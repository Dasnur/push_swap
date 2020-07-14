#!/bin/sh

ARG="23 15 5 0 28 12 21 17 22 4 27 20 26 13 29 9 7 14 11 10 3 24 16 1 25 19 8 6 18"
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -v $ARG
