#include <stdio.h>
#include "queue.h"

void showRetState (retState_t myState);

int main()
{
    queue_t *myQueue;
    u32int myData;
    retState_t retVal;

    // Creating the queue
    myQueue = createQueue(5);
    printf((NULL == myQueue ? "Failed to create" "\n": "Created Successfully" "\n"));
    printf("========================\n");

    // [ 1 ]
    retVal = enqueue(myQueue, 1);
    showRetState(retVal);

    // [ 1 2 ]
    retVal = enqueue(myQueue, 2);
    showRetState(retVal);

    // [ 1 2 3 ]
    retVal = enqueue(myQueue, 3);
    showRetState(retVal);


    // [ . 2 3 ]
    retVal = dequeue(myQueue, &myData);
    printf("Queue Front: %u\n", myData); // Queue Front: 1
    showRetState(retVal);

    // [ . . 3 ]
    retVal = dequeue(myQueue, &myData);
    printf("Queue Front: %u\n", myData); // Queue Front: 2
    showRetState(retVal);

    // [ . . 3 4 ]
    retVal = enqueue(myQueue, 4);
    showRetState(retVal);

    // [ . . 3 4 5 ]
    retVal = enqueue(myQueue, 5);
    showRetState(retVal);

    // [ 6 . 3 4 5 ]
    retVal = enqueue(myQueue, 6);
    showRetState(retVal);

    // [6 . . 4 5 ]
    retVal = dequeue(myQueue, &myData);
    printf("Queue Front: %u\n", myData); // Queue Front: 3
    showRetState(retVal);

    // [6 . . . 5 ]
    retVal = dequeue(myQueue, &myData);
    printf("Queue Front: %u\n", myData); // Queue Front: 4
    showRetState(retVal);

    // [ 6 7 . . 5 ]
    retVal = enqueue(myQueue, 7);
    showRetState(retVal);

    // [ 6 7 8 . 5 ]
    retVal = enqueue(myQueue, 8);
    showRetState(retVal);

    // Checking queue rear
    retVal = queueRear(myQueue, &myData);
    printf("Queue Rear: %u\n", myData); // Queue Rear: 8
    showRetState(retVal);

    // Checking queue front
    retVal = queueFront (myQueue, &myData);
    printf("Queue Front: %u\n", myData); // Queue Front: 5
    showRetState(retVal);

    // [ 6 7 8 9 5 ]
    retVal = enqueue(myQueue, 9);
    showRetState(retVal);

    retVal = queueRear(myQueue, &myData);
    printf("Queue Rear: %u\n", myData); // Queue Rear: 9
    showRetState(retVal);

    // [ 6 7 8 9 . ]
    retVal = dequeue(myQueue, &myData);
    printf("Queue Front: %u\n", myData); // Queue Front: 5
    showRetState(retVal);

    // [ . 7 8 9 . ]
    retVal = dequeue(myQueue, &myData);
    printf("Queue Front: %u\n", myData); // Queue Front: 6
    showRetState(retVal);

    // [ . . 8 9 . ]
    retVal = dequeue(myQueue, &myData);
    printf("Queue Front: %u\n", myData); // Queue Front: 7
    showRetState(retVal);

    // [ . . . 9 . ]
    retVal = dequeue(myQueue, &myData);
    printf("Queue Front: %u\n", myData); // Queue Front: 8
    showRetState(retVal);

    // [ . . . . . ]
    retVal = dequeue(myQueue, &myData);
    printf("Queue Front: %u\n", myData); // Queue Front: 9
    showRetState(retVal);

    // [ . . . . . ]
    retVal = dequeue(myQueue, &myData);
    printf("Queue Front: %u\n", myData); // It will fail
    showRetState(retVal);

    // [ 0 . . . . ]
    retVal = enqueue(myQueue, 0);
    showRetState(retVal);

    // Destroying the queue
    retVal = destroyQueue(myQueue);
    showRetState(retVal);

    return 0;
}

void showRetState (retState_t myState)
{
    printf("Return Status: %s\n", R_OK == myState ? "Success" : (R_NOK == myState ? "Failed" : "Undefined"));
    printf("========================\n");
}