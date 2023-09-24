//
// Created by Blu-ray on 8/27/2023.
//

#ifndef DOUBLY_LINKED_LIST_DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_DOUBLY_LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "platform_types.h"


typedef struct node
{
    struct node *nextNode;
    struct node *prevNode;
    u32int data;
}node_t;


typedef enum retState
{
    R_NOK,
    R_OK
}retState_t;

/**
 * @brief           Creates a doubly linked list with the specified number of nodes and data values.
 * @param headRef   Pointer to the head of the linked list.
 * @param tailRef   Pointer to the tail of the linked list.
 * @param numNodes  Number of nodes to create.
 * @param ...       Variable number of data values to be assigned to each node.
 * @return          Returns R_OK if the linked list is successfully created, R_NOK otherwise.
 */
retState_t createLinkedList(node_t **headRef, node_t **tailRef, u32int numNodes, ...);

/**
 * @brief           Destroys the doubly linked list and frees the memory occupied by each node.
 * @param headRef   Pointer to the head of the linked list.
 * @return          Returns R_OK if the linked list is successfully destroyed, R_NOK otherwise.
 */
retState_t destroyLinkedList(node_t **headRef);

/**
 * @brief           Displays the contents of the doubly linked list.
 * @param head      Pointer to the head of the linked list.
 */
void displayLinkedList(node_t *head);

/**
 * @brief           Counts and returns the number of nodes in the doubly linked list.
 * @param head      Pointer to the head of the linked list.
 * @return          Number of nodes in the linked list.
 */
u32int countNodes(node_t *head);

/**
 * @brief           Adds a node with the specified data at the beginning of the doubly linked list.
 * @param headRef   Pointer to the head of the linked list.
 * @param data      Data value to be added to the new node.
 * @return          Returns R_OK if the node is successfully added, R_NOK otherwise.
 */
retState_t addAtBeg(node_t **headRef, u32int data);

/**
 * @brief           Adds a node with the specified data at the end of the doubly linked list.
 * @param tailRef   Pointer to the tail of the linked list.
 * @param data      Data value to be added to the new node.
 * @return          Returns R_OK if the node is successfully added, R_NOK otherwise.
 */
retState_t addAtEnd(node_t **tailRef, u32int data);

/**
 * @brief           Inserts a node with the specified data at the given position in the doubly linked list.
 * @param headRef   Pointer to the head of the linked list.
 * @param tailRef   Pointer to the tail of the linked list.
 * @param pos       Position at which the new node should be inserted.
 * @param data      Data value to be added to the new node.
 * @return          Returns R_OK if the node is successfully inserted, R_NOK otherwise.
 */
retState_t insertNode(node_t **headRef, node_t **tailRef, u32int pos, u32int data);

/**
 * @brief           Deletes the first node from the doubly linked list.
 * @param headRef   Pointer to the head of the linked list.
 * @return          Returns R_OK if the first node is successfully deleted, R_NOK otherwise.
 */
retState_t delFirstNode(node_t **headRef);

/**
 * @brief           Deletes the last node from the doubly linked list.
 * @param tailRef   Pointer to the tail of the linked list.
 * @return          Returns R_OK if the last node is successfully deleted, R_NOK otherwise.
 */
retState_t delLastNode(node_t **tailRef);

/**
 * @brief           Deletes the node at the specified position in the doubly linked list.
 * @param headRef   Pointer to the head of the linked list.
 * @param tailRef   Pointer to the tail of the linked list.
 * @param pos       Position of the node to be deleted.
 * @return          Returns R_OK if the node is successfully deleted, R_NOK otherwise.
 */
retState_t delNode(node_t **headRef, node_t **tailRef, u32int pos);

/**
 * @brief           Reverses the order of nodes in the doubly linked list.
 * @param headRef   Pointer to the head of the linked list.
 * @param tailRef   Pointer to the tail of the linked list.
 * @return          Returns R_OK if the linked list is successfully reversed, R_NOK otherwise.
 */
retState_t reverse(node_t **headRef, node_t **tailRef);

#endif //DOUBLY_LINKED_LIST_DOUBLY_LINKED_LIST_H
