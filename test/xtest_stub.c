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

#include <fossil/xmock/stub.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

// Test case for xmock_stub_create function
XTEST_CASE(test_xmock_stub_create) {
    XMockStub* stub = xmock_stub_create();

    // Verify that the created stub is not NULL
    TEST_ASSERT_NOT_CNULLPTR(stub);

    // Clean up
    xmock_stub_erase(stub);
}

// Test case for xmock_stub_set_response and xmock_stub_get_response functions
XTEST_CASE(test_xmock_stub_set_get_response) {
    XMockStub* stub = xmock_stub_create();

    // Set a predefined response
    xmock_stub_set_response(stub, 42);

    // Get and verify the predefined response
    int response = xmock_stub_get_response(stub);
    TEST_ASSERT_EQUAL_INT(42, response);

    // Clean up
    xmock_stub_erase(stub);
}

// Test case for xmock_stub_erase function
XTEST_CASE(test_xmock_stub_erase) {
    XMockStub* stub = xmock_stub_create();

    // Verify that the created stub is not NULL before destruction
    TEST_ASSERT_NOT_CNULLPTR(stub);

    // Destroy the stub
    xmock_stub_erase(stub);

    // Verify that the stub is NULL after destruction
    TEST_ASSERT_CNULLPTR(stub);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(xmock_stubs_group) {
    XTEST_RUN_UNIT(test_xmock_stub_create,           runner);
    XTEST_RUN_UNIT(test_xmock_stub_set_get_response, runner);
    XTEST_RUN_UNIT(test_xmock_stub_erase,          runner);
} // end of fixture
