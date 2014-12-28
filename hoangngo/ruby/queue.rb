# An implementation of stack using array
class Queue
	def initialize(elements = [])
		@elements = elements
	end

	# Adds new element to the end of the array and
	# returns the queue's internal storage
	def enqueue(element)
		@elements.push(element)
		self
	end

	# Removes and returns the first added element
	def dequeue
		@elements.shift
	end

	# Returns the size of the queue
	def size
		@elements.size
	end

	# Returns true if the stack is empty
	def empty?
		@elements.empty?
	end
end