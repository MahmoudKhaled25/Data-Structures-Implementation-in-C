//
// Created by Blu-ray on 8/19/2023.
//

#ifndef DYNAMIC_STACK_STACK_H
#define DYNAMIC_STACK_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "platform_types.h"

#define PTR_FOR_EMPTY (-1)

typedef struct stack
{
    void **dataInHeap;
    s32int topPointer;
    u32int maxSize;
}stack_t;

typedef enum stackStatus
{
    STACK_NOK = 0,
    STACK_OK,
    STACK_FULL,
    STACK_EMPTY,
    STACK_NULL_PTR
}stackStatus_t;

/**
 * @brief This function creates a new stack with the specified size.
 * @param stackSize The maximum size of the stack.
 * @param retVal A pointer to a stackStatus_t variable to store the return status of the function.
 * @return stack_t* (Pointer to the newly created stack)
 */
stack_t *stackCreate(u32int stackSize, stackStatus_t *retVal);

/**
 * @brief This function destroys the given stack and frees the associated memory.
 * @param stack Pointer to the stack to be destroyed.
 * @param retVal pointer to a stackStatus_t variable to store the return status of the function.
 * @return stack_t* (Pointer to the destroyed stack, which is set to NULL)
 */
stack_t *stackDestroy(stack_t *stack, stackStatus_t *retVal);

/**
 * @brief This function pushes an item onto the stack.
 * @param stack Pointer to the stack.
 * @param itemPtr Pointer to the item to be pushed onto the stack.
 * @return stackStatus_t (Return status indicating the success or failure of the operation)
 */
stackStatus_t stackPush (stack_t *stack, void *itemPtr);

/**
 * @brief This function pops an item from the top of the stack.
 * @param stack Pointer to the stack.
 * @param retVal A pointer to a stackStatus_t variable to store the return status of the function.
 * @return void* (Pointer to the popped item from the stack)

 */
void *stackPop (stack_t *stack, stackStatus_t *retVal);

/**
 * @brief This function retrieves the item at the top of the stack without removing it.
 * @param stack Pointer to the stack.
 * @param retVal A pointer to a stackStatus_t variable to store the return status of the function.
 * @return void* (Pointer to the item at the top of the stack)
 */
void *stackTop (stack_t *stack, stackStatus_t *retVal);

/**
 * @brief This function returns the current size (number of elements) of the stack.
 * @param stack Pointer to the stack.
 * @param retVal A pointer to a stackStatus_t variable to store the return status of the function.
 * @return s32int (Current size of the stack) (returns -1 if NULL passed into retVal)
 */
s32int stackSize (stack_t *stack, stackStatus_t *retVal);

/**
 * @brief This function displays the contents of the stack.
 * @param stack Pointer to the stack.
 * @return stackStatus_t (Return status indicating the success or failure of the operation)
 */
stackStatus_t stackDisplay (stack_t *stack);

#endif //DYNAMIC_STACK_STACK_H
