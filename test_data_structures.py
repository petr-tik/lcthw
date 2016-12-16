#! /usr/bin/env python

import unittest
from data_structures import LinkedList, Stack, Node, Queue, Heap
import random as rnd


class LinkedListTestCase(unittest.TestCase):

    def setUp(self):
        self.arr = [rnd.randint(0, 20) for x in xrange(10)]
        self.LL1 = LinkedList(self.arr)
        self.LL2 = LinkedList()
        self.det_ll = LinkedList([1, 2, 3, 4])

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
        self.assertEqual(l1, l2.as_list())

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
        self.arr = [rnd.randint(0, 20) for x in xrange(10)]
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
        new_val = rnd.randint(20, 40)
        self.st1.push(new_val)
        self.assertEqual(self.st1.as_list()[0], new_val)

    def test_size_after_push(self):
        new_val = rnd.randint(20, 40)
        size_before_push = self.st1.size
        self.st1.push(new_val)
        size_after_push = self.st1.size
        self.assertEqual(size_after_push - 1, size_before_push)


class QueueTestCase(unittest.TestCase):

    def setUp(self):
        self.bare_q = Queue()
        self.q2 = Queue([4, 5, 6])

    def test_dequeue_return(self):
        self.assertEqual(4, self.q2.dequeue())

    def test_dequeue_from_empty(self):
        self.assertEqual(None, self.bare_q.dequeue())

    def test_deq_enq(self):
        val = 5
        self.bare_q.enqueque(val)
        ret = self.bare_q.dequeue()
        self.assertEqual(val, ret)


class HeapTestCase(unittest.TestCase):

    def setUp(self):
        self.min_heap = Heap(0)
        self.max_heap = Heap(1)

    def test_items_empty(self):
        """ a newly created heap (min or max) is an empty list """
        self.assertEqual(self.min_heap.items(), [])

    def test_push_to_empty(self):
        """ Pushing a new value to empty always has it go on top """
        val_to_insert = rnd.randint(0, 5)
        self.min_heap.push(val_to_insert)
        self.assertEqual(val_to_insert, self.min_heap.top())

    def test_items_nonempty(self):
        """ the .items() method returns a heaparray after pushing a value """
        self.min_heap.push(10)
        self.assertEqual(self.min_heap.items(), self.min_heap.heaparray)

    def test_size_after_insert(self):
        """ the size attribute of Heap class increments by 1 after pushing """
        size_before_ins = self.min_heap.size
        self.min_heap.push(5)
        self.assertEqual(size_before_ins + 1, self.min_heap.size)

    def test_push_and_pop(self):
        val_to_test = 10
        self.min_heap.push(val_to_test)
        other_vals = [rnd.randint(20, 30) for _ in xrange(5)]
        for val in other_vals:
            self.min_heap.push(val)
        self.assertEqual(val_to_test, self.min_heap.pop())

    def test_pop_rets_top(self):
        """ Heap.pop returns the same value as heap.top before popping """
        top = self.max_heap.top()
        self.assertEqual(top, self.max_heap.pop())

    def test_rebalance_after_pop(self):
        biggest_val = rnd.randint(90, 99)
        second_biggest_val = rnd.randint(80, 89)
        vals = [rnd.randint(0, 15) for _ in xrange(5)] + \
            [biggest_val, second_biggest_val]
        new_max_heap = Heap(1, vals)
        new_max_heap.pop()
        self.assertEqual(second_biggest_val, new_max_heap.top())

    def test_rebalance_after_two_pops(self):
        smallest_val = rnd.randint(0, 9)
        second_smallest_val = rnd.randint(10, 19)
        third_smallest_val = rnd.randint(20, 29)
        random_bigger_vals = [rnd.randint(30, 50) for _ in xrange(5)]
        all_vals = random_bigger_vals + \
            [smallest_val, second_smallest_val, third_smallest_val]
        for item in all_vals:
            self.min_heap.push(item)
        for _ in xrange(2):
            self.min_heap.pop()
        self.assertEqual(third_smallest_val, self.min_heap.top())

    def test_bigger_rises_in_max_heap(self):
        """ The greater random value stays on top when 5 vals added"""
        bigger_val = rnd.randint(30, 50)
        for _ in xrange(5):
            smaller_val = rnd.randint(0, 15)
            self.max_heap.push(smaller_val)
        self.max_heap.push(bigger_val)
        self.assertEqual(bigger_val, self.max_heap.top())

    def test_smaller_rises_in_min_heap(self):
        """ The smaller random value moves to top when 5 greater vals added"""
        smaller_val = rnd.randint(0, 15)
        for _ in xrange(5):
            bigger_val = rnd.randint(30, 50)
            self.max_heap.push(bigger_val)
        self.min_heap.push(smaller_val)
        self.assertEqual(smaller_val, self.min_heap.top())

    def test_percolate_down_only_left_child(self):
        pass

    def test_big_heap(self):
        big = 200
        big2 = 150
        vals = [big, big2] + [rnd.randint(0, 100) for _ in xrange(60)]
        for val in vals:
            self.max_heap.push(val)
        self.assertEqual(big, self.max_heap.pop())
        self.assertEqual(big2, self.max_heap.pop())

if __name__ == '__main__':
    unittest.main(verbosity=10)
