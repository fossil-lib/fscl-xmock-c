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
#ifndef TRILOBITE_XMOCK_H
#define TRILOBITE_XMOCK_H

#ifdef __cplusplus
#include <cstddef>
#else
#include <stddef.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

// xmock/spy.h - Header for Spy Mocking in xmock library
// This header includes definitions and functions related to Spy mocking in the xmock library.
// It provides facilities for creating, recording, and verifying function calls using spies.
#include "xmock/spy.h"

// xmock/fake.h - Header for Fake Functions in xmock library
// This header includes definitions and functions related to Fake Functions in the xmock library.
// It allows users to create fake functions, set their return values, record calls, and perform verification.
#include "xmock/fake.h"

// xmock/behavior.h - Header for Behavior Verification in xmock library
// This header includes definitions and functions related to Behavior Verification in the xmock library.
// It provides facilities for creating behavior verification instances, setting expectations, recording calls,
// and verifying that the actual calls match the expected calls.
#include "xmock/behavior.h"

// xmock/inject.h - Header for Dependency Injection in xmock library
// This header includes definitions and functions related to Dependency Injection in the xmock library.
// It offers functionality for creating and managing dependencies, injecting dependencies into systems,
// and performing operations using the injected dependencies.
#include "xmock/inject.h"

// xmock/stub.h - Header for Stubs in xmock library
// This header includes definitions and functions related to Stubs in the xmock library.
// It provides facilities for creating stubs, setting predefined responses, getting responses, and destroying stubs.
#include "xmock/stub.h"

//
// XMock function declarations
//

/**
 * @def XMOCK_FUNC_DEF
 * @brief Macro for creating a mock function with the specified return type, name, and parameters.
 *
 * This macro simplifies the creation of mock functions by defining a function with the given return
 * type, name, and parameters. The function name will be prefixed with "xmock_" to clearly indicate
 * that it is a mock function.
 *
 * @param return_type   The return type of the mock function.
 * @param name          The name of the mock function.
 * @param ...           The parameters of the mock function in the format: (type1 param1, type2 param2, ...).
 * @return The return type specified for the mock function.
 */
#define XMOCK_FUNC_DEF(return_type, name, ...) \
    return_type xmock_##name(__VA_ARGS__)

/**
 * @def XMOCK_TYPE_ALIAS
 * @brief Macro for creating a type alias based on an existing type.
 *
 * This macro creates a type alias for a given existing type.
 *
 * @param new_type       The name of the new type alias.
 * @param existing_type  The existing type to create an alias for.
 */
#define XMOCK_TYPE_ALIAS(new_type, existing_type) \
    typedef existing_type xmock_##new_type##_type; \
    xmock_##new_type##_type xmock_##new_type(void)

/**
 * @def XMOCK_STRUCT_DEF
 * @brief Macro for creating a mock struct with the specified name and members.
 *
 * This macro simplifies the creation of mock structs by defining a struct with the given name
 * and members. The struct name will be prefixed with "xmock_" to clearly indicate that it is a mock struct.
 *
 * @param name     The name of the mock struct.
 * @param ...      The members of the mock struct in the format: (type1 member1, type2 member2, ...).
 */
#define XMOCK_STRUCT_DEF(name, ...) \
    typedef struct { \
        __VA_ARGS__ \
    } xmock_##name;


#ifdef __cplusplus
}
#endif

#endif