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

#include <trilobite/xmock/inject.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//
XTEST_CASE(test_xmock_inject_create_dependency) {
    // Arrange
    XMockDependency* dependency;

    // Act
    dependency = xmock_inject_create_dependency();

    // Assert
    TEST_ASSERT_NOT_NULL_PTR(dependency);

    // Clean up
    xmock_inject_destroy_dependency(dependency);
}

XTEST_CASE(test_xmock_inject_set_dependency_properties) {
    // Arrange
    XMockDependency* dependency = xmock_inject_create_dependency();
    int expectedValue = 42;

    // Act
    xmock_inject_set_dependency_properties(dependency, expectedValue);

    // Assert
    TEST_ASSERT_EQUAL_INT(expectedValue, dependency->dependencyValue);

    // Clean up
    xmock_inject_destroy_dependency(dependency);
}

XTEST_CASE(test_xmock_inject_create_system_and_perform_operation) {
    // Arrange
    XMockDependency* dependency = xmock_inject_create_dependency();
    XMockSystem* system;
    int expectedResult = 84;

    // Act
    system = xmock_inject_create_system(dependency);
    int result = xmock_inject_perform_operation(system);

    // Assert
    TEST_ASSERT_EQUAL_INT(expectedResult, result);

    // Clean up
    xmock_inject_destroy_system(system);
    xmock_inject_destroy_dependency(dependency);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
void basic_group(XUnitRunner *runner) {
    XTEST_RUN_UNIT(test_xmock_inject_create_dependency,                   runner);
    XTEST_RUN_UNIT(test_xmock_inject_set_dependency_properties,           runner);
    XTEST_RUN_UNIT(test_xmock_inject_create_system_and_perform_operation, runner);
} // end of fixture
