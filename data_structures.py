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



class Heap(object):
    """ Implementing priority queue as a binary heap. The main property of a min or max heap is that each key is the smaller/greater (respectively) or equal to the keys in all his children. Max-heap has the greatest element at the top, min-heap lowest element at the top
    Usage:
    Heap(1, [1,3,4]) - makes a max-heap from [1,3,4]
    Heap(0, [2,3,1]) - makes a min-heap from [2,3,1]
 """    
    def __init__(self, max_or_min, arr=None):
        self.heaparray = []
        self.size = 0
        self.max_or_min = max_or_min # max-heap 1, min-heap 0
        if arr:
            for item in arr:
                self.push(item)


    def items(self):
        return self.heaparray


    def top(self):
        """ Shows the value currently at the top of the heap without popping it off"""
        return self.heaparray[0]


    def push(self, value):
        """ One of the main methods of Heap class. Given a value, push it onto the Heap and make sure it keeps the heap property, where the parent of every subtree is the greatest/smallest element (max-heap/min-heap) in the subtree """
        self.heaparray = self.heaparray + [value]
        self.size += 1
        if self.size == 1:
            return
        else:
            self.percolate_up()


    def pop(self):
        """ Another important method of the class - pops (removes and returns) the top element of the heap and rebalances it. First pop the top element, then add the last element of the heap to the top and move it down as much as possible """
        # deal with simple cases - heap of 0 or 1 elements
        print "working with {}".format(self.heaparray)
        if not self.size:
            print "ERROR. Empty heap - nothing to return"
            return
        # whatever happens you are popping off the first element
        ret = self.heaparray[0]
        if self.size == 1:
            self.size = 0
            self.heaparray = []
            return ret
        # pops the element of the end of the array and moves it to the beginning  
        self.heaparray.insert(0, self.heaparray.pop(-1))
        print "popped {} from {}".format(ret, self.heaparray)
        self.percolate_down(0)
        return ret


    def cmp_func(self, new_item, parent):
        """ Internal compare function: looks up the self.max_or_min value to choose, which way to compare new_item and parent in percolate_up and percolate_down funcs.
        return True if comparison works, False otherwise """
        if self.max_or_min == 1:
            if new_item > parent:
                return True
            else:
                return False
        else:
            if new_item < parent:
                return True
            else:
                return False


    def percolate_down(self, start_parent_idx=0):
        """ Helper func for self.pop. Takes the heap after with the top has been removed. 
Moves the last element to the (temporary) top of the heap and then compare it to children to move it down as much as possible. 
Comparison funcs - if self.max_or_min == 1
 """
        parent_idx = start_parent_idx
        parent = self.heaparray[parent_idx]
        children = [] # list of tuples of format (child_item, child_idx)
        left_child_idx = 2*parent_idx + 1
        right_child_idx = 2*parent_idx + 2

        try:
            left_child = self.heaparray[left_child_idx]
        except IndexError:
            pass
        else:
            children.append((left_child, left_child_idx))            

        try:
            right_child = self.heaparray[right_child_idx]
        except IndexError:
            pass            
        else:
            children.append((right_child, right_child_idx))

        while children:
            for child in children:
                if self.cmp_func(child, parent):
                    self.heaparray[parent_idx] = child[0] 
                    # new value at parent_idx
                    self.heaparray[child[1]] = parent
                    new_idx = child[1]
                    self.percolate_down(new_idx)

        return


    def percolate_up(self):
        """ Takes the heaparray with a newly added element and percolates it up acording to self.max_or_min. By default, it uses the index of the last item and moves it as high up as possible. 
        if 1, swap if new element greater than parent
        elif 0, swap if new element is less than parent"""
        idx = self.size - 1 # starting idx is the last item of the array
        while idx > -1:
            parent_idx = (idx - 1)/2
            parent = self.heaparray[parent_idx] # zero-based array
            if self.cmp_func(self.heaparray[idx], parent):
                # the compare function calls to self.max_or_min to choose the correct comparison
                print "swapping parent {} with new {}".format(parent, self.heaparray[idx])
                temp = self.heaparray[idx] 
                self.heaparray[idx] = parent
                self.heaparray[parent_idx] = temp
                # swap new_item and parent
                idx = parent_idx # change the idx to new idx
            else:
                break


