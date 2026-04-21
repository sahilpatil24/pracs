#fibonacci series using while loop

read -p "Enter n " n

temp=$n
i=0
n1=0
n2=1
n3=0

while [ $i -lt $n ]
do
	echo -n "$n3 "
	n3=$((n1 + n2))
	n1=$n2
	n2=$n3

	i=$((i+1))
done

