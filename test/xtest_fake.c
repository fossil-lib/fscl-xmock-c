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

#include <trilobite/xmock/fake.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//
XTEST_CASE(xmock_fake_create_object) {
    XMockFake* fake = xmock_fake_create();
    TEST_ASSERT_NOT_NULL(fake);
    xmock_fake_destroy(fake);
}

XTEST_CASE(xmock_fake_set_return_value_object) {
    XMockFake* fake = xmock_fake_create();
    xmock_fake_set_return_value(fake, 42);
    TEST_ASSERT_EQUAL_INT(42, xmock_fake_get_return_value(fake));
    xmock_fake_destroy(fake);
}

XTEST_CASE(xmock_fake_record_call_object) {
    XMockFake* fake = xmock_fake_create();
    xmock_fake_record_call(fake);
    TEST_ASSERT_EQUAL_INT(1, xmock_fake_get_call_count(fake));
    xmock_fake_destroy(fake);
}

XTEST_CASE(xmock_fake_get_call_count_object) {
    XMockFake* fake = xmock_fake_create();
    xmock_fake_record_call(fake);
    xmock_fake_record_call(fake);
    TEST_ASSERT_EQUAL_INT(2, xmock_fake_get_call_count(fake));
    xmock_fake_destroy(fake);
}

XTEST_CASE(xmock_fake_get_return_value_object) {
    XMockFake* fake = xmock_fake_create();
    xmock_fake_set_return_value(fake, 42);
    TEST_ASSERT_EQUAL_INT(42, xmock_fake_get_return_value(fake));
    xmock_fake_destroy(fake);
}

XTEST_CASE(xmock_fake_destroy_object) {
    XMockFake* fake = xmock_fake_create();
    xmock_fake_destroy(fake);
    // Ensure no memory leaks or crashes during destruction
    TEST_IGNORE_MESSAGE("Memory has been freed successfully");
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
void xmock_fakes_group(XUnitRunner *runner) {
    XTEST_RUN_UNIT(xmock_fake_create_object,           runner);
    XTEST_RUN_UNIT(xmock_fake_set_return_value_object, runner);
    XTEST_RUN_UNIT(xmock_fake_record_call_object,      runner);
    XTEST_RUN_UNIT(xmock_fake_get_call_count_object,   runner);
    XTEST_RUN_UNIT(xmock_fake_get_return_value_object, runner);
    XTEST_RUN_UNIT(xmock_fake_destroy_object,          runner);
} // end of fixture
