#include <stdio.h>

#include "single_linked_list.h"

node_t *head = NULL;
node_t *tail = NULL;

int main(void)
{
    //Trying to pass NULL to addAtEnd and invalid position to insert
    addAtEnd(&tail, 11);
    insert(&head,&tail, 5, 33);
    printf("Number of Nodes: %u\n", countNodes(head));
    printNodesData(head);
    printf("\n");

    // Creating head node
    addAtBeg(&head, 45);
    tail = head;
    printf("Number of Nodes: %u\n", countNodes(head));
    printNodesData(head);
    printf("\n");


    // Add 2nd node to end
    addAtEnd(&tail, 98);
    printf("Number of Nodes: %u\n", countNodes(head));
    printNodesData(head);
    printf("\n");

    // Add 3rd node to end
    addAtEnd(&tail, 3);
    printf("Number of Nodes: %u\n", countNodes(head));
    printNodesData(head);
    printf("\n");

    // Add 4th node to begin
    addAtBeg(&head, 77);
    printf("Number of Nodes: %u\n", countNodes(head));
    printNodesData(head);
    printf("\n");

    // Add 5th node to position 3
    insert(&head, &tail, 3, 66);
    printf("Number of Nodes: %u\n", countNodes(head));
    printNodesData(head);
    printf("\n");

    // Add 6th node to position 1
    insert(&head, &tail, 1, 22);
    printf("Number of Nodes: %u\n", countNodes(head));
    printNodesData(head);
    printf("\n");

    // Add 7th node to position 7
    insert(&head, &tail, 7, 33);
    printf("Number of Nodes: %u\n", countNodes(head));
    printNodesData(head);
    printf("\n");

    // Add 8th node to position 1
    insert(&head, &tail, 1, 55);
    printf("Number of Nodes: %u\n", countNodes(head));
    printNodesData(head);
    printf("\n");

    // Reverse linked list
    reverse(&head, &tail);
    printf("Number of Nodes: %u\n", countNodes(head));
    printNodesData(head);
    printf("\n");

    // Delete last node from linked list
    // Now we have 7 nodes
    delLastNode(&head, &tail);
    printf("Number of Nodes: %u\n", countNodes(head));
    printNodesData(head);
    printf("\n");

    // Delete first node from linked list
    // Now we have 6 nodes
    delFirstNode(&head);
    printf("Number of Nodes: %u\n", countNodes(head));
    printNodesData(head);
    printf("\n");

    // Delete 3rd node from linked list
    // Now we have 5 nodes
    delNode(&head, &tail, 3);
    printf("Number of Nodes: %u\n", countNodes(head));
    printNodesData(head);
    printf("\n");

    // Reverse linked list
    reverse(&head, &tail);
    printf("Number of Nodes: %u\n", countNodes(head));
    printNodesData(head);
    printf("\n");


    // Deallocating the linked list
    destroyLinkedList(&head);

    if(NULL == head)
        printf("Linked List destroyed Successfully\n");

    return 0;
}
