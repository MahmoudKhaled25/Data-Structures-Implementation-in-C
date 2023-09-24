//
// Created by Blu-ray on 9/7/2023.
//

#ifndef QUEUE_ARRAY_BASED_QUEUE_H
#define QUEUE_ARRAY_BASED_QUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include "platform_types.h"

typedef enum retState
{
    R_NOK,
    R_OK
}retState_t;

typedef struct Queue
{
    u32int *data;
    s32int front;
    s32int rear;
    u32int numElements;
    u64int queueSize;
}queue_t;

/**
 * @brief Creates a new queue with the specified size.
 *
 * @param queueSize The maximum number of elements that the queue can hold.
 * @return A pointer to the newly created queue, or NULL if memory allocation fails.
 */
queue_t *createQueue(u64int queueSize);

/**
 * @brief Destroys the specified queue and frees the associated memory.
 *
 * @param queue A pointer to the queue to be destroyed.
 * @return R_OK if the queue is successfully destroyed, otherwise R_NOK.
 */
retState_t destroyQueue(queue_t *queue);

/**
 * @brief Inserts an element into the rear of the queue.
 *
 * @param queue A pointer to the queue.
 * @param data The data to be enqueued.
 * @return R_OK if the data is successfully enqueued, otherwise R_NOK.
 */
retState_t enqueue(queue_t *queue, u32int data);

/**
 * @brief Removes an element from the front of the queue.
 *
 * @param queue A pointer to the queue.
 * @param data A pointer to a variable that will store the dequeued data.
 * @return R_OK if the data is successfully dequeued, otherwise R_NOK.
 */
retState_t dequeue(queue_t *queue, u32int *data);

/**
 * @brief Retrieves the element at the front of the queue without removing it.
 *
 * @param queue A pointer to the queue.
 * @param data A pointer to a variable that will store the front element data.
 * @return R_OK if the front element is successfully retrieved, otherwise R_NOK.
 */
retState_t queueFront(const queue_t *queue, u32int *data);

/**
 * @brief Retrieves the element at the rear of the queue without removing it.
 *
 * @param queue A pointer to the queue.
 * @param data A pointer to a variable that will store the rear element data.
 * @return R_OK if the rear element is successfully retrieved, otherwise R_NOK.
 */
retState_t queueRear(const queue_t *queue, u32int *data);

/**
 * @brief Retrieves the current number of elements in the queue.
 *
 * @param queue A pointer to the queue.
 * @param queueCount A pointer to a variable that will store the queue count.
 * @return R_OK if the queue count is successfully retrieved, otherwise R_NOK.
 */
retState_t getQueueCount(const queue_t *queue, u32int *queueCount);

#endif //QUEUE_ARRAY_BASED_QUEUE_H
