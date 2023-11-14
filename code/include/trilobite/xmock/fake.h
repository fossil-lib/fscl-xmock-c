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
#ifndef TRILOBITE_XMOCK_FAKE_H
#define TRILOBITE_XMOCK_FAKE_H

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

// Structure to store information about fake function calls
typedef struct {
    int callCount;
    int returnValue;
} XMockFake;

/**
 * @brief Creates a new instance of XMockFake.
 *
 * This function allocates memory for a new XMockFake and initializes its fields.
 *
 * @return A pointer to the newly created XMockFake instance.
 */
XMockFake* xmock_fake_create(void);

/**
 * @brief Sets the return value for the fake function.
 *
 * This function allows you to specify the return value that the fake function should provide.
 *
 * @param fake   A pointer to the XMockFake for which to set the return value.
 * @param value  The return value to set for the fake function.
 */
void xmock_fake_set_return_value(XMockFake* fake, int value);

/**
 * @brief Records a call in the XMockFake.
 *
 * This function is used to record the occurrence of a function call in the fake.
 * It increments the call count of the fake, providing a way to track the number of calls.
 *
 * @param fake A pointer to the XMockFake in which to record a call.
 */
void xmock_fake_record_call(XMockFake* fake);

/**
 * @brief Gets the call count from the XMockFake.
 *
 * This function retrieves the total number of recorded calls in the XMockFake.
 *
 * @param fake A pointer to the XMockFake from which to retrieve the call count.
 * @return The number of calls recorded in the XMockFake.
 */
int xmock_fake_get_call_count(XMockFake* fake);

/**
 * @brief Gets the return value of the fake function.
 *
 * This function retrieves the return value that was set for the fake function.
 *
 * @param fake A pointer to the XMockFake from which to retrieve the return value.
 * @return The return value set for the fake function.
 */
int xmock_fake_get_return_value(XMockFake* fake);

/**
 * @brief Destroys an instance of XMockFake.
 *
 * This function frees the memory allocated for the XMockFake instance.
 *
 * @param fake A pointer to the XMockFake instance to destroy.
 */
void xmock_fake_destroy(XMockFake* fake);

#ifdef __cplusplus
}
#endif

#endif