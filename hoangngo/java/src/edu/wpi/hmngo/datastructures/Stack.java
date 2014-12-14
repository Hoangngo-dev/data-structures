package edu.wpi.hmngo.datastructures;


/**
 * File: Stack.java
 * @author hmngo
 * ----------------
 * Implementation of a stack using array
 */
public class Stack<T> {
	/* -------------------- Constants -------------------- */
	private static final int INIT_STACK_SIZE = 4;
	
	
	/* ---------------- Instance variables --------------- */
	private T[] elements;
	private int top;
	
	
	/* ------------------- Constructors ------------------ */
	/**
	 * Constructs an empty stack
	 */
	public Stack() {
		this(INIT_STACK_SIZE);
	}
	
	/**
	 * Constructs a stack with given length
	 * @param size Length of the stack
	 */
	@SuppressWarnings("unchecked")
	public Stack(int size) {
		this.elements = (T[]) new Object[INIT_STACK_SIZE];
		this.top = -1;
	}
	
	
	/* -------------------- Public methods --------------- */
	/**
	 * Puts a new element at the end of the stack
	 * @param newElement New element
	 */
	public void push(T newElement) {
		if (top == this.elements.length) {
			resize(this.elements.length * 2);
		}
		
		this.elements[++top] = newElement;
	};
	
	/**
	 * Returns an element at the end of the stack
	 * @return Returns an element at the end of the stack 
	 */
	public T pop() {
		// prevents popping empty stack
		if (isEmpty()) return null;
		
		T lastElement = this.elements[top];
		this.elements[top--] = null;
		
		// resize the stack if it's size is less than 1/4
		if (top > 0 && top < this.elements.length / 4) {
			resize(this.elements.length / 2);
		}
		
		return lastElement;
	};
	
	/**
	 * Returns true if the stack has no elements
	 * @return Returns true if the stack has no elements
	 */
	public boolean isEmpty() {
		return top == -1;
	};
	
	
	/* ------------------ Private methods ---------------- */
	/*
	 * Resizes the array to the given length
	 */
	private void resize(int newLength) {
		@SuppressWarnings("unchecked")
		T[] temp = (T[]) new Object[newLength];
		
		for (int i = 0; i < this.elements.length; i++) {
			temp[i] = this.elements[i];
		}
		
		this.elements = temp;
	}
}
