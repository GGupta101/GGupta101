#!/bin/sh
gcc lab8_FIFO.c -o FIFO ;
gcc lab8_LRU.c -o LRU ;
gcc lab8_SecondChance.c -o SecondChance ;
for i in 10 50 100 150 200 250 300 350 400 450 500
do
	cat accesses.txt | ./FIFO $i
	cat accesses.txt | ./LRU $i
	cat accesses.txt | ./SecondChance $i
done
