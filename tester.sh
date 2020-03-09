#!/bin/sh

ARG="19 37 3 25 1 22 35 2 28 24 0 7 16 12 34 10 26 18 17 38 4 13 39 30 9 20 6 23 15 11 31 36 5 29 8 21 32 14 27"
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -v $ARG
