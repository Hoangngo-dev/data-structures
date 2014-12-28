# Implementation of a node in Ruby
# A Node has data and a reference to another Node
class Node
	attr_accessor :data, :next

	def initialize(data = nil, nextNode = nil)
		@data = data
		@next = nextNode
	end
end