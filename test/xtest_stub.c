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

#include <trilobite/xmock/stub.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

// Test case for xmock_stub_create function
XTEST_CASE(test_xmock_stub_create) {
    XMockStub* stub = xmock_stub_create();

    // Verify that the created stub is not NULL
    TEST_ASSERT_NOT_NULL_PTR(stub);

    // Clean up
    xmock_stub_destroy(stub);
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
    xmock_stub_destroy(stub);
}

// Test case for xmock_stub_destroy function
XTEST_CASE(test_xmock_stub_destroy) {
    XMockStub* stub = xmock_stub_create();

    // Verify that the created stub is not NULL before destruction
    TEST_ASSERT_NOT_NULL_PTR(stub);

    // Destroy the stub
    xmock_stub_destroy(stub);

    // Verify that the stub is NULL after destruction
    TEST_ASSERT_NULL_PTR(stub);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
void xmock_stubs_group(XUnitRunner *runner) {
    XTEST_RUN_UNIT(test_xmock_stub_create,           runner);
    XTEST_RUN_UNIT(test_xmock_stub_set_get_response, runner);
    XTEST_RUN_UNIT(test_xmock_stub_destroy,          runner);
} // end of fixture
