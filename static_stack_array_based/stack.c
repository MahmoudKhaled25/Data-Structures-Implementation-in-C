//
// Created by Blu-ray on 8/15/2023.
//
/**
 ******************************************************************
 * @file              :   main.c
 * @author            :   Mahmoud Khaled
 * @brief             :   This file contains stack data structure implementation
 ******************************************************************
 */

#include "stack.h"
#define CALC_STACK_SIZE(STACK_PTR) ((STACK_PTR) + 1)

/***************************** Helper Functions *****************************/
static unsigned int stackFull (const stack_t *);
static unsigned int stackEmpty (const stack_t *);

static unsigned int stackFull (const stack_t *stack)
{
    return ((STACK_MAX_SIZE - 1) == stack->stack_pointer);
}

static unsigned int stackEmpty (const stack_t *stack)
{
    return (STACK_EMPTY == stack->stack_pointer);
}
/****************************************************************************/

returnState_t pushBack (stack_t *stack, u32int data)
{
    returnState_t retVal = FALSE;

    if (NULL != stack)
    {
        if(!stackFull(stack))
        {
            stack->data[++(stack->stack_pointer)] = data;
            retVal = TRUE;
        }
        else
        {
            retVal = FALSE;
        }
    } else { }

    return retVal;
}

retStruct_t popBack(stack_t *stack)
{
    retStruct_t retStruct;
    retStruct.state = FALSE;

    if (NULL != stack)
    {
        if (!stackEmpty(stack))
        {
            retStruct.retValue = (s32int)stack->data[(stack->stack_pointer)--];
            retStruct.state = TRUE;
        }
        else
        {
            retStruct.state = FALSE;
        }
    } else { }

    return retStruct;
}

retStruct_t stackTop(const stack_t *stack)
{
    retStruct_t retStruct;
    retStruct.state = FALSE;

    if (NULL != stack)
    {
        if(!stackEmpty(stack))
        {
            retStruct.retValue = (s32int)stack->data[(stack->stack_pointer)];
            retStruct.state = TRUE;
        }
        else
        {
            retStruct.state = FALSE;
        }
    }
    else { }

    return retStruct;
}

returnState_t stackInit(stack_t *stack)
{
    returnState_t retVal = FALSE;
    u32int counter;

    if((NULL != stack))
    {
        stack->stack_pointer = STACK_EMPTY;

        for (counter = 0; counter < STACK_MAX_SIZE; ++counter)
            stack->data[counter] = 0;

        retVal = TRUE;
    }
    else {}

    return retVal;
}

retStruct_t stackSize(const stack_t *stack)
{
    retStruct_t retStruct;
    retStruct.state = FALSE;

    if (NULL != stack)
    {
        retStruct.retValue = CALC_STACK_SIZE(stack->stack_pointer);
        retStruct.state = TRUE;
    }
    return retStruct;
}

void stackDisplay(const stack_t *stack)
{
    s32int counter;

    if (NULL == stack )
    {
        printf("Stack pointer is pointing to NULL!\n");
    }
    else if (stack->stack_pointer == STACK_EMPTY)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack Elements: ");
        for (counter = stack->stack_pointer; counter >= 0; counter--)
        {
            printf("%u\t", stack->data[counter]);
        }
        printf("\n");
    }
}

