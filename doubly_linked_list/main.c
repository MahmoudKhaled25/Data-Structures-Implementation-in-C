#include <stdio.h>
#include "doubly_linked_list.h"

node_t *head = NULL;
node_t *tail = NULL;

void displayRetState (retState_t retState);

int main(void)
{
    retState_t returnStatus;

    printf("Number of Nodes: %u\n", countNodes(head));
    displayLinkedList(head);

    // Creating 1st node
    returnStatus = createLinkedList(&head, &tail, 3, 66, 77, 88);
    printf("Number of Nodes: %u\n", countNodes(head));
    displayRetState(returnStatus);
    displayLinkedList(head);

    // Add 4th node at beginning
    returnStatus = addAtBeg(&head, 98);
    printf("Number of Nodes: %u\n", countNodes(head));
    displayRetState(returnStatus);
    displayLinkedList(head);

    // Add 5th node at end
    returnStatus = addAtEnd(&tail, 3);
    printf("Number of Nodes: %u\n", countNodes(head));
    displayRetState(returnStatus);
    displayLinkedList(head);

    // Insert 6th node at position 2
    returnStatus = insertNode(&head, &tail, 2, 55);
    printf("Number of Nodes: %u\n", countNodes(head));
    displayRetState(returnStatus);
    displayLinkedList(head);

    // Insert 7th node at beginning
    returnStatus = insertNode(&head, &tail, 1, 44);
    printf("Number of Nodes: %u\n", countNodes(head));
    displayRetState(returnStatus);
    displayLinkedList(head);

    // Insert 8th node at end
    returnStatus = insertNode(&head, &tail, 8, 77);
    printf("Number of Nodes: %u\n", countNodes(head));
    displayRetState(returnStatus);
    displayLinkedList(head);

    // Insert a node at invalid position
    returnStatus = insertNode(&head, &tail, 11, 77);
    printf("Number of Nodes: %u\n", countNodes(head));
    displayRetState(returnStatus);
    displayLinkedList(head);

    // Reverse the list
    returnStatus = reverse(&head, &tail);
    printf("Number of Nodes: %u\n", countNodes(head));
    displayRetState(returnStatus);
    displayLinkedList(head);

    // Delete the node at position 3
    returnStatus = delNode(&head, &tail, 3);
    printf("Number of Nodes: %u\n", countNodes(head));
    displayRetState(returnStatus);
    displayLinkedList(head);

    // Delete the first node from the list
    returnStatus = delFirstNode(&head);
    printf("Number of Nodes: %u\n", countNodes(head));
    displayRetState(returnStatus);
    displayLinkedList(head);

    // Delete the last node from the list
    returnStatus = delLastNode(&tail);
    printf("Number of Nodes: %u\n", countNodes(head));
    displayRetState(returnStatus);
    displayLinkedList(head);

    // Delete the list
    returnStatus = destroyLinkedList(&head);
    printf("Number of Nodes: %u\n", countNodes(head));
    displayRetState(returnStatus);
    displayLinkedList(head);

    return 0;
}

void displayRetState (retState_t retState)
{
    if (R_NOK == retState)
    {
        printf("Return Status: R_NOK\n");
    }
    else if (R_OK == retState)
    {
        printf("Return Status: R_OK\n");
    }
    else
    {
        printf("Undefined Return Status\n");
    }
}