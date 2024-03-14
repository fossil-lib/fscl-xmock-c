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
#include <stdarg.h>

// Define a buffer for storing printed output
#define MAX_OUTPUT_SIZE 100
static char printed_output[MAX_OUTPUT_SIZE];

// Mock function to capture printf output
int mock_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vsnprintf(printed_output, MAX_OUTPUT_SIZE, format, args);
    va_end(args);
    return 0; // Return value of printf doesn't matter for testing
}

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

// Test case for scanf mock
XTEST_CASE(test_xmock_io_scanf) {
    // Set mock printf function
    xmock_io_set_printf(mock_printf);
    // Capture console output
    xmock_io_capture_output();
    // Set up mock input
    char input[] = "42\n"; // Function pointer cannot be used here
    xmock_io_set_input(input);

    int num;
    xmock_io_scanf("%d", &num);

    TEST_ASSERT_EQUAL_INT(42, num);
    // Clear printed output buffer
    printed_output[0] = '\0';
    // Restore original console output
    xmock_io_restore_output();
}

// Test case for gets mock
XTEST_CASE(test_xmock_io_gets) {
    // Set mock printf function
    xmock_io_set_printf(mock_printf);
    // Capture console output
    xmock_io_capture_output();
    // Set up mock input
    char input[] = "Hello\n"; // Function pointer cannot be used here
    xmock_io_set_input(input);

    char buffer[100];
    xmock_io_gets(buffer);

    TEST_ASSERT_EQUAL_STRING("Hello", buffer);
    // Clear printed output buffer
    printed_output[0] = '\0';
    // Restore original console output
    xmock_io_restore_output();
}

// Test case for fgets mock
XTEST_CASE(test_xmock_io_fgets) {
    // Set mock printf function
    xmock_io_set_printf(mock_printf);
    // Capture console output
    xmock_io_capture_output();
    // Set up mock input
    char input[] = "Testing fgets\n"; // Function pointer cannot be used here
    xmock_io_set_input(input);

    char buffer[100];
    xmock_io_fgets(buffer, 100, stdin);

    TEST_ASSERT_EQUAL_STRING("Testing fgets\n", buffer);
    // Clear printed output buffer
    printed_output[0] = '\0';
    // Restore original console output
    xmock_io_restore_output();
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(xmock_output_group) {
    XTEST_RUN_UNIT(test_xmock_io_capture_and_restore_output);
    XTEST_RUN_UNIT(test_xmock_io_scanf);
    XTEST_RUN_UNIT(test_xmock_io_gets);
    XTEST_RUN_UNIT(test_xmock_io_fgets);
} // end of fixture
