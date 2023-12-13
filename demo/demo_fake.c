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
#include <trilobite/xmock/fake.h>
#include <stdio.h>

int main() {
    // Create a mock instance of XMockFake
    XMockFake* mockFake = xmock_fake_create();

    // Set a predefined return value for the mock fake
    xmock_fake_set_return_value(mockFake, 42);

    // Record some calls in the mock fake
    xmock_fake_record_call(mockFake);
    xmock_fake_record_call(mockFake);
    xmock_fake_record_call(mockFake);

    // Get and print the call count and return value from the mock fake
    int callCount = xmock_fake_get_call_count(mockFake);
    int returnValue = xmock_fake_get_return_value(mockFake);
    printf("Number of Calls Recorded: %d\n", callCount);
    printf("Predefined Return Value: %d\n", returnValue);

    // Destroy the mock fake
    xmock_fake_erase(mockFake);

    return 0;
} // end of func
