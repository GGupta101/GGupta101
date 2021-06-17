#!/bin/bash 
gcc step1.c -o Step1 ;
gcc step2.c -o Step2 ;
gcc step3.c -o Step3 ;
gcc step4.c -o Step4 -lpthread;
echo "step 1 testing"
echo " "
echo " "
for file in file1.txt file2.txt file3.txt file4.txt file5.txt; do 
	echo "step1 $file"
	time ./Step1 $file
	echo " "
done
echo " "
echo " "
echo "step 2 testing"
echo " "
echo " "
for file in file1.txt file2.txt file3.txt file4.txt file5.txt; do
	for buffer in 100 1000 10000 100000; do
		echo "step2 $file $buffer"
		time ./Step2 $file $buffer
		echo " "
	done
done
echo " "
echo " "
echo "step 3 testing"
echo " "
echo " "
for file in file1.txt file2.txt file3.txt file4.txt file5.txt; do
        for buffer in 100 1000 10000 100000; do
		echo "step3 $file $buffer"
                time ./Step3 $file $buffer
		echo " "
        done
done
echo " "
echo " "
echo "step 4 testing"
echo " "
echo " "
for file in file1.txt file2.txt file3.txt file4.txt ; do
        for buffer in 100 1000 10000 100000; do
			for thread in 2 8 32 64; do 
                	echo "step4 $file $buffer $thread"
	                time ./Step4 $file $buffer $thread
			echo " "
        	done
	done
done
