require './node'

# A singly linked list implementation
class SinglyLinkedList
	attr_accessor :head

	def initialize
		@head = nil
	end

	# Adds new element to the end of the singly linked list
	def add(element)
		newNode = Node.new(element)

		if @head.nil?
			@head = newNode
		else
			# Traverses to the end of the linked list
			currentNode = @head
			while !currentNode.next.nil?
				currentNode = currentNode.next
			end

			# Appends new element after currentNode
			currentNode.next = newNode
		end
	end

	# Deletes an element
	def delete(element)
		# Does nothing in empty linked list case
		return if @head.nil?

		# Finds the element before the one that would be removed
		prevNode    = nil
		currentNode = @head
		while !currentNode.nil?
			break if currentNode.data == element
			prevNode    = currentNode
			currentNode = currentNode.next
		end

		# Deletes the node that has the element from linked list, if exists
		return if currentNode.nil?

		if prevNode.nil?
			@head = @head.next
		else
			prevNode.next = currentNode.next
		end
	end

	# Inserts new element after the first node that has the given element
	def insertAfter(newElement, element)
		# Finds the node that has the given element
		currentNode = @head
		while !currentNode.nil?
			break if currentNode.data == element
			currentNode = currentNode.next
		end

		# Inserts new node after that node if found
		if !currentNode.nil?
			newNode = Node.new(newElement, currentNode.next)
			currentNode.next = newNode
		end
	end

	# Inserts new element before the first node that has the given element
	def insertBefore(newElement, element)
		# Finds the node to insert new node after
		prevNode    = nil
		currentNode = @head
		while !currentNode.nil?
			break if currentNode.data == element
			prevNode    = currentNode
			currentNode = currentNode.next
		end

		# Inserts new node after that node, if found
		return if currentNode.nil?
		
		newNode = Node.new(newElement, nil)
		if prevNode.nil?
			newNode.next = @head
			@head = newNode
		else
			newNode.next  = currentNode
			prevNode.next = newNode
		end	
	end

	# Returns a string form of the linked list
	def to_s
		result = ""

		currentNode = @head
		while !currentNode.nil?
			result += currentNode.data.to_s
			result += " " if !currentNode.next.nil?
			currentNode = currentNode.next
		end

		result
	end
end