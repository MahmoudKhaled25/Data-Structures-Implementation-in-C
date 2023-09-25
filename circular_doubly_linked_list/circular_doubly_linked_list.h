/**
 * @file circular_doubly_linked_list.h
 * @author Mahmoud Khaled
 * @date 2023-09-24
 * @brief Header file for Circular Doubly Linked List operations in C.
 */

#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H_
#define CIRCULAR_DOUBLY_LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "platform_types.h"

/**
 * @struct node_t
 * Structure representing a node in the Circular Doubly Linked List.
 */
typedef struct Node
{
    struct Node *nextNode; /**< Pointer to the next node in the list. */
    struct Node *prevNode; /**< Pointer to the previous node in the list. */
    u32int data; /**< Data stored in the node. */
} node_t;

/**
 * @enum retState_t
 * Enumeration representing the return states of the operations on the Circular Doubly Linked List.
 */
typedef enum retState
{
    R_NOK, /**< Indicates an operation failure. */
    R_OK   /**< Indicates a successful operation. */
} retState_t;

/**
 * @brief Create a Circular Doubly Linked List with a specified number of nodes and data.
 *
 * This function creates a Circular Doubly Linked List with the given number of nodes and data values.
 * The data values are provided as variable arguments.
 *
 * @param tailRef Pointer to the tail reference of the Circular Doubly Linked List.
 * @param numNodes The number of nodes to create.
 * @param ... Variable arguments representing the data values for the nodes.
 * @return retState_t Returns R_OK if the list creation is successful, R_NOK otherwise.
 */
retState_t createList(node_t **tailRef, u32int numNodes, ...);

/**
 * @brief Destroy the Circular Doubly Linked List and free the memory occupied by the nodes.
 *
 * This function destroys the Circular Doubly Linked List and frees the memory occupied by the nodes.
 * It also sets the tail reference to NULL.
 *
 * @param tailRef Pointer to the tail reference of the Circular Doubly Linked List.
 * @return retState_t Returns R_OK if the list destruction is successful, R_NOK otherwise.
 */
retState_t destroyList(node_t **tailRef);

/**
 * @brief Add a new node with the given data at the beginning of the Circular Doubly Linked List.
 *
 * This function adds a new node with the provided data at the beginning of the Circular Doubly Linked List.
 * The tail reference is updated accordingly.
 *
 * @param tailRef Pointer to the tail reference of the Circular Doubly Linked List.
 * @param data The data to be stored in the new node.
 * @return retState_t Returns R_OK if the addition is successful, R_NOK otherwise.
 */
retState_t addAtBeg(node_t **tailRef, u32int data);

/**
 * @brief Add a new node with the given data at the end of the Circular Doubly Linked List.
 *
 * This function adds a new node with the provided data at the end of the Circular Doubly Linked List.
 * The tail reference is updated accordingly.
 *
 * @param tailRef Pointer to the tail reference of the Circular Doubly Linked List.
 * @param data The data to be stored in the new node.
 * @return retState_t Returns R_OK if the addition is successful, R_NOK otherwise.
 */
retState_t addAtEnd(node_t **tailRef, u32int data);

/**
 * @brief Insert a new node with the given data at the specified position in the Circular Doubly Linked List.
 *
 * This function inserts a new node with the provided data at the specified position in the Circular Doubly Linked List.
 * The tail reference and the positions of the existing nodes are adjusted accordingly.
 *
 * @param tailRef Pointer to the tail reference of the Circular Doubly Linked List.
 * @param pos The position at which the new node should be inserted (starting from 0).
 * @param data The data to be stored in the new node.
 * @return retState_t Returns R_OK if the insertion is successful, R_NOK otherwise.
 */
retState_t insert(node_t **tailRef, u32int pos, u32int data);

/**
 * @brief Delete the last node in the Circular Doubly Linked List.
 *
 * This function deletes the last node in the Circular Doubly Linked List and updates the tail reference accordingly.
 *
 * @param tailRef Pointer to the tail reference of the Circular Doubly Linked List.
 * @return retState_t Returns R_OK if the deletion is successful, R_NOK otherwise.
 */
retState_t delLastNode(node_t **tailRef);

/**
 * @brief Delete the first node in the Circular Doubly Linked List.
 *
 * This function deletes the first node in the Circular Doubly Linked List and updates the tail reference accordingly.
 *
 * @param tailRef Pointer to the tail reference of the Circular Doubly Linked List.
 * @return retState_t Returns R_OK if the deletion is successful, R_NOK otherwise.
 */
retState_t delFirstNode(node_t **tailRef);

/**
 * @brief Delete the node at the specified position in the Circular Doubly Linked List.
 *
 * This function deletes the node at the specified position in the Circular Doubly Linked List and updates
 * the tail reference and the positions of the remaining nodes accordingly.
 *
 * @param tailRef Pointer to the tail reference of the Circular Doubly Linked List.
 * @param pos The position of the node to be deleted (starting from 0).
 * @return retState_t Returns R_OK if the deletion is successful, R_NOK otherwise.
 */
retState_t delNode(node_t **tailRef, u32int pos);

/**
 * @brief Reverse the order of nodes in the Circular Doubly Linked List.
 *
 * This function reverses the order of nodes in the Circular Doubly Linked List by updating the links between the nodes.
 * The tail reference is also updated to point to the new head of the list.
 *
 * @param tailRef Pointer to the tail reference of the Circular Doubly Linked List.
 * @return retState_t Returns R_OK if the reversal is successful, R_NOK otherwise.
 */
retState_t reverseList(node_t **tailRef);

/**
 * @brief Sort the Circular Doubly Linked List in ascending order.
 *
 * This function sorts the Circular Doubly Linked List in ascending order.
 *
 * @param tail Pointer to the tail node of the Circular Doubly Linked List.
 * @return retState_t Returns R_OK if the sorting is successful, R_NOK otherwise.
 */
retState_t sortList(node_t *tail);

/**
 * @brief Print the data values of all nodes in the Circular Doubly Linked List.
 *
 * This function prints the data values of all nodes in the Circular Doubly Linked List, starting from the tail.
 *
 * @param tail Pointer to the tail of the Circular Doubly Linked List.
 */
void printList(node_t *tail);

/**
 * @brief Count the number of nodes in the Circular Doubly Linked List.
 *
 * This function counts the number of nodes present in the Circular Doubly Linked List and returns the count.
 *
 * @param tail Pointer to the tail of the Circular Doubly Linked List.
 * @return u32int The number of nodes in the list.
 */
u32int countNodes(node_t *tail);

#endif // CIRCULAR_DOUBLY_LINKED_LIST_H_
