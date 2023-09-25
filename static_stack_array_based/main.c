/**
 ******************************************************************
 * @file              :   main.c
 * @author            :   Mahmoud Khaled
 * @brief             :   This file to use stack data structure implementation
 ******************************************************************
 */

/* *********************** Link section start *********************** */
#include <stdio.h>
#include "stack.h"


int main(void)
{

    stack_t stack;
    u8int returnedVal;
    retStruct_t retValues;

    returnedVal = stackInit(&stack);

    stackDisplay(&stack);

    returnedVal = pushBack(&stack, 11);
    returnedVal = pushBack(&stack, 22);
    returnedVal = pushBack(&stack, 33);
    returnedVal = pushBack(&stack, 44);
    returnedVal = pushBack(&stack, 55);
    returnedVal = pushBack(&stack, 66);
    returnedVal = pushBack(&stack, 66);

    stackDisplay(&stack);

    retValues = popBack(&stack);
    retValues = popBack(&stack);
    retValues = popBack(&stack);
    retValues = popBack(&stack);
    retValues = popBack(&stack);
    retValues = stackTop(&stack);
    retValues = popBack(&stack);
    return 0;
}

/**
 ************************************************************************
     @user          @date          @brief
 ************************************************************************
 *   Mahmoud       19apr2023       Start coding the program
 */
