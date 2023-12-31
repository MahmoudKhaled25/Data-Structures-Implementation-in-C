# Array-Based Queue Implementation in C

This repository contains a C implementation of an array-based queue. A queue is a linear data structure that follows the First-In-First-Out (FIFO) principle, where the element added first is the one removed first.

## Table of Contents

- [Array-Based Queue Implementation in C](#array-based-queue-implementation-in-c)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Usage](#usage)
  - [Functionality](#functionality)
    - [Example](#example)
  - [Contributions](#contributions)

## Overview

The array-based queue is implemented in C and consists of the following components:

- `queue_array_based.h`: Header file containing function declarations and data structures for the array-based queue.
- `queue_array_based.c`: Source file with implementations of queue functions.
- `platform_types.h`: Header file defining platform-specific types used in the implementation.
- `main.c`: Example usage of the queue functions.

## Usage

To use the array-based queue in your C project, follow these steps:

1. Copy the `queue_array_based.h` and `queue_array_based.c` files into your project directory.
2. Include the `queue_array_based.h` header file in your source file(s) where you want to use the queue.
3. Compile and link the `queue_array_based.c` file along with your other source files.

## Functionality

The array-based queue implementation provides the following functions:

- `queue_t *createQueue(u64int queueSize)`: Creates a new queue with the specified maximum size.
- `retState_t destroyQueue(queue_t *queue)`: Destroys the queue and frees associated memory.
- `retState_t enqueue(queue_t *queue, u32int data)`: Inserts an element into the rear of the queue.
- `retState_t dequeue(queue_t *queue, u32int *data)`: Removes an element from the front of the queue.
- `retState_t queueFront(const queue_t *queue, u32int *data)`: Retrieves the element at the front of the queue without removing it.
- `retState_t queueRear(const queue_t *queue, u32int *data)`: Retrieves the element at the rear of the queue without removing it.
- `retState_t getQueueCount(const queue_t *queue, u32int *queueCount)`: Retrieves the current number of elements in the queue.

### Example

```c
#include <stdio.h>
#include "queue_array_based.h"

int main() {
    // Create a new queue with a maximum size of 10 elements
    queue_t *myQueue = createQueue(10);

    // Enqueue elements
    enqueue(myQueue, 5);
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);

    // Dequeue elements
    u32int data;
    dequeue(myQueue, &data);
    printf("Dequeued: %d\n", data);

    // Retrieve the front element
    queueFront(myQueue, &data);
    printf("Front element: %d\n", data);

    // Destroy the queue
    destroyQueue(myQueue);

    return 0;
}

```

## Contributions

Contributions to this array-based queue implementation are welcome. If you encounter any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request.