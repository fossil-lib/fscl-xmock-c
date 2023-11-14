/*  ----------------------------------------------------------------------------
    File: demo.c

    Description:
    This demo file serves as a showcase of the Trilobite Stdlib in action. It provides
    example code snippets and usage scenarios to help users understand how to leverage
    the library's features and functions in their own projects.

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
#include <trilobite/xmock/inject.h>
#include <stdio.h>

int main() {
    // Create a mock instance of XMockDependency
    XMockDependency* mockDependency = xmock_inject_create_dependency_mock();

    // Set properties for the mocked dependency
    xmock_inject_set_dependency_properties_mock(mockDependency, 5);

    // Create a mock instance of XMockSystem with the mocked dependency
    XMockSystem* mockSystem = xmock_inject_create_system_mock(mockDependency);

    // Perform a mock operation using the mocked dependency
    int result = xmock_inject_perform_operation_mock(mockSystem);
    printf("Mock Operation Result: %d\n", result);

    // Destroy the mock system and the mocked dependency
    xmock_inject_destroy_system_mock(mockSystem);
    xmock_inject_destroy_dependency_mock(mockDependency);

    return 0;
} // end of func
