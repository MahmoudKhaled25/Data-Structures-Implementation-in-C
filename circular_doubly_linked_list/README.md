# Circular Doubly Linked List in C

This repository contains a C implementation of a Circular Doubly Linked List, a versatile data structure with various applications. A Circular Doubly Linked List is a data structure that consists of a sequence of nodes, where each node contains a data element and two links. One link points to the next node, and the other points to the previous node in the sequence. It is a variation of a doubly linked list where the last node points back to the first node, creating a circular structure.

## Table of Contents

- [Circular Doubly Linked List in C](#circular-doubly-linked-list-in-c)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Contents](#contents)
  - [Usage](#usage)
  - [Functionality](#functionality)
    - [Example](#example)
  - [Contributions](#contributions)

## Introduction

A Circular Doubly Linked List is a powerful data structure that offers efficient operations for various tasks, such as managing lists of items with dynamic sizes, implementing undo-redo functionality, and handling circular queues.

## Contents

- `circular_doubly_linked_list.h`: Header file containing the declarations of functions and structures related to the Circular Doubly Linked List.
- `circular_doubly_linked_list.c`: Source file containing the implementations of the Circular Doubly Linked List functions.
- `platform_types.h`: Header file defining platform-specific types used in the Circular Doubly Linked List implementation.
- `main.c`: Example usage of the Circular Doubly Linked List functions.

## Usage

To incorporate the Circular Doubly Linked List into your C project, follow these straightforward steps:

1. Copy the `circular_doubly_linked_list.h` file into your project directory.
2. Include the `circular_doubly_linked_list.h` header file in your source file(s) where you intend to use the Circular Doubly Linked List.
3. Compile and link your source files with the required headers.

## Functionality

The Circular Doubly Linked List implementation provides a comprehensive set of functions for managing and manipulating the list. Here are the key functions:

- `createList`: Create a Circular Doubly Linked List with a specified number of nodes and data.
- `destroyList`: Destroy the Circular Doubly Linked List and free the memory occupied by the nodes.
- `addAtBeg`: Add a new node with the given data at the beginning of the Circular Doubly Linked List.
- `addAtEnd`: Add a new node with the given data at the end of the Circular Doubly Linked List.
- `insert`: Insert a new node with the given data at the specified position in the Circular Doubly Linked List.
- `delLastNode`: Delete the last node from the Circular Doubly Linked List.
- `delFirstNode`: Delete the first node from the Circular Doubly Linked List.
- `delNode`: Delete the node at the specified position in the Circular Doubly Linked List.
- `reverseList`: Reverse the order of nodes in the Circular Doubly Linked List.
- `sortList`: Sort the Circular Doubly Linked List in ascending order.
- `printList`: Display the contents of the Circular Doubly Linked List.
- `countNodes`: Count and return the number of nodes in the Circular Doubly Linked List.

### Example

Here's an example of how to use the Circular Doubly Linked List in your code:

```c
#include <stdio.h>
#include "circular_doubly_linked_list.h"

int main() {
    node_t *tail = NULL;
    
    // Create a Circular Doubly Linked List with 3 nodes and data 10, 20, 30
    createList(&tail, 3, 10, 20, 30);
    
    // Display the list
    printf("Circular Doubly Linked List: ");
    printList(tail);

    // Add a new node at the beginning with data 5
    addAtBeg(&tail, 5);
    
    // Add a new node at the end with data 40
    addAtEnd(&tail, 40);

    // Insert a new node with data 25 at position 2
    insert(&tail, 2, 25);

    // Display the updated list
    printf("Updated List: ");
    printList(tail);

    // Delete the last node
    delLastNode(&tail);

    // Delete the first node
    delFirstNode(&tail);

    // Delete the node at position 1
    delNode(&tail, 1);

    // Reverse the list
    reverseList(&tail);

    // Display the reversed list
    printf("Reversed List: ");
    printList(tail);

    // Destroy the list
    destroyList(&tail);

    return 0;
}

```

## Contributions

Contributions to this Circular Doubly Linked List implementation are welcome. If you encounter any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request.