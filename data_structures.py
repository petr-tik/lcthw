#! /usr/bin/env python
# implementing a stack


class Node(object):
    """docstring for Node"""
    def __init__(self, data, next=None):
        self.data = data
        self.next = next


class LinkedList(object):
    """LinkedList """
    def __init__(self, arr=None):
        # given an array of numbers, return a linked list of them
        # super(LinkedList, self).__init__()
        self.head = None
        if arr:
            for item in arr:
                self.append_node(item)
    
    def append_node(self, data):
        new_node = Node(data)
        # if empty list, set head to new node
        if self.head is None:
            self.head = new_node
        # otherwise, walk down the list until a node links to nothing and insert there
        else:
            node = self.head
            while node.next != None:
                node = node.next
            node.next = new_node
        # print "Adding {} to the right of the list".format(data)

    def left_append(self, data):
        new_node = Node(data)
        # whatever the current the head is, it will be after the node we are inserting
        new_node.next = self.head
        # after head is linked to new, make the new node head
        self.head = new_node
        # print "Adding {} to the left of the list".format(data)

    def print_list(self):
        node = self.head
        while node:
            print node.data
            node = node.next
        print "end of list"

    def delete(self, value):
        # delete the node with given value
        # walk down the list
        # when value found
        # | prev | -> | found | -> | next |

        # prev's next = found's next
        # 3 special cases
        # empty list
        # deleting the head node
        # no such value in list

        node = self.head
        prev = None
        if node == None:
            print "Empty list cannot delete"
            return None
        elif node.data == value:
            self.head = node.next
            return 

        while node.data != value:
            # if you the value is never in the list
            if node.next == None:
                return None    
            prev = node
            upcoming = node.next
            node = node.next
        prev.next = node.next
        # print "deleted {} from the list".format(value)

    def as_list(self):
        node = self.head
        res = []
        while node:
            res.append(node.data)
            node = node.next
        return res

    def retrieve_from_end(self, N):
        node = self.head
        n_from_end = node
        counter = 1
        while node.next is not None:
            if counter > N:
            # only start keeping track of element N places behind, 
            # after reaching position N+1     
                n_from_end = n_from_end.next
            node = node.next
            counter += 1
        if counter > N:
            return n_from_end
        else:
            return None


class Stack(object):
    """"Implementing a Stack as a LinkedList with a pretty print method"""
    def __init__(self, arr=None):
    	self.head = None
    	self.size = 0
        if arr:
            for item in arr:
                self.push(item)

    def push(self, value):
        """Pushes a value on top of the stack
        returns nothing, just modifies the stack object"""
        new_node = Node(value)
        if self.head == None:
            self.head = new_node
            return

        node = self.head
        while node.next != None:
            node = node.next
        node.next = new_node
        self.size += 1
        
    def pop(self):
        """Pops the value from the top of the stack"""
        if self.head == None:
            print "Stack underflow"
            return
        node = self.head
        for _ in xrange(self.size):
            prev = node # keep track of current
            node = node.next
        prev.next = None # make it the new top
        val = node.data # get the value
        self.size -= 1 # reduce the size
        return val

    def as_list(self):
        """ Returns the Stack as a list, where the head is at the start of the list"""
        node = self.head
        res = []
        while node.next != None:
            res.append(node.data)
            node = node.next
        res.append(node.data)
        return res

    def print_stack(self):
        """returns nothing, pretty prints the stack with comments"""
        node = self.head
        counter = 0
        stack_values = []
        while node.next != None:
            stack_values.append(node.data)
            counter += 1
            node = node.next
        stack_values.append(node.data) # append the last one
        print stack_values[counter], "<- top value" # print it with an arrow
        print "|"
        for idx in xrange(counter - 1, -1, -1):
            print stack_values[idx] # print stack values from the end of the array
            if idx == 0:
                break
            print "|"


class Queue(object):
    def __init__(self, arr=None):
        """Implementing a queue with a list and a head index
        The dynamic nature of python allows me to keep growing the list and operate with indices
        """
        self.size = 0
        self.head = -1 
        self.items = []
        if arr:
            for item in arr:
                self.enqueque(item)

    def enqueque(self, value):
        """Adds a value to the back of the queue""" 
        self.items.append(value)
        self.size += 1
        if self.head == -1:
            self.head = 0

    def dequeue(self):
        """ Pops (Returns and removes) the head of queue """
        if self.size == 0:
            print "Error: empty queue"
            return
        
        temp = self.head
        self.head += 1 # go up to the next index
        self.size -= 1
        return self.items[temp]
