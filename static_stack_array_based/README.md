# Stack Implementation in C


This repository contains a simple yet efficient implementation of a stack data structure in C. A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle, meaning that the last element added to the stack is the first one to be removed.

## Table of Contents

- [Stack Implementation in C](#stack-implementation-in-c)
  - [Table of Contents](#table-of-contents)
  - [Features](#features)
  - [Usage](#usage)
    - [Example](#example)
  - [Contributions](#contributions)

## Features

- **Push and Pop:** Add elements onto the stack and remove them with ease.
- **Peek:** Retrieve the element at the top of the stack without removing it.
- **Initialization:** Initialize the stack for immediate use.
- **Size Inquiry:** Get the current size (number of elements) of the stack.
- **Display:** Visualize the contents of the stack for debugging.

## Usage

To use the stack in your C project, follow these steps:

1. Copy the `stack.h` file into your project directory.
2. Include the `stack.h` header file in your source file(s) where you want to use the stack.
3. Compile and link your source files with the required headers.

### Example

Here's an example of how to use the stack:

```c
#include <stdio.h>
#include "stack.h"

int main() {
    stack_t myStack;
    stackInit(&myStack);

    // Push some elements onto the stack
    pushBack(&myStack, 10);
    pushBack(&myStack, 20);

    // Pop an element from the stack
    retStruct_t poppedItem = popBack(&myStack);
    printf("Popped item: %u\n", poppedItem.retValue);

    // Get the top element without removing it
    retStruct_t topItem = stackTop(&myStack);
    printf("Top item: %u\n", topItem.retValue);

    // Get the current size of the stack
    retStruct_t size = stackSize(&myStack);
    printf("Stack size: %u\n", size.retValue);

    // Display the contents of the stack
    stackDisplay(&myStack);

    return 0;
}

```

## Contributions

Contributions to this Stack implementation are welcome. If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.