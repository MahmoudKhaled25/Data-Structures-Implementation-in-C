//
// Created by Blu-ray on 8/19/2023.
//

#include "stack.h"

#define CALC_STACK_SIZE(POINTER) ((POINTER) + 1)

static u8int stackFull(const stack_t *stack);
static u8int stackEmpty(const stack_t *stack);

static u8int stackFull(const stack_t *stack)
{
    return (CALC_STACK_SIZE(stack->topPointer) == stack->maxSize);
}

static u8int stackEmpty(const stack_t *stack)
{
    return (PTR_FOR_EMPTY == stack->topPointer);
}

stack_t *stackCreate (u32int stackSize, stackStatus_t *retVal)
{
    stack_t *stack = NULL;

    if (NULL != retVal)
    {
        stack = (stack_t *) malloc(sizeof(stack_t));

        if(!stack)
        {
            *retVal = STACK_NOK;
        }
        else
        {
            stack->dataInHeap = (void **) calloc(stackSize, sizeof(void *));
            if(!stack->dataInHeap)
            {
                free(stack);
                stack = NULL;
                *retVal = STACK_NOK;
            }
            else
            {
                stack->maxSize = stackSize;
                stack->topPointer = PTR_FOR_EMPTY;
                *retVal = STACK_OK;
            }
        }
    }
    else
    {
        *retVal = STACK_NOK;
    }

    return stack;
}

stack_t *stackDestroy(stack_t *stack, stackStatus_t *retVal)
{
    if (NULL == retVal || NULL == stack)
    {
        if(NULL != retVal)
            *retVal = STACK_NOK;
    }
    else
    {
        if(!stack->dataInHeap)
            free(stack->dataInHeap);

        free(stack);
        stack = NULL;
        *retVal = STACK_OK;
    }

    return stack;
}

stackStatus_t stackPush (stack_t *stack, void *itemPtr)
{
    stackStatus_t stackStatus = STACK_NOK;

    if (NULL == stack)
    {
        stackStatus = STACK_NULL_PTR;
    }
    else
    {
        if (stackFull(stack))
        {
            stackStatus = STACK_FULL;
        }
        else
        {
            stack->dataInHeap[++stack->topPointer] = itemPtr;
            stackStatus = STACK_OK;
        }
    }
    return stackStatus;
}

void *stackPop (stack_t *stack, stackStatus_t *retVal)
{
    void *stackTop = NULL;

    if (NULL != stack && NULL != retVal)
    {
        if (stackEmpty(stack))
        {
            *retVal = STACK_EMPTY;
        }
        else
        {
            stackTop = stack->dataInHeap[stack->topPointer--];
            *retVal = STACK_OK;
        }
    }
    else
    {
        *retVal = STACK_NOK;
    }

    return stackTop;
}

void *stackTop (stack_t *stack, stackStatus_t *retVal)
{
    void *stackTop = NULL;

    if (NULL != stack && NULL != retVal)
    {
        if (stackEmpty(stack))
        {
            *retVal = STACK_EMPTY;
        }
        else
        {
            stackTop = stack->dataInHeap[stack->topPointer];
            *retVal = STACK_OK;
        }
    }
    else
    {
        *retVal = STACK_NOK;
    }

    return stackTop;
}

s32int stackSize (stack_t *stack, stackStatus_t *retVal)
{
    s32int retSize;

    if (!stack)
    {
        *retVal = STACK_NULL_PTR;
        retSize = -1;
    }
    else
    {
       *retVal = STACK_OK;
        retSize = stack->topPointer + 1;
    }

    return retSize;
}

stackStatus_t stackDisplay (stack_t *stack)
{
    stackStatus_t retVal = STACK_NOK;
    s32int counter = 0;

    if(!stack)
    {
        retVal = STACK_NULL_PTR;
    }
    else
    {
        if(stackEmpty(stack))
        {
            printf("Stack is Empty!");
            retVal = STACK_EMPTY;
        }
        else
        {
            printf("Stack Content: ");
            for (counter = stack->topPointer; counter >= 0; --counter)
            {
                printf("0x%p\t", ((stack->dataInHeap[counter])));
            }
            printf("\n");
            retVal = STACK_OK;
        }
    }
    return retVal;
}
