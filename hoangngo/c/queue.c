/*
 * File: queue.c
 * -------------
 * Implementation of a queue
 */

#include "queue.h"
#define INIT_QUEUE_SIZE 4

void QueueNew(queue *q, int elementSize)
{
	q->elementSize = elementSize;
	q->actualNumberOfElements = 0;
	q->maximumNumberOfElements = INIT_QUEUE_SIZE;
	q->elements = malloc(INIT_QUEUE_SIZE * elementSize);

	assert(q->elements != NULL);
}

void QueueDispose(queue *q)
{
	free(q->elements);
}

bool QueueEmpty(const queue *q)
{
	return q->actualNumberOfElements == 0;
}

void Dequeue(queue *q, void *elementAddress)
{
	assert(!QueueEmpty(q));

	const void *sourceAddress;
	
	// copies the address of the first element to elementAddress
	memcpy(elementAddress, q->elements, q->elementSize);

	// updates the address of the first element in the queue
	q->actualNumberOfElements--;
	sourceAddress = (const char *)q->elements + q->elementSize;
	memcpy(q->elements, sourceAddress, q->actualNumberOfElements * q->elementSize);
}

void Enqueue(queue *q, void *elementAddress)
{
	void *destinationAddress;

	if (q->actualNumberOfElements == q->maximumNumberOfElements) {
		q->maximumNumberOfElements *= 2;
		q->elements = realloc(q->elements, q->actualNumberOfElements * q->elementSize);
		assert(q->elements != NULL);
	}

	destinationAddress = (char *)q->elements + q->actualNumberOfElements * q->elementSize;
	memcpy(destinationAddress, elementAddress, q->elementSize);
	q->actualNumberOfElements++;
}