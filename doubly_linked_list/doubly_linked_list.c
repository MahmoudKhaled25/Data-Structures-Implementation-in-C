//
// Created by Blu-ray on 8/27/2023.
//

#include "doubly_linked_list.h"

retState_t createLinkedList (node_t **headRef, node_t **tailRef,u32int numNodes, ...)
{
    retState_t retVal = R_NOK;
    u32int counter;
    va_list args;

    va_start(args, numNodes);

    if (NULL != headRef)
    {
        *headRef = (node_t *) malloc(sizeof(node_t));
        (*headRef)->nextNode = NULL;
        (*headRef)->prevNode = NULL;
        (*headRef)->data = va_arg(args, u32int);
        *tailRef = *headRef;
        retVal = R_OK;

        if (NULL != *headRef)
        {
            for (counter = 1; counter < numNodes; ++counter)
            {
                retVal = addAtEnd(tailRef, va_arg(args, u32int));

                if (R_NOK == retVal)
                {
                    destroyLinkedList(headRef);
                    break;
                }
            }
        }
    }

    va_end(args);
    return retVal;
}

retState_t destroyLinkedList(node_t **headRef)
{
    retState_t retVal = R_NOK;
    node_t *nextNode = NULL;

    if ((NULL != headRef) && (NULL != *headRef))
    {
        if (NULL == (*headRef)->prevNode)
        {
            while (*headRef) {
                nextNode = (*headRef)->nextNode;
                free(*headRef);
                *headRef = nextNode;
            }

            retVal = R_OK;
        }
    }

    return retVal;
}

void displayLinkedList(node_t *head)
{
    node_t *currentNode = NULL;
    u32int counter = 1;

    if (NULL != head)
    {
        currentNode = head;
        printf("==================\n");
        while (NULL != currentNode)
        {
            printf("Node[%u]: %u\n", counter++, currentNode->data);
            currentNode = currentNode->nextNode;
        }
        printf("==================\n");
    }
    else
    {
        printf("List is empty !\n");
    }
    printf("\n");

}

u32int countNodes(node_t *head)
{
    node_t *currentNode = NULL;
    u32int counter = 0;

    if (NULL != head)
    {
        if (NULL == head->prevNode)
        {
            currentNode = head;
            while (currentNode)
            {
                counter++;
                currentNode = currentNode->nextNode;
            }
        }
    }

    return counter;
}

retState_t addAtBeg (node_t **headRef, u32int data)
{
    retState_t retVal = R_NOK;
    node_t *newNode = NULL;

    if ((NULL != headRef) && (NULL != *headRef))
    {
        if (NULL == (*headRef)->prevNode)
        {
            newNode = (node_t *) malloc(sizeof(node_t));
            if (NULL != newNode) {
                newNode->data = data;
                newNode->prevNode = NULL;
                newNode->nextNode = *headRef;
                (*headRef)->prevNode = newNode;
                *headRef = newNode;

                retVal = R_OK;
            }
        }
    }

    return retVal;
}

retState_t addAtEnd (node_t **tailRef, u32int data)
{
    retState_t retVal = R_NOK;
    node_t *newNode = NULL;

    if ((NULL != tailRef) && (NULL != *tailRef))
    {
        if (NULL == (*tailRef)->nextNode)
        {
            newNode = (node_t *) malloc(sizeof(node_t));
            if (NULL != newNode) {
                newNode->data = data;
                newNode->prevNode = *tailRef;
                newNode->nextNode = NULL;
                (*tailRef)->nextNode = newNode;
                *tailRef = newNode;

                retVal = R_OK;
            }
        }
    }

    return retVal;
}

retState_t insertNode(node_t **headRef, node_t **tailRef, u32int pos, u32int data)
{
    retState_t retVal = R_NOK;
    u32int numNodes = countNodes(*headRef), counter = 1;
    node_t *currentNode = NULL;
    node_t *newNode = NULL;

    if (NULL != headRef && NULL != tailRef)
    {
        if (NULL != *headRef && NULL != *tailRef)
        {
            if (NULL == (*headRef)->prevNode && NULL == (*tailRef)->nextNode)
            {
                if (pos > (numNodes + 1) || pos < 1)
                {
                    retVal = R_NOK;
                }
                else if (pos == (numNodes + 1))
                {
                    addAtEnd(tailRef, data);
                    retVal = R_OK;
                }
                else if (1 == pos)
                {
                    addAtBeg(headRef, data);
                    retVal = R_OK;
                }
                else
                {
                    currentNode = *headRef;
                    while ((++counter) != pos)
                        currentNode = currentNode->nextNode;

                    newNode = (node_t *) malloc(sizeof(node_t));
                    newNode->data = data;

                    newNode->nextNode = currentNode->nextNode;
                    newNode->prevNode = currentNode;
                    (currentNode->nextNode)->prevNode = newNode;
                    currentNode->nextNode = newNode;

                    retVal = R_OK;
                }
            }
        }
    }

    return retVal;
}

retState_t delFirstNode(node_t **headRef)
{
    retState_t retVal = R_NOK;

    if (NULL != headRef)
    {
        if (NULL != *headRef)
        {
            if (NULL == (*headRef)->prevNode)
            {
                *headRef = (*headRef)->nextNode;
                free((*headRef)->prevNode);
                (*headRef)->prevNode = NULL;

                retVal = R_OK;
            }
        }
    }

    return retVal;
}

retState_t delLastNode(node_t **tailRef)
{
    retState_t retVal = R_NOK;

    if (NULL != tailRef)
    {
        if (NULL != *tailRef)
        {
            if (NULL == (*tailRef)->nextNode)
            {
                *tailRef = (*tailRef)->prevNode;
                free((*tailRef)->nextNode);
                (*tailRef)->nextNode = NULL;

                retVal = R_OK;
            }
        }
    }

    return retVal;
}

retState_t delNode(node_t **headRef, node_t **tailRef, u32int pos)
{
    retState_t retVal = R_NOK;
    u32int counter;
    u32int numNodes = countNodes(*headRef);
    node_t *currentNode = NULL;

    if ((NULL != headRef) && (NULL != tailRef))
    {
        if (NULL != *headRef && NULL != *tailRef)
        {
            if (NULL == (*headRef)->prevNode && NULL == (*tailRef)->nextNode)
            {
                if (pos <= numNodes && pos >= 1)
                {
                    if (1 == pos)
                    {
                        delFirstNode(headRef);
                    }
                    else if (numNodes == pos)
                    {
                        delLastNode(tailRef);
                    }
                    else
                    {
                        currentNode = *headRef;
                        for (counter = 1; counter < pos; ++counter)
                        {
                            currentNode = currentNode->nextNode;
                        }
                        currentNode->prevNode->nextNode = currentNode->nextNode;
                        currentNode->nextNode->prevNode = currentNode->prevNode;
                        free(currentNode);
                        currentNode = NULL;
                    }

                    retVal = R_OK;
                }
            }
        }
    }

    return retVal;
}

retState_t reverse(node_t **headRef, node_t **tailRef)
{
    retState_t retVal = R_NOK;
    node_t *currentNode = NULL;
    node_t *prevNode = NULL;

    if ((NULL != headRef) && (NULL != tailRef))
    {
        if (NULL != *headRef && NULL != *tailRef)
        {
            if (NULL == (*headRef)->prevNode && NULL == (*tailRef)->nextNode)
            {
                currentNode = *headRef;
                *headRef = *tailRef;
                *tailRef = currentNode;

                while (currentNode)
                {
                    prevNode = currentNode->prevNode;
                    currentNode->prevNode = currentNode->nextNode;
                    currentNode->nextNode = prevNode;
                    currentNode = currentNode->prevNode;
                }

                retVal = R_OK;
            }
        }
    }

    return retVal;
}