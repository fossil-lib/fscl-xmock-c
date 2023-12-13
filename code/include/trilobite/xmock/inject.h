/*
   This C header file is part of the Trilobite Stdlib, a collection of utility functions and
   standard data structures for enhancing software development projects. Feel free to use
   and modify these utilities to streamline your software development process.

   Project: Trilobite Stdlib
   Author: Michael Gene Brockus (Dreamer)
   Email: michaelbrockus@gmail.com
   Website: [Trilobite Coder Blog](https://trilobite.home.blog)

   Trilobite Stdlib is designed to provide a robust set of functionalities that can be
   incorporated into various projects. The utilities included in this library aim to optimize
   and standardize common operations, ensuring efficient and reliable code.

   This header file is a part of a broader initiative to support developers in creating secure,
   efficient, and scalable software. Contributions, suggestions, and feedback are welcomed,
   as we strive to continuously improve and expand the capabilities of Trilobite Stdlib.

   License: Apache License 2.0
   SPDX Identifier: Apache-2.0

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software distributed under the License
   is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
   or implied. See the License for the specific language governing permissions and limitations
   under the License.

   The above copyright notice and this permission notice shall be included in all copies or
   substantial portions of the Software.

   Please review the full text of the Apache License 2.0 for the complete terms and conditions.

   (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
*/
#ifndef TRILOBITE_XMOCK_INJECT_H
#define TRILOBITE_XMOCK_INJECT_H

#ifdef __cplusplus
#include <cstdlib>
#include <cstdio>
#else
#include <stdlib.h>
#include <stdio.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

// Structure to represent a dependency
typedef struct {
    // Fields representing the dependency's properties
    int dependencyValue;
} XMockDependency;

// Structure to represent the system under test
typedef struct {
    // Dependency injected into the system
    XMockDependency* dependency;
} XMockSystem;

/**
 * @brief Creates a new instance of XMockDependency.
 *
 * This function allocates memory for a new XMockDependency and initializes its fields.
 *
 * @return A pointer to the newly created XMockDependency instance.
 */
XMockDependency* xmock_inject_create_dependency(void);

/**
 * @brief Sets properties for the injected dependency.
 *
 * This function allows you to set properties, such as values, for the given XMockDependency.
 *
 * @param dependency  A pointer to the XMockDependency for which to set properties.
 * @param value       The value to set for the dependency.
 */
void xmock_inject_set_dependency_properties(XMockDependency* dependency, int value);

/**
 * @brief Destroys an instance of XMockDependency.
 *
 * This function frees the memory allocated for the XMockDependency instance.
 *
 * @param dependency  A pointer to the XMockDependency instance to destroy.
 */
void xmock_inject_erase_dependency(XMockDependency* dependency);

/**
 * @brief Creates a new instance of XMockSystem with the injected dependency.
 *
 * This function creates a new instance of XMockSystem and injects the provided dependency into it.
 *
 * @param injectedDependency  A pointer to the XMockDependency to inject into the system.
 * @return A pointer to the newly created XMockSystem instance.
 */
XMockSystem* xmock_inject_create_system(XMockDependency* injectedDependency);

/**
 * @brief Performs an operation using the injected dependency.
 *
 * This function performs an operation using the injected dependency within the given XMockSystem.
 *
 * @param system  A pointer to the XMockSystem containing the injected dependency.
 * @return The result of the operation.
 */
int xmock_inject_perform_operation(XMockSystem* system);

/**
 * @brief Destroys an instance of XMockSystem.
 *
 * This function frees the memory allocated for the XMockSystem instance.
 *
 * @param system  A pointer to the XMockSystem instance to destroy.
 */
void xmock_inject_erase_system(XMockSystem* system);

#ifdef __cplusplus
}
#endif

#endif