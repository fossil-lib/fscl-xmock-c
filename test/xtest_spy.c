/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

#include <fossil/xmock/spy.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

// Test case for xmock_spy_create
XTEST_CASE(test_xmock_spy_create) {
    XMockSpy* spy = xmock_spy_create();
    TEST_ASSERT_NOT_CNULLPTR(spy);
    xmock_spy_erase(spy); // Cleanup
}

// Test case for xmock_spy_record_call and xmock_spy_get_call_count
XTEST_CASE(test_xmock_spy_record_and_get_call_count) {
    XMockSpy* spy = xmock_spy_create();
    TEST_ASSERT_NOT_CNULLPTR(spy);

    // Record calls and verify call count
    xmock_spy_record_call(spy);
    xmock_spy_record_call(spy);
    TEST_ASSERT_EQUAL_INT(2, xmock_spy_get_call_count(spy));

    xmock_spy_erase(spy); // Cleanup
}

// Test case for xmock_spy_erase
XTEST_CASE(test_xmock_spy_erase) {
    XMockSpy* spy = xmock_spy_create();
    TEST_ASSERT_NOT_CNULLPTR(spy);

    xmock_spy_erase(spy);

    // Ensure that spy is destroyed (double destruction should not crash)
    TEST_ASSERT_CNULLPTR(spy);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(xmock_spies_group) {
    XTEST_RUN_UNIT(test_xmock_spy_create);
    XTEST_RUN_UNIT(test_xmock_spy_record_and_get_call_count);
    XTEST_RUN_UNIT(test_xmock_spy_erase);
} // end of fixture
