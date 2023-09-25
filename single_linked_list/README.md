# Single Linked List Implementation

This repository provides an implementation of a single linked list in the C programming language. It offers a collection of functions to manipulate and operate on a linked list data structure.

## Table of Content

- [Single Linked List Implementation](#single-linked-list-implementation)
  - [Table of Content](#table-of-content)
  - [Usage](#usage)
  - [Functions](#functions)
  - [Contributions](#contributions)

## Usage

To use the single linked list implementation in your C projects, follow these steps:

1. Copy the `single_linked_list.h` header file into your project directory.
2. Include the header file in your source file(s) where you want to use the linked list functions.
3. Compile and link your source file(s) along with the linked list implementation.

## Functions

The `single_linked_list.h` header file provides the following functions:

- `retState_t destroyLinkedList(node_t **tailNodeRef)`: Destroys the entire linked list by deallocating the memory occupied by each node.
- `u32int countNodes(node_t *headNode)`: Counts the number of nodes in the linked list.
- `void printNodesData(node_t *headNode)`: Prints the data stored in each node of the linked list.
- `retState_t addAtEnd(node_t **tailNodeRef, u32int data)`: Adds a new node with the specified data at the end of the linked list.
- `retState_t addAtBeg(node_t **headNodeRef, u32int data)`: Adds a new node with the specified data at the beginning of the linked list.
- `retState_t insert(node_t **headNodeRef, node_t **tailNodeRef, u32int pos, u32int data)`: Inserts a new node with the specified data at the given position in the linked list.
- `retState_t delFirstNode(node_t **headNodeRef)`: Deletes the first node from the linked list.
- `retState_t delLastNode(node_t **headNodeRef, node_t **tailNodeRef)`: Deletes the last node from the linked list.
- `retState_t delNode(node_t **headNodeRef, node_t **tailNodeRef, u32int pos)`: Deletes the node at the specified position in the linked list.
- `retState_t reverse(node_t **headNodeRef, node_t **tailNodeRef)`: Reverses the order of nodes in the linked list.

Please refer to the `single_linked_list.h` header file for detailed descriptions of each function and their parameters.

## Contributions

Contributions to this repository are welcome! If you find any issues, bugs, or have suggestions for improvements, feel free to open an issue or submit a pull request. By contributing, you can help enhance the quality and functionality of the single linked list implementation, making it even more valuable for the developer community.

Let's build robust and efficient linked lists together!