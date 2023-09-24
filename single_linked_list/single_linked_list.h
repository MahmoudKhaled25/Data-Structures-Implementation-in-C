//
// Created by Blu-ray on 8/20/2023.
//

#ifndef SINGLE_LINKED_LIST_NESO_SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_NESO_SINGLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "platform_types.h"

typedef struct node {
    u32int data;
    struct node *link;
}node_t;

typedef enum retState {
    R_NOK,
    R_OK
}retState_t;

/**
 * @brief This function destroys the entire linked list by deallocating the memory occupied by each node.
 * @param tailNodeRef A pointer to the reference of the tail node of the linked list.
 * @return retState_t (Return state indicating whether the operation was successful or not)
 */
retState_t destroyLinkedList(node_t **tailNodeRef);

/**
 * @brief This function counts the number of nodes in the linked list.
 * @param headNode A pointer to the head node of the linked list.
 * @return u32int (The count of nodes in the linked list)
 */
u32int countNodes(node_t *headNode);

/**
 * @brief This function prints the data stored in each node of the linked list.
 * @param headNode A pointer to the head node of the linked list.
 */
void printNodesData(node_t *headNode);

/**
 * @brief This function adds a new node with the specified data at the end of the linked list.
 * @param tailNodeRef A pointer to the reference of the tail node of the linked list.
 * @param data The data to be stored in the new node.
 * @return retState_t (Return state indicating whether the operation was successful or not)
 */
retState_t addAtEnd(node_t **tailNodeRef, u32int data);

/**
 * @brief This function adds a new node with the specified data at the beginning of the linked list.
 * @param headNodeRef A pointer to the reference of the head node of the linked list.
 * @param data The data to be stored in the new node.
 * @return retState_t (Return state indicating whether the operation was successful or not)
 */
retState_t addAtBeg(node_t **headNodeRef, u32int data);

/**
 * @brief This function inserts a new node with the specified data at the given position in the linked list.
 * @param headNodeRef A pointer to the reference of the head node of the linked list.
 * @param tailNodeRef A pointer to the reference of the tail node of the linked list.
 * @param pos The position at which the new node should be inserted.
 * @param data The data to be stored in the new node.
 * @return retState_t (Return state indicating whether the operation was successful or not)
 */
retState_t insert(node_t **headNodeRef, node_t **tailNodeRef, u32int pos, u32int data);

/**
 * @brief This function deletes the first node from the linked list.
 * @param headNodeRef A pointer to the reference of the head node of the linked list.
 * @return retState_t (Return state indicating whether the operation was successful or not)
 */
retState_t delFirstNode(node_t **headNodeRef);

/**
 * @brief This function deletes the last node from the linked list.
 * @param headNodeRef A pointer to the reference of the head node of the linked list.
 * @param tailNodeRef A pointer to the reference of the tail node of the linked list.
 * @return retState_t (Return state indicating whether the operation was successful or not)
 */
retState_t delLastNode(node_t **headNodeRef, node_t **tailNodeRef);

/**
 * @brief This function deletes the node at the specified position in the linked list.
 * @param headNodeRef A pointer to the reference of the head node of the linked list.
 * @param tailNodeRef A pointer to the reference of the tail node of the linked list.
 * @param pos The position of the node to be deleted.
 * @return retState_t (Return state indicating whether the operation was successful or not)
 */
retState_t delNode(node_t **headNodeRef, node_t **tailNodeRef, u32int pos);

/**
 * @brief This function reverses the order of nodes in the linked list.
 * @param headNodeRef A pointer to the reference of the head node of the linked list.
 * @param tailNodeRef A pointer to the reference of the tail node of the linked list.
 * @return retState_t (Return state indicating whether the operation was successful or not)
 */
retState_t reverse(node_t **headNodeRef, node_t **tailNodeRef);

#endif //SINGLE_LINKED_LIST_NESO_SINGLE_LINKED_LIST_H
