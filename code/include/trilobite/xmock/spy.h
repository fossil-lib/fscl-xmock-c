/*
   This C header file is part of the Trilobite Stdlib, a collection of utility functions and
   standard data structures for enhancing software development projects. Feel free to use
   and modify these utilities to streamline your software development process.

   Project: Trilobite Stdlib
   Author: Michael Gene Brockus (Dreamer)
   Email: michaelbrockus@gmail.com
   Website: [Trilobite Coder Blog](https://trilobite.code.blog)

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
#ifndef TRILOBITE_XMOCK_SPY_H
#define TRILOBITE_XMOCK_SPY_H

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

// Structure to store information about function calls
typedef struct {
    int callCount;
} XMockSpy;

/**
 * @brief Creates a new instance of XMockSpy.
 *
 * This function allocates memory for a new XMockSpy and initializes its fields.
 *
 * @return A pointer to the newly created XMockSpy instance.
 */
XMockSpy* xmock_spy_create(void);

/**
 * @brief Records a call in the XMockSpy.
 *
 * This function is used to record the occurrence of a function call in the spy.
 * It increments the call count of the spy, providing a way to track the number of calls.
 *
 * @param spy A pointer to the XMockSpy in which to record a call.
 */
void xmock_spy_record_call(XMockSpy* spy);

/**
 * @brief Gets the call count from the XMockSpy.
 *
 * This function retrieves the total number of recorded calls in the XMockSpy.
 *
 * @param spy A pointer to the XMockSpy from which to retrieve the call count.
 * @return The number of calls recorded in the XMockSpy.
 */
int xmock_spy_get_call_count(XMockSpy* spy);

/**
 * @brief Destroys an instance of XMockSpy.
 *
 * This function frees the memory allocated for the XMockSpy instance.
 *
 * @param spy A pointer to the XMockSpy instance to destroy.
 */
void xmock_spy_destroy(XMockSpy* spy);

#ifdef __cplusplus
}
#endif

#endif