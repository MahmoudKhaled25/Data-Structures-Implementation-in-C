//
// Created by Blu-ray on 8/15/2023.
//

/**
 ******************************************************************
 * @file              :   main.c
 * @author            :   Mahmoud Khaled
 * @brief             :   This file contains stack data structure declarations
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
}stack_t;

typedef struct retStruct
{
    returnState_t state;
    u32int retValue;
}retStruct_t;

returnState_t pushBack(stack_t *, u32int);
retStruct_t popBack(stack_t *);
retStruct_t stackTop(const stack_t *);
returnState_t stackInit(stack_t *);
retStruct_t stackSize(const stack_t *);
void stackDisplay(const stack_t *);


#endif //STACK_IMPLEMENTATION_STACK_H
