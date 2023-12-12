/*  ----------------------------------------------------------------------------
    File: xunit_runner.c

    Description:
    This test file contains unit tests for the various functions and utilities provided
    by the Trilobite Stdlib. These tests ensure the correctness and reliability of the
    library's components and demonstrate their intended usage.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.home.blog)

    Project: Trilobite Stdlib

    License: Apache License 2.0
    SPDX Identifier: Apache-2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.

    Unless required by applicable law or agreed to in writing, software distributed under the License
    is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing permissions and limitations
    under the License.

    Please review the full text of the Apache License 2.0 for the complete terms and conditions.

    (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
    ----------------------------------------------------------------------------
*/
#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

#include <trilobite/xmock/behavior.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

// Test for xmock_behavior_create
XTEST_CASE(xmock_behavior_create_object) {
    XMockBehavior* behavior = xmock_behavior_create();
    TEST_ASSERT_NOT_NULL_PTR(behavior);
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
XTEST_GROUP_DEFINE(xmock_behav_group) {
    XTEST_RUN_UNIT(xmock_behavior_create_object, runner);
    XTEST_RUN_UNIT(xmock_behavior_expect_and_verify, runner);
    XTEST_RUN_UNIT(xmock_behavior_expect_call_count_mismatch, runner);
} // end of fixture
