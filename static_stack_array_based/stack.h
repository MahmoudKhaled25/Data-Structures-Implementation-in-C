/**
 ******************************************************************
 * @file              :   stack.h
 * @brief             :   This file contains stack data structure declarations
 * @author            :   Mahmoud Khaled
 * @date              :   8/15/2023
 ******************************************************************
 */

#ifndef STACK_IMPLEMENTATION_STACK_H
#define STACK_IMPLEMENTATION_STACK_H

#include <stdio.h>
#include "platform_types.h"

#define STACK_MAX_SIZE 6
#define STACK_EMPTY (-1)

typedef struct Stack
{
    u32int data[STACK_MAX_SIZE];
    s32int stack_pointer;
} stack_t;

typedef struct retStruct
{
    returnState_t state;
    u32int retValue;
} retStruct_t;

/**
 * @brief Pushes an element onto the stack.
 *
 * This function pushes an element onto the stack.
 *
 * @param stack A pointer to the stack.
 * @param data The data to be pushed onto the stack.
 * @return returnState_t Returns STACK_OK if the push operation is successful, STACK_FULL otherwise.
 */
returnState_t pushBack(stack_t *stack, u32int data);

/**
 * @brief Pops an element from the stack.
 *
 * This function pops an element from the stack.
 *
 * @param stack A pointer to the stack.
 * @return retStruct_t Returns a structure containing the status of the pop operation and the popped value.
 */
retStruct_t popBack(stack_t *stack);

/**
 * @brief Retrieves the element at the top of the stack without removing it.
 *
 * This function retrieves the element at the top of the stack without removing it.
 *
 * @param stack A pointer to the stack.
 * @return retStruct_t Returns a structure containing the status of the operation and the top element's value.
 */
retStruct_t stackTop(const stack_t *stack);

/**
 * @brief Initializes the stack.
 *
 * This function initializes the stack by resetting the stack pointer.
 *
 * @param stack A pointer to the stack.
 * @return returnState_t Returns STACK_OK if the initialization is successful.
 */
returnState_t stackInit(stack_t *stack);

/**
 * @brief Retrieves the current size of the stack.
 *
 * This function retrieves the current size (number of elements) of the stack.
 *
 * @param stack A pointer to the stack.
 * @return retStruct_t Returns a structure containing the status of the operation and the stack size.
 */
retStruct_t stackSize(const stack_t *stack);

/**
 * @brief Displays the contents of the stack.
 *
 * This function displays the contents of the stack.
 *
 * @param stack A pointer to the stack.
 */
void stackDisplay(const stack_t *stack);

#endif //STACK_IMPLEMENTATION_STACK_H
