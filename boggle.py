#! /usr/bin/env python3


"""
Solve boogle, given a 4x4 grid of letters and a dictionary, return the list of
words that you can make from letters.

Choosing letters:
 * diagonal edges between nodes are allowed
 * no cycles

"""

import operator

"""
z m h t
z z z i
b z t r
a l g o
"""
test_grid = [["a", "l", "g", "o"], ["b", "z", "t", "r"],
             ["z", "z", "z", "i"], ["z", "m", "h", "t"]]


test_matrix = [[0 for _ in range(4)] for _ in range(4)]

test_dict = ["algorithm", "a"]


def get_dict_to_line(idx):
    res = []
    while idx > 0:
        for line in open("/usr/share/dict/british-english"):
            res.append(line.strip())
            idx -= 1
    return res

b_index = 21156


def my_add(tup1, tup2):
    return (tup1[0] + tup2[0], tup1[1] + tup2[1])


def in_range(tup):
    for item in tup:
        if item not in range(4):
            return False
    return True


def legal_child_coordinates(progress_matrix, point):
    """
    Input:
        progress_matrix - bitmap of same dimensionality
            1 for already or currently visited Node, 0 - free node
        point - a Tuple of the (x, y) format
    return an array of allowed child coordinates (tuples)
    """
    dimension = 4
    allowed_range = (dimension - 1, dimension - 1)
    options = [(0, 1), (1, 0), (-1, 0), (0, -1),
               (1, 1), (1, -1), (-1, 1), (-1, -1)]
    points = [point for _ in range(8)]
    unfiltered = map(my_add, points, options)
    filtered = filter(in_range, unfiltered)
    return filtered


def get_char(matrix, coord):
    """ Given a tuple of coordinates, return the char """
    return matrix[coord[0]][coord[1]]


def update_progress(progress_matrix, point):
    new_matrix = progress_matrix
    new_matrix[point[0]][point[1]] = 1
    return new_matrix


def prepare_dictionary():
    """ Takes a dictionary of words, returns a dictionary:
    key - prefix
    value - 
            1 - prefix only

    """


def check_dictionary()


def recur_build_word(matrix, point, progress_matrix,
                     dictionary, string_so_far=None, words=None):
    if words == None:
        words = []
    progress_matrix = update_progress(progress_matrix, point)
    if string_so_far == None:
        string_so_far = get_char(matrix, point)
    if string_so_far in dictionary:
        words.append(string_so_far)
    children = legal_child_coordinates(progress_matrix, point)

    for child_coord in children:
        new_string = string_so_far + get_char(matrix, point)
        recur_build_word(matrix, child_coord, progress_matrix,
                         dictionary, new_string, words)
    return words


def solve():
    return recur_build_word(test_grid, (0, 0), test_matrix, test_dict)

print(solve())
