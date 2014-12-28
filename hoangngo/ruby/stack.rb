# An implementation of stack
class Stack
	def initialize(elements = [])
		@elements = elements
	end

	# Removes and returns recently added element
	# ------------------------------------------
	# The implementation can be shorten by pop method
	def pop
		lastElement = @elements[-1]
		@elements.delete_at(-1)
		lastElement
	end

	# Adds new elements to the end of the stack and
	# returns an instance of the stack
	def push(element)
		@elements.push(element)
		self
	end

	# Returns the number of elements inside the stack
	def size
		@elements.size
	end
end