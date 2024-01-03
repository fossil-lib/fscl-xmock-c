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

#include <fossil/xmock/behavior.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

// Test for xmock_behavior_create
XTEST_CASE(xmock_behavior_create_object) {
    XMockBehavior* behavior = xmock_behavior_create();
    TEST_ASSERT_NOT_CNULLPTR(behavior);
    xmock_behavior_erase(behavior);
}

// Test for xmock_behavior_expect_call_count and xmock_behavior_verify
XTEST_CASE(xmock_behavior_expect_and_verify) {
    XMockBehavior* behavior = xmock_behavior_create();

    // Set the expected call count
    int expectedCalls = 3;
    xmock_behavior_expect_call_count(behavior, expectedCalls);

    // Record calls and verify behavior
    for (int i = 0; i < expectedCalls; i++) {
        xmock_behavior_record_call(behavior);
    }

    // Verify that the expected calls match the actual calls
    xmock_behavior_verify(behavior);

    xmock_behavior_erase(behavior);
}

// Test for xmock_behavior_expect_call_count with incorrect number of calls
XTEST_CASE(xmock_behavior_expect_call_count_mismatch) {
    XMockBehavior* behavior = xmock_behavior_create();

    // Set the expected call count
    int expectedCalls = 3;
    xmock_behavior_expect_call_count(behavior, expectedCalls);

    // Record fewer calls than expected
    for (int i = 0; i < expectedCalls - 1; i++) {
        xmock_behavior_record_call(behavior);
    }

    xmock_behavior_erase(behavior);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(xmock_behav_group) {
    XTEST_RUN_UNIT(xmock_behavior_create_object);
    XTEST_RUN_UNIT(xmock_behavior_expect_and_verify);
    XTEST_RUN_UNIT(xmock_behavior_expect_call_count_mismatch);
} // end of fixture
