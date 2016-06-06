#! /usr/bin/env python
# implementing a stack


class Node(object):
    """docstring for Node"""
    def __init__(self, data, next=None):
        self.data = data
        self.next = next


class LinkedList(object):
    """docstring for LinkedList"""
    def __init__(self):
        # given an array of numbers, return a linked list of them
        # super(LinkedList, self).__init__()
        self.head = None

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

    def left_append(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def print_list(self):
        node = self.head
        while node:
            print node.data
            node = node.next
        

class Stack(object):
    def __init__(self):
    	self.maxsize = None
    	self.top = None
    	self.items = list()


ll = LinkedList()
ll.append_node(3)
ll.append_node(5)
ll.append_node(7)

ll.print_list()

ll.left_append(4)
ll.print_list()
