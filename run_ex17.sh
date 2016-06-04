#!/bin/bash
set -x
./ex17 db.dat c
./ex17 db.dat s 1 zed zed@zedshaw.com
./ex17 db.dat s 2 frank frank@zedshaw.com
./ex17 db.dat s 3 joe joe@zedshaw.com
./ex17 db.dat s 4 Petr lad@gmail.com
./ex17 db.dat l
./ex17 db.dat d 3
./ex17 db.dat l
./ex17 db.dat g 2
valgrind --leak-check=yes ./ex17 db.dat g 2