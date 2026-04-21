#!/bin/bash

read -p "enter n: " n

#to check if number is even or odd
if [ $((n % 2 )) -eq 0 ]
then 
	echo "even"
else
	echo "odd"
fi
