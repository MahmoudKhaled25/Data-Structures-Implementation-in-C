//
// Created by Blu-ray on 9/7/2023.
//

#include "queue.h"

typedef enum queueStatus
{
    EMPTY,
    NOT_EMPTY,
    FULL,
    NOT_FULL
}queueStatus_t;

static queueStatus_t isEmpty (const queue_t *queue);
static queueStatus_t isFull (const queue_t *queue);

static queueStatus_t isEmpty (const queue_t *queue)
{
    return (0 == queue->numElements) ? EMPTY : NOT_EMPTY;
}

static queueStatus_t isFull (const queue_t *queue)
{
    return (queue->queueSize == queue->numElements) ? FULL : NOT_FULL;
}

queue_t *createQueue(u64int queueSize)
{
    queue_t *queue = NULL;

    queue = (queue_t *) malloc(sizeof(queue_t));
    if (NULL != queue)
    {
        queue->data = (u32int *) calloc(queueSize, sizeof(u32int));
        if (NULL != queue->data)
        {
            queue->front = -1;
            queue->rear = -1;
            queue->numElements = 0;
            queue->queueSize = queueSize;
        }
        else
        {
            free(queue);
            queue = NULL;
        }
    }

    return queue;
}

retState_t destroyQueue(queue_t *queue)
{
    retState_t retVal = R_NOK;

    if (NULL != queue)
    {
        free(queue->data);
        free(queue);
        retVal = R_OK;
    }

    return retVal;
}

retState_t enqueue(queue_t *queue, u32int data)
{
    retState_t retVal = R_NOK;

    if (NULL != queue)
    {
        if (NOT_FULL == isFull(queue))
        {
            queue->rear++;

            if (EMPTY == isEmpty(queue))
            {
                queue->front++;
            }
            else
            {
                if (queue->queueSize == queue->rear &&  NOT_FULL == isFull(queue))
                {
                    queue->rear = 0;
                }
            }

            queue->numElements++;
            queue->data[queue->rear] = data;
            retVal = R_OK;
        }

    }

    return retVal;
}

retState_t dequeue(queue_t *queue, u32int *data)
{
    retState_t retVal = R_NOK;

    if (NULL != queue && NULL != data)
    {
        if (NOT_EMPTY == isEmpty(queue))
        {
            *data = queue->data[queue->front++];
            queue->numElements--;

            if (queue->queueSize == queue->front)
            {
                queue->front = 0;
            }

            if (EMPTY == isEmpty(queue))
            {
                queue->front = -1;
                queue->rear = -1;
            }

            retVal = R_OK;
        }
        else
        {
            *data = -1;
        }
    }

    return retVal;
}

retState_t queueFront(const queue_t *queue, u32int *data)
{
    retState_t retVal = R_NOK;
    if (NULL != queue && NULL != data)
    {
        if (NOT_EMPTY == isEmpty(queue))
        {
            *data = queue->data[queue->front];
            retVal = R_OK;
        }
        else
        {
            *data = -1;
        }
    }
    return retVal;
}

retState_t queueRear(const queue_t *queue, u32int *data)
{
    retState_t retVal = R_NOK;
    if (NULL != queue && NULL != data)
    {
        if (NOT_EMPTY == isEmpty(queue))
        {
            *data = queue->data[queue->rear];
            retVal = R_OK;
        }
        else
        {
            *data = -1;
        }
    }
    return retVal;
}

retState_t getQueueCount (const queue_t *queue, u32int *queueCount)
{
    retState_t retVal = R_NOK;

    if (NULL != queue && NULL != queueCount)
    {
        *queueCount = queue->numElements;
        retVal = R_OK;
    }

    return retVal;
}