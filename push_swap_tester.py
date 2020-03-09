import sys
import subprocess
from random import sample

def make_bash(a,b,n):
	samp = sample(range(a,b,1),n)
	samp =' '.join(str(item) for item in samp)
	with open('tester.sh','w') as f:
		f.writelines('#!/bin/sh')
		f.writelines('\n')
		f.writelines('\n')
		f.writelines(f'ARG="{samp}"')
		f.writelines('\n')
		f.writelines('./push_swap $ARG | wc -l')
		f.writelines('\n')
		f.writelines('./push_swap $ARG | ./checker $ARG')
		f.writelines('\n')


if __name__ == '__main__':
	a = int(sys.argv[1])
	b = int(sys.argv[2])
	n = int(sys.argv[3])
	k = int(sys.argv[4])
	for i in range(k):
		make_bash(a,b,n)
		subprocess.call(['./tester.sh'])
