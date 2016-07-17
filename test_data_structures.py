#! /usr/bin/env python 

import unittest
from data_structures import LinkedList, Stack, Node, Queue
import random as rnd

class LinkedListTestCase(unittest.TestCase):
    def setUp(self):
        self.arr = [rnd.randint(0,20) for x in xrange(10)]
        self.LL1 = LinkedList(self.arr)
        self.LL2 = LinkedList()
        self.det_ll = LinkedList([1,2,3,4])

    def test_append(self):
        for item in self.arr:
            self.LL2.append_node(item)
        l1 = self.LL1.as_list()
        l2 = self.LL2.as_list()
        self.assertEqual(l1, l2)

    def test_left_append(self):
        l1 = self.LL1.as_list()
        l2 = self.LL2
        for idx in xrange(1, 10):
            l2.append_node(self.arr[idx])

        l2.left_append(self.arr[0])
        self.assertEqual(l1,l2.as_list())

    def test_delete_empty(self):
        ll2 = self.LL2.delete(5)
        self.assertEqual(ll2, None)

    def test_delete_not_found(self):
        ll1_original = self.LL1.as_list()
        ll1_with_del = self.LL1
        ll1_with_del.delete(25)

        self.assertEqual(ll1_original, ll1_with_del.as_list())

    def test_delete_head(self):
        self.LL1.delete(self.arr[0])
        new_ll = LinkedList(self.arr[1:]).as_list()
        self.assertEqual(self.LL1.as_list(), new_ll)

    def test_retrieve_from_end(self):
        n_from_end = self.det_ll.retrieve_from_end(2)
        self.assertEqual(n_from_end.data, 2)


class StackTestCase(unittest.TestCase):
    def setUp(self):
        self.arr = [rnd.randint(0,20) for x in xrange(10)]
        self.st1 = Stack(self.arr)
        self.last_val = self.arr[-1]

    def test_pop_return(self):
        self.assertEqual(self.last_val, self.st1.pop())

    def test_size_after_pop(self):
        size_before_pop = self.st1.size
        self.st1.pop()
        size_after_pop = self.st1.size
        self.assertEqual(size_before_pop - 1, size_after_pop)

    def test_push(self):
        new_val = rnd.randint(20,40)
        self.st1.push(new_val)
        self.assertEqual(self.st1.as_list()[-1], new_val)

    def test_size_after_push(self):
        new_val = rnd.randint(20,40)
        size_before_push = self.st1.size
        self.st1.push(new_val)
        size_after_push = self.st1.size
        self.assertEqual(size_after_push - 1, size_before_push)


class QueueTestCase(unittest.TestCase):
    def setUp(self):
        self.bare_q = Queue()
        self.q2 = Queue([4,5,6])

    def test_dequeue_return(self):
        self.assertEqual(4, self.q2.dequeue())

    def test_dequeue_from_empty(self):
        self.assertEqual(None, self.bare_q.dequeue())

    def test_deq_enq(self):
        val = 5
        self.bare_q.enqueque(val)
        ret = self.bare_q.dequeue()
        self.assertEqual(val, ret)



if __name__ == '__main__':
    unittest.main(verbosity=10)