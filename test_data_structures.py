#! /usr/bin/env python 

import unittest
from data_structures import LinkedList, Stack, Node
import random as rnd

class LinkedListTestCase(unittest.TestCase):
    def setUp(self):
        self.arr = [rnd.randint(0,20) for x in xrange(10)]
        self.LL1 = LinkedList(self.arr)
        self.LL2 = LinkedList()

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
        pass



if __name__ == '__main__':
    unittest.main(verbosity=10)