/*
 * File: stack.c
 * -------------
 * Implementation of stack
 *
 */

#define INIT_ALLOC_SIZE 4;

void StackNew(stack *s, int elementSize)
{
	assert(elementSize > 0);
	s->elementSize = elementSize;
	s->actualNumberOfElements = 0;
	s->maximumNumberOfElements = INIT_ALLOC_SIZE;
	s->elements = malloc(INIT_ALLOC_SIZE * elementSize);
	assert(s->elements != NULL);
}

void StackDispose(stack *s)
{
	free(s->elements);
}

bool StackEmpty(const stack *s)
{
	return s->actualNumberOfElements == 0;
}

void StackPush(stack *s, const void *elementAddress)
{
	void *destinationAddress;

	if (s->actualNumberOfElements == s->maximumNumberOfElements) {
		s->maximumNumberOfElements *= 2;
		s->elements = realloc(s->elements, s->maximumNumberOfElements * s->elementSize);
		assert(s->elements != NULL);
	}

	destinationAddress = (char *)s->elements + s->actualNumberOfElements * s->elementSize;
	memcpy(destinationAddress, elementAddress, s->elementSize);
	s->actualNumberOfElements++;
}

void StackPop(stack *s, void *elementAddress)
{
	const void *sourceAddress;

	assert(!StackEmpty(s));
	s->actualNumberOfElements--;
	sourceAddress = (const char *)s->elements + s->actualNumberOfElements * s->elementSize;
	memcpy(elementAddress, sourceAddress, s->elementSize);
}