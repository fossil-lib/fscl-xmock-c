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

#include <trilobite/xmock.h> // library under test

XMOCK_FUNC_DEF(int, mock_function, int);
XMOCK_TYPE_ALIAS(MyAlias, int);
XMOCK_STRUCT_DEF(MyStruct, int member);


// Test for XMOCK_FUNC_DEF macro
XTEST_CASE(test_xmock_func_def) {
    // Act
    int result = xmock_mock_function(42);

    // Assert
    TEST_ASSERT_EQUAL_INT(0, result);  // Modify this assertion based on your mock function behavior
}

// Test for XMOCK_TYPE_ALIAS macro
XTEST_CASE(test_xmock_type_alias) {
    // Act
    MyAlias aliasResult = xmock_MyAlias();

    // Assert
    TEST_ASSERT_EQUAL_INT(0, aliasResult);  // Modify this assertion based on your alias behavior
}

// Test for XMOCK_STRUCT_DEF macro
XTEST_CASE(test_xmock_struct_def) {
    // Act
    MyStruct myStruct;
    myStruct.member = 42;

    // Assert
    TEST_ASSERT_EQUAL_INT(42, myStruct.member);  // Modify this assertion based on your struct behavior
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
void xmock_basic_group(XUnitRunner *runner) {
    XTEST_RUN_UNIT(test_xmock_func_def,   runner);
    XTEST_RUN_UNIT(test_xmock_type_alias, runner);
    XTEST_RUN_UNIT(test_xmock_struct_def, runner);
} // end of fixture
