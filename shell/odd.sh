#!/bin/bash
#sum of first n odd numbers

read -p "Enter n: " n
i=1
sum=0
while [ $n -gt 0 ]
do
	sum=$((sum + i))
	i=$((i + 2))
	n=$((n - 1	))
done

echo $sum