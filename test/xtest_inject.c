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

#include <fossil/xmock/inject.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//
XTEST_CASE(test_xmock_inject_create_dependency) {
    // Arrange
    XMockDependency* dependency;

    // Act
    dependency = xmock_inject_create_dependency();

    // Assert
    TEST_ASSERT_NOT_CNULLPTR(dependency);

    // Clean up
    xmock_inject_erase_dependency(dependency);
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
    xmock_inject_erase_dependency(dependency);
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
    xmock_inject_erase_system(system);
    xmock_inject_erase_dependency(dependency);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(xmock_inject_group) {
    XTEST_RUN_UNIT(test_xmock_inject_create_dependency,                   runner);
    XTEST_RUN_UNIT(test_xmock_inject_set_dependency_properties,           runner);
    XTEST_RUN_UNIT(test_xmock_inject_create_system_and_perform_operation, runner);
} // end of fixture
