#! /usr/bin/env python 

import unittest
from data_structures import LinkedList, Stack, Node

class LinkedListTestCase(unittest.TestCase):
    def setUp(self):
        self.LL1 = LinkedList([1,2,3,4])
        self.LL2 = LinkedList()

    def test_append(self):
        for item in [1,2,3,4]:
            self.LL2.append_node(item)
        l1 = self.LL1.as_list()
        l2 = self.LL2.as_list()
        self.assertEqual(l1, l2)




if __name__ == '__main__':
    unittest.main(verbosity=10)