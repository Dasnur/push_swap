#!/bin/sh

ARG="459 44 62 288"
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
