#!/bin/sh

ARG="16 15 10 9 1 7 5 3 18 8 13 2 6 11 0 12 14 4 17"
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -v $ARG
