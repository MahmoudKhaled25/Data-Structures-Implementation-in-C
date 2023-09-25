# Dynamic Stack (Array-Based) in C

This repository contains a C implementation of a Dynamic Stack using an array-based approach. A dynamic stack is a data structure that allows you to push and pop elements onto and from a stack, where the stack size can dynamically adjust as elements are added or removed.

## Table of Content

- [Dynamic Stack (Array-Based) in C](#dynamic-stack-array-based-in-c)
  - [Table of Content](#table-of-content)
  - [Contents](#contents)
  - [Usage](#usage)
  - [Functionality](#functionality)
    - [Example](#example)
  - [Contributions](#contributions)

## Contents

- `stack.h`: Header file containing the declarations of functions and structures related to the Dynamic Stack.
- `stack.c`: Source file containing the actual implementations of the Dynamic Stack functions.
- `platform_types.h`: Header file defining platform-specific types used in the Dynamic Stack implementation.
- `main.c`: Example usage of the Dynamic Stack functions.

## Usage

To use the Dynamic Stack in your C project, follow these steps:

1. Copy the `stack.h` and `stack.c` files into your project directory.
2. Include the `stack.h` header file in your source file(s) where you want to use the Dynamic Stack.
3. Compile and link your source files with the required headers and the `stack.c` implementation.

## Functionality

The Dynamic Stack (Array-Based) implementation provides the following functions:

- `stackCreate`: Create a new stack with the specified size.
- `stackDestroy`: Destroy the given stack and free the associated memory.
- `stackPush`: Push an item onto the stack.
- `stackPop`: Pop an item from the top of the stack.
- `stackTop`: Retrieve the item at the top of the stack without removing it.
- `stackSize`: Get the current size (number of elements) of the stack.
- `stackDisplay`: Display the contents of the stack.

### Example

Here's an example of how to use the Dynamic Stack:

```c
#include <stdio.h>
#include "stack.h"

int main() {
    stack_t *myStack;
    stackStatus_t status;

    // Create a new stack with a maximum size of 10
    myStack = stackCreate(10, &status);

    // Push some items onto the stack
    int item1 = 10;
    int item2 = 20;
    stackPush(myStack, &item1);
    stackPush(myStack, &item2);

    // Pop an item from the stack
    int *poppedItem = (int *)stackPop(myStack, &status);

    // Get the item at the top of the stack without removing it
    int *topItem = (int *)stackTop(myStack, &status);

    // Display the current size of the stack
    s32int size = stackSize(myStack, &status);

    // Display the contents of the stack
    stackDisplay(myStack);

    // Destroy the stack and free the memory
    myStack = stackDestroy(myStack, &status);

    return 0;
}

```

## Contributions

Contributions to this Stack implementation are welcome. If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.