#!/bin/bash

#sum of n numbers

read -p "Enter n: " n

i=1
echo $n
while [ $i -lt $n ]
do
	sum=$((i + sum))
	i=$((i + 1))
done
sum=$((sum+n))
echo $sum