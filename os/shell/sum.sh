#!/bin/bash

#Write a shell program to find sum of digits of entered no.

read -p "Enter the number to find sum of digits: " num

echo $num
sum=0
while [ $num -gt 0 ]
do
	#logic
	digit=$((num % 10))
	sum=$((sum + digit))
	num=$((num / 10))
done

echo $sum
#logic - 23 - 23 % 10 = 3 
