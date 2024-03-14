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

#include <fossil/xmock/output.h> // library under test
#include <stdio.h>

//
// XUNIT-CASES: list of test cases testing project features
//
XTEST_CASE(test_xmock_io_capture_and_restore_output) {
    // Arrange
    xmock_io_setup();
    xmock_io_capture_output();

    // Act
    printf("Test Output");

    // Assert
    const char* captured_output = xmock_io_get_output();
    TEST_ASSERT_EQUAL_STRING("Test Output", captured_output);

    // Restore and teardown
    xmock_io_restore_output();
    xmock_io_teardown();
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(xmock_output_group) {
    XTEST_RUN_UNIT(test_xmock_io_capture_and_restore_output);
} // end of fixture
