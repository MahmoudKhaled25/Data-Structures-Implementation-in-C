//
// Created by Blu-ray on 8/20/2023.
//

#include "single_linked_list.h"

retState_t destroyLinkedList(node_t **headNodeRef)
{
    node_t *nextNode = NULL;
    retState_t retVal = R_NOK;

    if(NULL != headNodeRef && NULL != *headNodeRef)
    {
        while (NULL != *headNodeRef)
        {
            nextNode = (*headNodeRef)->link;
            free(*headNodeRef);
            *headNodeRef = nextNode;
        }
        retVal = R_OK;
    }
    return retVal;
}

u32int countNodes(node_t *const headNode)
{
    s32int numNodes = 0;
    node_t *currentNode = NULL;

    if(NULL != headNode)
    {
        currentNode = headNode;

        while (NULL != currentNode)
        {
            numNodes++;
            currentNode = currentNode->link;
        }
    }

    return numNodes;
}

void printNodesData(node_t *headNode)
{
    node_t *currentNode = NULL;
    u32int counter = 1;

    if(NULL != headNode)
    {
        currentNode = headNode;
        printf("==================\n");
        while (NULL != currentNode)
        {
            printf("Node[%i]: %u\n",counter++, currentNode->data );
            currentNode = currentNode->link;
        }
        printf("==================\n");
    }
    else
    {
        printf("Linked list is empty !\n");
    }
}

retState_t addAtEnd(node_t **tailNodeRef, u32int data)
{
    node_t *newNode = NULL;
    retState_t retVal = R_NOK;


    if(NULL != tailNodeRef && NULL != *tailNodeRef)
    {
            newNode = (node_t *) malloc(sizeof(node_t));
            newNode->link = NULL;
            newNode->data = data;
            (*tailNodeRef)->link = newNode;
            *tailNodeRef = newNode;

            retVal = R_OK;
    }
    return retVal;
}

retState_t addAtBeg(node_t **headNodeRef, u32int data)
{
    node_t *newNode = NULL;
    retState_t retVal = R_NOK;

    if(NULL != headNodeRef)
    {
            newNode = (node_t *) malloc(sizeof(node_t));
            newNode->link = *headNodeRef;
            newNode->data = data;
            *headNodeRef = newNode;
            retVal = R_OK;
    }

    return retVal;
}

retState_t insert(node_t **headNodeRef, node_t **tailNodeRef, u32int pos, u32int data)
{
    node_t *newNode = NULL;
    node_t *currentNode = NULL;
    u32int counter;
    u32int numNodes = countNodes(*headNodeRef);
    retState_t retVal = R_NOK;

    if(NULL != tailNodeRef && NULL != headNodeRef)
    {
        if ((numNodes + 1) < pos)
                retVal = R_NOK;

        else if ((numNodes + 1) == pos)
        {
            addAtEnd(tailNodeRef, data);
            retVal = R_OK;
        }
        else if (1 == pos)
        {
            if (NULL == *headNodeRef && NULL == *tailNodeRef)
            {
                addAtBeg(headNodeRef, data);
                *tailNodeRef = *headNodeRef;
            }
            else
            {
                addAtBeg(headNodeRef, data);
            }
            retVal = R_OK;
        }
        else
        {
            currentNode = *headNodeRef;
            newNode = (node_t *) malloc(sizeof(node_t));
            newNode->data = data;

            for (counter = 1; counter < (pos - 1); ++counter)
            {
                currentNode = currentNode->link;
            }

            newNode->link = currentNode->link;
            currentNode->link = newNode;

            retVal = R_OK;
        }
    }

    return retVal;
}

retState_t delFirstNode(node_t **headNodeRef)
{
    retState_t retVal = R_NOK;
    node_t *tempNode = NULL;
    if(NULL != headNodeRef && NULL != *headNodeRef)
    {
        tempNode = *headNodeRef;
        *headNodeRef = (*headNodeRef)->link;
        free(tempNode);

        retVal = R_OK;
    }
    return retVal;
}


retState_t delLastNode(node_t **headNodeRef, node_t **tailNodeRef)
{
    retState_t retVal = R_NOK;
    node_t *currentNode = NULL;

    if(NULL != headNodeRef && NULL != *headNodeRef)
    {
        if (NULL == (*headNodeRef)->link)
        {
            free(*headNodeRef);
            *headNodeRef = NULL;
            retVal = R_OK;
        }
        else
        {
            currentNode = *headNodeRef;

            while (NULL != currentNode->link->link)
                currentNode = currentNode->link;

            free(currentNode->link);
            currentNode->link = NULL;
            *tailNodeRef = currentNode;
            retVal = R_OK;
        }
    }
    return retVal;
}

retState_t delNode(node_t **headNodeRef, node_t **tailNodeRef, u32int pos)
{
    retState_t retVal = R_NOK;
    u32int counter;
    u32int numNodes = countNodes(*headNodeRef);
    node_t *currentNode = NULL;
    node_t *tempNode = NULL;

    if ((NULL != *headNodeRef) && (NULL != *tailNodeRef) && (NULL != headNodeRef) && (NULL != tailNodeRef))
    {
        if (pos <= numNodes)
        {
            if (1 == pos)
            {
                delFirstNode(headNodeRef);
            }
            else if (numNodes == pos)
            {
                delLastNode(headNodeRef, tailNodeRef);
            }
            else
            {
                currentNode = *headNodeRef;
                for (counter = 1; counter < (pos - 1); ++counter)
                {
                    currentNode = currentNode->link;
                }
                tempNode = currentNode->link;
                currentNode->link = currentNode->link->link;
                free(tempNode);
            }

            retVal = R_OK;
        }
    }


    return retVal;
}

retState_t reverse(node_t **headNodeRef, node_t **tailNodeRef)
{
    retState_t retVal = R_NOK;
    node_t *nextNode = NULL;
    node_t *prevNode = NULL;

    if ((NULL != *headNodeRef) && (NULL != *tailNodeRef) && (NULL != headNodeRef) && (NULL != tailNodeRef))
    {
        *tailNodeRef = *headNodeRef;
        prevNode = *headNodeRef;
        nextNode = (*headNodeRef)->link;
        prevNode->link = NULL;

        while (NULL != nextNode)
        {
            prevNode = *headNodeRef;
            *headNodeRef = nextNode;
            nextNode = nextNode->link;
            (*headNodeRef)->link = prevNode;
        }

        retVal = R_OK;
    }

    return retVal;
}


