#Write a shell program to swap 2 numbers.

read -p "Enter a: " a
read -p "Enter b: " b

#swap now
temp=$a
a=$b
b=$temp

echo "a: $a"
echo "b: $b"

