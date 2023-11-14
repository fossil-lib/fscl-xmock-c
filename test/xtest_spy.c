/*  ----------------------------------------------------------------------------
    File: xunit_runner.c

    Description:
    This test file contains unit tests for the various functions and utilities provided
    by the Trilobite Stdlib. These tests ensure the correctness and reliability of the
    library's components and demonstrate their intended usage.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.code.blog)

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

#include <trilobite/xmock/spy.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

// Test case for xmock_spy_create
XTEST_CASE(test_xmock_spy_create) {
    XMockSpy* spy = xmock_spy_create();
    TEST_ASSERT_NOT_NULL_PTR(spy);
    xmock_spy_destroy(spy); // Cleanup
}

// Test case for xmock_spy_record_call and xmock_spy_get_call_count
XTEST_CASE(test_xmock_spy_record_and_get_call_count) {
    XMockSpy* spy = xmock_spy_create();
    TEST_ASSERT_NOT_NULL_PTR(spy);

    // Record calls and verify call count
    xmock_spy_record_call(spy);
    xmock_spy_record_call(spy);
    TEST_ASSERT_EQUAL_INT(2, xmock_spy_get_call_count(spy));

    xmock_spy_destroy(spy); // Cleanup
}

// Test case for xmock_spy_destroy
XTEST_CASE(test_xmock_spy_destroy) {
    XMockSpy* spy = xmock_spy_create();
    TEST_ASSERT_NOT_NULL(spy);

    xmock_spy_destroy(spy);

    // Ensure that spy is destroyed (double destruction should not crash)
    TEST_ASSERT_NULL(spy);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
void xmock_spies_group(XUnitRunner *runner) {
    XTEST_RUN_UNIT(test_xmock_spy_create,                    runner);
    XTEST_RUN_UNIT(test_xmock_spy_record_and_get_call_count, runner);
    XTEST_RUN_UNIT(test_xmock_spy_destroy,                   runner);
} // end of fixture
