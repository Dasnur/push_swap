#!/bin/sh

ARG="11 6 4 1 9 7 5 10 2 8 3 0"
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -v $ARG
