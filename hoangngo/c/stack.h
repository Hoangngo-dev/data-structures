/*
 * File: stack.h
 * -------------
 * An interface for a stack
 */

 #ifndef _STACK_H
 #define _STACK_H

/*
 * Type: stack
 * -----------
 * Type for a stack. It holds all information of a stack
 */
typedef struct {
	void *elements;
	int elementSize;
	int actualNumberOfElements;
	int maximumNumberOfElements;
} stack;

/*
 * Function: StackNew
 * ------------------
 * Initializes an empty stack with maximum number of elements
 * that this stack can hold
 */
void StackNew(stack *s, int elementSize);

/*
 * Function: StackDispose
 * ----------------------
 * Frees all the memory associated with the stack
 */
void StackDispose(stack *s);

/* 
 * Function: StackEmpty
 * --------------------
 * Returns true if a stack has no elements
 */
bool StackEmpty(const stack *s);

/*
 * Function: StackPush, StackPop
 * -----------------------------
 * StackPush puts the element at the end of the stack.
 * StackPop gets the last element out of the stack and
 * put it in the passed argument.
 */
void StackPush(stack *s, const void *elementAddress);
void StackPop(stack *s, void *elementAddress);

 #endif // _STACK_H