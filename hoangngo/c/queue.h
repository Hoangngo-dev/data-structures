/*
 * File: queue.h
 * --------------
 * An interface for a queue
 */

 #ifndef _QUEUE_H
 #define _QUEUE_H

#include <string.h>
#include <stdbool.h>
#include "stdlib.h"
 #include <assert.h>

/*
 * Type: queue
 * -----------
 * Type for a queue. It holds all information of a queue.
 */
typedef struct {
	void *elements;
	int elementSize;
	int actualNumberOfElements;
	int maximumNumberOfElements;
} queue;

/*
 * Function: QueueNew
 * ------------------
 * Initializes an empty queue with no elements
 */
 void QueueNew(queue *q, int elementSize);

 /*
  * Function: QueueDispose
  * ----------------------
  * Frees all memory associated with this queue
  */
void QueueDispose(queue *q);

 /*
  * Function: QueueEmpty
  * --------------------
  * Returns true if the queue is empty 
  */
bool QueueEmpty(const queue *q);

/*
 * Function: Dequeue, Enqueue
 * --------------------------
 * Dequeue removes and returns the first element in the queue.
 * Enqueue adds an element to the end of the queue
 */
void Dequeue(queue *q, void *elementAddress);
void Enqueue(queue *q, void *elementAddress);

 #endif // _QUEUE_H