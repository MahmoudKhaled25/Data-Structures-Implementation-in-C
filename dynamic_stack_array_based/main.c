/**
 ******************************************************************
 * @file              :   main.c
 * @author            :   Mahmoud Khaled
 * @brief             :   This file to use stack data structure implementation
 ******************************************************************
 */

/* *********************** Link section start *********************** */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


/* *********************** Link section end ************************* */

/* ******************** Definition section start ******************** */

/* ******************** Definition section end ********************** */

/* **************** Global declaration section start **************** */
stack_t *myStack = NULL;
u32int var1 = 0x11;
u32int var2 = 0x22;
u32int var3 = 0x33;
u32int var4 = 0x44;
u32int var5 = 0x55;
/* **************** Global declaration section end****************** */

int main(void)
{
    stackStatus_t returnStatus;

    myStack = stackCreate(3, &returnStatus);


    returnStatus = stackPush(myStack, &var1); printf("%i\n", returnStatus);
    returnStatus = stackPush(myStack, &var2); printf("%i\n", returnStatus);
    returnStatus = stackPush(myStack, &var3); printf("%i\n", returnStatus);
    returnStatus = stackPush(myStack, &var4); printf("%i\n", returnStatus);
    returnStatus = stackPush(myStack, &var5); printf("%i\n", returnStatus);

    stackDisplay(myStack);

    stackPop(myStack, &returnStatus);

    stackDisplay(myStack);

    stackDestroy(myStack, &returnStatus);

    return 0;
}

/* ****************** Sub-functions section start ******************* */



/* ****************** Sub-functions section end ********************* */

/**
 ************************************************************************
     @user          @date          @brief
 ************************************************************************
 *   Mahmoud       19apr2023       Start coding the program
 */
