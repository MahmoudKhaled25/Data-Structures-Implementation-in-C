/**
 * @file main.c
 * @author Mahmoud Khaled
 * @date 2023-09-24
 *  
 */
#include <stdio.h>
#include "circular_singly_linked_list.h"

void showRetState (retState_t myState);

int main()
{
//    node_t **tailRef = NULL;
    node_t *tail = NULL;
    retState_t retVal;

    printList(tail);

    // Create a list with 1 node
    retVal = createList (&tail, 1, 1);
    showRetState (retVal);
    printList (tail);

    // Adding 2nd node at the end
    retVal = addAtEnd(&tail, 2);
    showRetState (retVal);
    printList(tail);

    // Adding 3rd node at the beginning
    retVal = addAtBeg(&tail, 0);
    showRetState (retVal);
    printList(tail);

    // Adding 4th node at the pos 2
    retVal = insert(&tail, 2, 77);
    showRetState (retVal);
    printList(tail);

    // Adding 5th node at the pos 1
    retVal = insert(&tail, 1, 99);
    showRetState (retVal);
    printList(tail);

    // Adding 6th node at the pos 6
    retVal = insert(&tail, 6, 11);
    showRetState (retVal);
    printList(tail);

    // Adding node at invalid position
    retVal = insert(&tail, 12, 22);
    showRetState (retVal);
    printList(tail);

    // Reversing the list
    retVal = reverseList(&tail);
    showRetState (retVal);
    printList(tail);

    // Deleting first node from the list
    retVal = delFirstNode(&tail);
    showRetState (retVal);
    printList(tail);

    // Deleting last node from the list
    retVal = delLastNode(&tail);
    showRetState (retVal);
    printList(tail);

    // Deleting last node from the list
    retVal = delNode(&tail, 3);
    showRetState (retVal);
    printList(tail);


    // Destroying the list
    retVal = destroyList(&tail);
    showRetState (retVal);
    printList(tail);

    return 0;
}

void showRetState (retState_t myState)
{
    printf("Return Status: %s\n", R_OK == myState ? "Success" : (R_NOK == myState ? "Failed" : "Undefined"));
}