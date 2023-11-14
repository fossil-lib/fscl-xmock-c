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

// Mock function for testing
XMOCK_FUNC_DEF(int, add, int a, int b) {
    return a + b;
}

// Type alias for testing
XMOCK_TYPE_ALIAS(MyInt, int);

// Mock struct for testing
XMOCK_STRUCT_DEF(Point, int x, int y);

//
// XUNIT-CASES: list of test cases testing project features
//
XTEST_CASE(test_mock_function) {
    // Arrange
    int expected_result = 5;

    // Act
    int result = xmock_add(2, 3);

    // Assert
    TEST_ASSERT_EQUAL_INT(expected_result, result);
}

XTEST_CASE(test_type_alias) {
    // Arrange
    int original_value = 42;

    // Act
    MyInt aliased_value = xmock_MyInt();

    // Assert
    TEST_ASSERT_EQUAL_INT(original_value, aliased_value);
}

XTEST_CASE(test_mock_struct) {
    // Arrange
    Point p = {1, 2};

    // Act
    xmock_Point mock_point = {3, 4};

    // Assert
    TEST_ASSERT_EQUAL_INT(p.x, mock_point.x);
    TEST_ASSERT_EQUAL_INT(p.y, mock_point.y);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
void basic_group(XUnitRunner *runner) {
    XTEST_RUN_UNIT(test_mock_function, runner);
    XTEST_RUN_UNIT(test_type_alias,    runner);
    XTEST_RUN_UNIT(test_mock_struct,   runner);
} // end of fixture
