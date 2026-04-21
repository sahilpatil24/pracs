#!/bin/bash
#Write a shell program to accept Percentage marks (integer) and display the grade. 

read -p "Marks in percentage: " marks

# 90 > A, 80 > B, 70 > C
if [ $marks -gt 90 ] 
then
	echo "A"
elif [ $marks -gt 80 ] 
then
	echo "B"
elif [ $marks -gt 70 ] 
then
	echo "C"
else
	echo "D"
fi