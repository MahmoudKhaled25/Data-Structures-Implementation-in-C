# Circular Singly Linked List Implementation

This repository contains an implementation of a Circular Singly Linked List in C. The Circular Singly Linked List is a data structure that consists of a sequence of nodes, where each node contains a data element and a link to the next node in the sequence. In a circular singly linked list, the last node's link points back to the first node, forming a circular structure.

### Contents

- circular_singly_linked_list.h: Header file containing the declarations of functions and structures related to the Circular Singly Linked List.
- circular_singly_linked_list.c: Source file containing the implementations of the Circular Singly Linked List functions.
- platform_types.h: Header file defining platform-specific types used in the Circular Singly Linked List implementation.
- main.c: Example usage of the Circular Singly Linked List functions.

### Usage

To use the Circular Singly Linked List in your C project, follow these steps:

1. Copy the `circular_singly_linked_list.h` and `circular_singly_linked_list.c` files into your project directory.
2. Include the `circular_singly_linked_list.h` header file in your source file(s) where you want to use the Circular Singly Linked List.
3. Compile and link the `circular_singly_linked_list.c` file along with your other source files.

### Functionality

The Circular Singly Linked List implementation provides the following functions:

- `createList`: Create a Circular Singly Linked List with a specified number of nodes and data.
- `destroyList`: Destroy the Circular Singly Linked List and free the memory occupied by the nodes.
- `addAtBeg`: Add a new node with the given data at the beginning of the Circular Singly Linked List.
- `addAtEnd`: Add a new node with the given data at the end of the Circular Singly Linked List.
- `insert`: Insert a new node with the given data at the specified position in the Circular Singly Linked List.
- `delLastNode`: Delete the last node in the Circular Singly Linked List.
- `delFirstNode`: Delete the first node in the Circular Singly Linked List.
- `delNode`: Delete the node at the specified position in the Circular Singly Linked List.
- `reverseList`: Reverse the order of nodes in the Circular Singly Linked List.
- `printList`: Print the data values of all nodes in the Circular Singly Linked List.
- `countNodes`: Count the number of nodes in the Circular Singly Linked List.

### Example

```c
#include <stdio.h>
#include "circular_singly_linked_list.h"

int main() {
    // Create a new Circular Singly Linked List
    node_t *tail = NULL;
    createList(&tail, 3, 10, 20, 30);

    // Add a new node at the beginning
    addAtBeg(&tail, 5);

    // Add a new node at the end
    addAtEnd(&tail, 40);

    // Insert a new node at position 2
    insert(&tail, 2, 15);

    // Print the list
    printf("List: ");
    printList(tail);

    // Reverse the list
    reverseList(&tail);

    // Print the reversed list
    printf("Reversed List: ");
    printList(tail);

    // Delete the last node
    delLastNode(&tail);

    // Delete the first node
    delFirstNode(&tail);

    // Delete the node at position 1
    delNode(&tail, 1);

    // Print the updated list
    printf("Updated List: ");
    printList(tail);

    // Count the number of nodes
    printf("Number of Nodes: %d\n", countNodes(tail));

    // Destroy the list
    destroyList(&tail);

    return 0;
}

```

### Contributions

Contributions to this Circular Singly Linked List implementation are welcome. If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.