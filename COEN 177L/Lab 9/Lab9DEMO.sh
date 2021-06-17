#!/bin/bash 
gcc step1.c -o Step1 ;
gcc step2.c -o Step2 ;
gcc step3.c -o Step3 ;
gcc step4.c -o Step4 -lpthread;
echo "Demo 1:"
echo "----1.1"
time ./Step1 file1.txt
echo "----1.2"
time ./Step1 file2.txt
echo " "
echo "Demo 2:"
echo "----2.1"
time ./Step2 file1.txt 20000
echo "----2.2"
time ./Step2 file2.txt 20000
echo " "
echo "Demo 3:"
echo "----3.2" 
time ./Step3 file2.txt 20000
echo "----3.3"
time ./Step3 file3.txt 20000
echo " "
echo "Demo 4:"
echo "----4.3 20000 2"
time ./Step4 file3.txt 20000 2
echo "----4.3 20000 4"
time ./Step4 file3.txt 20000 4
echo "----4.3 40000 2"
time ./Step4 file3.txt 40000 4



