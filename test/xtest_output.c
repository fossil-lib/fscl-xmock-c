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

#include <trilobite/xmock/output.h> // library under test
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
void xmock_output_group(XUnitRunner *runner) {
    XTEST_RUN_UNIT(test_xmock_io_capture_and_restore_output, runner);
} // end of fixture
