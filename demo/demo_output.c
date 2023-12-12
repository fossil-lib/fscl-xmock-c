/*  ----------------------------------------------------------------------------
    File: demo.c

    Description:
    This demo file serves as a showcase of the Trilobite Stdlib in action. It provides
    example code snippets and usage scenarios to help users understand how to leverage
    the library's features and functions in their own projects.

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
#include <trilobite/xmock/output.h>
#include <stdio.h>

int main() {
    // Setup xmock_io
    xmock_io_setup();

    // Capture console output
    xmock_io_capture_output();

    // Your code that produces console output
    printf("Hello, World!\n");

    // Get the captured output
    const char* captured_output = xmock_io_get_output();

    // Restore original console output
    xmock_io_restore_output();

    // Teardown xmock_io
    xmock_io_teardown();

    // Print the captured output (or use it in your tests)
    printf("Captured Output: %s", captured_output);

    return 0;
} // end of func
