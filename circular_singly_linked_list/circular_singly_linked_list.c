/**
 * @file circular_singly_linked_list.c
 * @author mahmoud Khaled
 * @date 2023-09-24
 * 
 */

#include "circular_singly_linked_list.h"


retState_t createList(node_t **tailRef, u32int numNodes, ...)
{
    va_list arg = NULL;
    retState_t retVal = R_NOK;
    u32int counter;

    va_start(arg, numNodes);

    if (NULL != tailRef && 0 != numNodes)
    {
        *tailRef = (node_t *) malloc(sizeof(node_t));
        if (NULL != *tailRef)
        {
            retVal = R_OK;

            (*tailRef)->data = va_arg(arg, u32int);
            (*tailRef)->link = *tailRef;

            for (counter = 1; counter < numNodes; ++counter)
            {
                retVal = addAtEnd(tailRef, va_arg(arg, u32int));
                if (R_NOK == retVal)
                {

                    break;
                }
            }
        }
    }

    va_end(arg);
    return retVal;
}

retState_t destroyList(node_t **tailRef)
{
    retState_t retVal = R_NOK;
    node_t *currentNode = NULL, *previousNode = NULL;

    if (NULL != tailRef)
    {
        if (NULL != *tailRef)
        {
            previousNode = (*tailRef)->link;
            (*tailRef)->link = NULL;
            do
            {
                currentNode = previousNode->link;
                free(previousNode);
                previousNode = currentNode;
            } while (previousNode != NULL);
            *tailRef = NULL;
            retVal = R_OK;
        }
    }

    return retVal;
}

retState_t addAtBeg(node_t **tailRef, u32int data)
{
    retState_t retVal = R_NOK;
    node_t *newNode = NULL;

    if (NULL != tailRef)
    {
        if (NULL != *tailRef && NULL != (*tailRef)->link)
        {
            newNode = (node_t *) malloc(sizeof(node_t));
            if (NULL != newNode)
            {
                retVal = R_OK;

                newNode->data = data;
                newNode->link = (*tailRef)->link;

                (*tailRef)->link = newNode;
            }
        }
    }

    return retVal;
}

retState_t addAtEnd(node_t **tailRef, u32int data)
{
    retState_t retVal = R_NOK;
    node_t *newNode = NULL;

    if (NULL != tailRef)
    {
        if (NULL != *tailRef)
        {
            newNode = (node_t *) malloc(sizeof(node_t));
            if (NULL != newNode)
            {
                retVal = R_OK;

                newNode->data = data;
                newNode->link = (*tailRef)->link;

                (*tailRef)->link = newNode;
                *tailRef = newNode;
            }
        }
    }

    return retVal;
}

retState_t insert(node_t **tailRef, u32int pos, u32int data)
{
    retState_t retVal = R_NOK, nullCheck = R_OK;
    u32int counter, numNodes = countNodes(*tailRef);
    node_t *currentNode = NULL, *newNode = NULL;

    if (NULL != tailRef)
    {
        if (NULL != *tailRef)
        {
            if (pos >= 1 && pos <= (numNodes+1))
            {
                if (1 == pos)
                    addAtBeg(tailRef, data);

                else if ((numNodes+1) == pos)
                    addAtEnd(tailRef, data);

                else
                {
                    currentNode = *tailRef;
                    newNode = (node_t *) malloc(sizeof (node_t));
                    if (NULL == newNode)
                    {
                        nullCheck = R_NOK;
                    }
                    else
                    {
                        for (counter = 1; counter < pos; ++counter)
                        {
                            currentNode = currentNode->link;
                        }
                        newNode->data = data;
                        newNode->link = currentNode->link;
                        currentNode->link = newNode;
                    }
                }

                if (R_OK == nullCheck)
                {
                    retVal = R_OK;
                }
            }
        }
    }

    return retVal;
}

retState_t delLastNode (node_t **tailRef)
{
    retState_t retVal = R_NOK;
    node_t *currentNode = NULL;

    if (NULL != tailRef)
    {
        if (NULL != *tailRef)
        {
            currentNode = (*tailRef)->link;
            while (currentNode->link != *tailRef)
                currentNode = currentNode->link;

            currentNode->link = (*tailRef)->link;
            free(*tailRef);
            *tailRef = currentNode;

            retVal = R_OK;
        }
    }

    return retVal;
}

retState_t delFirstNode (node_t **tailRef)
{
    retState_t retVal = R_NOK;
    node_t *currentNode = NULL;


    if (NULL != tailRef)
    {
        if (NULL != *tailRef)
        {
            currentNode = (*tailRef)->link;
            (*tailRef)->link = currentNode->link;
            free(currentNode);
            retVal = R_OK;
        }
    }

    return retVal;
}

retState_t delNode (node_t **tailRef, u32int pos)
{
    retState_t retVal = R_NOK;
    u32int counter, numNodes = countNodes(*tailRef);
    node_t *currentNode = NULL, *nodeToDelete = NULL;

    if (NULL != tailRef)
    {
        if (NULL != *tailRef)
        {
            if (pos >= 1 && pos <= numNodes)
            {
                if (1 == pos)
                    delFirstNode(tailRef);

                else if (numNodes == pos)
                    delLastNode(tailRef);

                else
                {
                    currentNode = *tailRef;

                    for (counter = 1; counter < pos; ++counter)
                    {
                        currentNode = currentNode->link;
                    }
                    nodeToDelete = currentNode->link;
                    currentNode->link = nodeToDelete->link;
                    free(nodeToDelete);
                }

                retVal = R_OK;
            }
        }
    }

    return retVal;
}

retState_t reverseList(node_t **tailRef)
{
    retState_t retVal = R_NOK;
    node_t *currentNode = NULL, *prevNode = NULL, *nextNode = NULL; 

    if (NULL != tailRef)
    {
        if (NULL != *tailRef)
        {
            retVal = R_OK;

            prevNode = *tailRef;
            currentNode = prevNode->link;
            nextNode = currentNode->link;
            *tailRef = (*tailRef)->link;

            do
            {
                currentNode->link = prevNode;
                prevNode = currentNode;
                currentNode = nextNode;
                nextNode = currentNode->link;
            } while (currentNode != *tailRef);
        }
    }

    return retVal;
}

void printList(node_t *tail)
{
    node_t *currentNode = NULL;

    if (NULL == tail)
    {
        printf("List is empty!\n\n");
    }
    else
    {
        currentNode = tail->link;

        printf("[  ");
        do
        {
            printf("%u  ", currentNode->data);

            currentNode = currentNode->link;
        }
        while (currentNode != tail->link);
        printf("]\n\n");

    }
}

u32int countNodes(node_t *tail)
{
    node_t *currentNode = NULL;
    u32int counter = 0;

    if (NULL != tail)
    {
        currentNode = tail->link;

        do
        {
            counter++;
            currentNode = currentNode->link;
        } while (currentNode != tail->link);
    }

    return counter;
}


