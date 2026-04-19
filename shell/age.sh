#!/bin/bash

read -p "Enter your age: " age

if [ $age -ge 18 ]
then 
	echo -n "eligible"
else
	echo -n "not eligible"
fi 