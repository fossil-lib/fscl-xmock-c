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
#ifndef FSCL_XMOCK_H
#define FSCL_XMOCK_H

#ifdef __cplusplus
#include <cstddef>
#else
#include <stddef.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#include "xmock/spy.h"
#include "xmock/fake.h"
#include "xmock/behavior.h"
#include "xmock/inject.h"
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