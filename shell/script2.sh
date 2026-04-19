#!/bin/bash

read -p "Enter the Armstrong number to verify" num

temp=$num
sum=0

while [ $num -gt 0 ]
do
	digit=$((num % 10))
	sum=$((sum + digit * digit * digit))
	num=$((num / 10))
done

if [ $sum -eq $temp ]
then 
	echo "equal"
else
	echo "not equal"
fi