#!/bin/bash
#Write a shell program to find out the factorial of givenno.

read -p "Enter n: " n

# factorial logic
# while I < n
#	fact = fact * I
i=1
fact=n
while [ $i -lt $n ]
do	
	fact=$((fact * i))
	i=$((i + 1))
done

echo $fact


