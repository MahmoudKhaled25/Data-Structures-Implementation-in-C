/**
 * @file circular_doubly_linked_list.c
 * @author Mahmoud Khaled
 * @date 2023-09-24
 * 
 */

#include "circular_doubly_linked_list.h"


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
            (*tailRef)->nextNode = *tailRef;
            (*tailRef)->prevNode = *tailRef;

            for (counter = 1; counter < numNodes; ++counter)
            {
                retVal = addAtEnd(tailRef, va_arg(arg, u32int));
                if (R_NOK == retVal)
                {
                    destroyList(tailRef);
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
            previousNode = (*tailRef)->nextNode;
            (*tailRef)->nextNode = NULL;
            do
            {
                currentNode = previousNode->nextNode;
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
        if (NULL != *tailRef && NULL != (*tailRef)->nextNode)
        {
            newNode = (node_t *) malloc(sizeof(node_t));
            if (NULL != newNode)
            {
                retVal = R_OK;

                newNode->data = data;
                newNode->nextNode = (*tailRef)->nextNode;
                newNode->prevNode = *tailRef;

                (*tailRef)->nextNode->prevNode = newNode;
                (*tailRef)->nextNode = newNode;
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
                newNode->nextNode = (*tailRef)->nextNode;
                newNode->prevNode = *tailRef;

                (*tailRef)->nextNode->prevNode = newNode;
                (*tailRef)->nextNode = newNode;
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
                            currentNode = currentNode->nextNode;
                        }
                        newNode->data = data;
                        newNode->nextNode = currentNode->nextNode;
                        newNode->prevNode = currentNode;

                        currentNode->nextNode->prevNode = newNode;
                        currentNode->nextNode = newNode;
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
    node_t *nodeToDelete = NULL;

    if (NULL != tailRef)
    {
        if (NULL != *tailRef)
        {
            nodeToDelete = *tailRef;
            *tailRef = (*tailRef)->prevNode;
            (*tailRef)->nextNode =  nodeToDelete->nextNode;
            nodeToDelete->nextNode->prevNode = *tailRef;
            free(nodeToDelete);
            retVal = R_OK;
        }
    }

    return retVal;
}

retState_t delFirstNode (node_t **tailRef)
{
    retState_t retVal = R_NOK;
    node_t *nodeToDelete = NULL;


    if (NULL != tailRef)
    {
        if (NULL != *tailRef)
        {
            nodeToDelete = (*tailRef)->nextNode;
            (*tailRef)->nextNode = nodeToDelete->nextNode;
            nodeToDelete->nextNode->prevNode = *tailRef;
            free(nodeToDelete);
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
                        currentNode = currentNode->nextNode;
                    }
                    nodeToDelete = currentNode->nextNode;
                    nodeToDelete->nextNode->prevNode = currentNode;
                    currentNode->nextNode = nodeToDelete->nextNode;
                    
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
    node_t *currentNode = NULL, *nextNode = NULL; 

    if (NULL != tailRef)
    {
        if (NULL != *tailRef)
        {
            retVal = R_OK;

            currentNode = (*tailRef)->nextNode;
            *tailRef = (*tailRef)->nextNode;

            do
            {
                nextNode = currentNode->nextNode;
                currentNode->nextNode = currentNode->prevNode;
                currentNode->prevNode = nextNode;
                currentNode = nextNode;
            } while (currentNode != *tailRef);
        }
    }

    return retVal;
}

retState_t sortList(node_t *tail)
{
    retState_t retVal = R_NOK;
    node_t *pivot = NULL, *currentNode = NULL;
    u32int buff;

    if (NULL != tail)
    {
        retVal = R_OK;
        pivot = tail->nextNode;

        do
        {
            pivot = pivot->nextNode;
            currentNode = pivot->prevNode;
            buff = pivot->data;

            do
            {
                if (buff < currentNode->data)
                {
                    currentNode->nextNode->data = currentNode->data;
                    currentNode = currentNode->prevNode;
                }
                else
                {
                    currentNode->nextNode->data = buff;
                    break;
                }

                if (currentNode == tail)
                    currentNode->nextNode->data = buff;

            } while (currentNode != tail);
                
        } while (pivot != tail);
            
            
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
        currentNode = tail->nextNode;

        printf("[  ");
        do
        {
            printf("%u  ", currentNode->data);

            currentNode = currentNode->nextNode;
        }
        while (currentNode != tail->nextNode);
        printf("]\n\n");

    }
}

u32int countNodes(node_t *tail)
{
    node_t *currentNode = NULL;
    u32int counter = 0;

    if (NULL != tail)
    {
        currentNode = tail->nextNode;

        do
        {
            counter++;
            currentNode = currentNode->nextNode;
        } while (currentNode != tail->nextNode);
    }

    return counter;
}