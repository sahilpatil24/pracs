#!/bin/bash
#Write a shell program to print the multiplication table of number n.

read -p "Enter n: " n

echo $n

i=1
max=11
mul=0
while [ $i -lt $max ]
do
	mul=$((n*i))
	echo "$n x $i = $mul"
	i=$((i + 1)) 
done
