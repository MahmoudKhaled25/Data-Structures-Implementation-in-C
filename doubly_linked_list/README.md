# Doubly Linked List Implementation

This repository contains an implementation of a Doubly Linked List in C. The Doubly Linked List is a data structure that consists of a sequence of nodes, where each node contains a data element and two links, one pointing to the previous node and another pointing to the next node in the sequence.

## Table of Content

- [Doubly Linked List Implementation](#doubly-linked-list-implementation)
  - [Table of Content](#table-of-content)
  - [Contents](#contents)
  - [Usage](#usage)
  - [Functionality](#functionality)
    - [Example](#example)
  - [Contributions](#contributions)

## Contents

- `doubly_linked_list.h`: Header file containing the declarations of functions and structures related to the Doubly Linked List.
- `doubly_linked_list.c`: Source file containing the implementations of the Doubly Linked List functions.
- `platform_types.h`: Header file defining platform-specific types used in the Doubly Linked List implementation.
- `main.c`: Example usage of the Doubly Linked List functions.

## Usage

To use the Doubly Linked List in your C project, follow these steps:

1. Copy the `doubly_linked_list.h` and `doubly_linked_list.c` files into your project directory.
2. Include the `doubly_linked_list.h` header file in your source file(s) where you want to use the Doubly Linked List.
3. Compile and link the `doubly_linked_list.c` file along with your other source files.

## Functionality

The Doubly Linked List implementation provides the following functions:

- `createLinkedList`: Create a Doubly Linked List with a specified number of nodes and data.
- `destroyLinkedList`: Destroy the Doubly Linked List and free the memory occupied by the nodes.
- `displayLinkedList`: Display the contents of the Doubly Linked List.
- `countNodes`: Count and return the number of nodes in the Doubly Linked List.
- `addAtBeg`: Add a new node with the given data at the beginning of the Doubly Linked List.
- `addAtEnd`: Add a new node with the given data at the end of the Doubly Linked List.
- `insertNode`: Insert a new node with the given data at the specified position in the Doubly Linked List.
- `delFirstNode`: Delete the first node from the Doubly Linked List.
- `delLastNode`: Delete the last node from the Doubly Linked List.
- `delNode`: Delete the node at the specified position in the Doubly Linked List.
- `reverse`: Reverse the order of nodes in the Doubly Linked List.

### Example

```c
#include <stdio.h>
#include "doubly_linked_list.h"

int main() {
    // Create a new Doubly Linked List
    node_t *head = NULL;
    node_t *tail = NULL;
    createLinkedList(&head, &tail, 5, 10, 20, 30, 40, 50);

    // Display the list
    printf("Linked List: ");
    displayLinkedList(head);

    // Count the number of nodes
    printf("Number of Nodes: %d\n", countNodes(head));

    // Add a new node at the beginning
    addAtBeg(&head, 5);

    // Add a new node at the end
    addAtEnd(&tail, 60);

    // Insert a new node at position 3
    insertNode(&head, &tail, 3, 25);

    // Display the updated list
    printf("Updated List: ");
    displayLinkedList(head);

    // Delete the first node
    delFirstNode(&head);

    // Delete the last node
    delLastNode(&tail);

    // Delete the node at position 2
    delNode(&head, &tail, 2);

    // Reverse the list
    reverse(&head, &tail);

    // Display the reversed list
    printf("Reversed List: ");
    displayLinkedList(head);

    // Destroy the list
    destroyLinkedList(&head);

    return 0;
}

```

## Contributions

Contributions to this Doubly Linked List implementation are welcome. If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.