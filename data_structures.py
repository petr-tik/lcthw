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
        print "Adding {} to the right of the list".format(data)

    def left_append(self, data):
        new_node = Node(data)
        # whatever the current the head is, it will be after the node we are inserting
        new_node.next = self.head
        # after head is linked to new, make the new node head
        self.head = new_node
        print "Adding {} to the left of the list".format(data)

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
        print "deleted {} from the list".format(value)


ll = LinkedList()
ll.append_node(3)
ll.append_node(5)
ll.append_node(7)

ll.print_list()

ll.left_append(4)
ll.print_list()


ll.delete(4)
ll.print_list()

ll1 = LinkedList([12,34,5,6])
ll1.delete(5)
ll1.print_list()


print "Starting stack exercises\n\n\n\n################\n\n"

class Stack(object):
    def __init__(self, arr=None):
    	self.head = None
    	self.size = 0
        if arr:
            for item in arr:
                self.push(item)
                self.size += 1

    def push(self, value):
        new_node = Node(value)
        if self.head == None:
            self.head = new_node
            return

        node = self.head
        while node.next != None:
            node = node.next
        node.next = new_node
        
    # def pop(self, idx = self.size):
    #     for _ in xrange(idx):
    #         pass

    def print_stack(self):
        node = self.head
        counter = 0
        stack_values = []
        while node.next != None:
            stack_values.append(node.data)
            counter += 1
            node = node.next
        stack_values.append(node.data)
        print stack_values[counter], "<- top value"
        print "|"
        for idx in xrange(counter - 1, -1, -1):
            print stack_values[idx]
            if idx == 0:
                break
            print "|"


st = Stack([12,3,4])
st.print_stack()
