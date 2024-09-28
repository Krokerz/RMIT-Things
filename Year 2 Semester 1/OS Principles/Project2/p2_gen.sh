#!/bin/bash

n=$1
min=1
max=512
x=1
y=1
# first 33% as alloc
p=3

first=`echo $(($1 / $p)) |bc -l`

while [ $y -le $first ]
do 
	number=$(expr $min + $RANDOM % $max)
	echo "alloc: $number"
	y=$(( $y + 1 ))
done

while [ $x -le $(( $n - $first)) ]
do
	option=`echo $(($RANDOM%2))`

	if [[ $option -eq 0 ]]
	then 
		number=$(expr $min + $RANDOM % $max)
		echo "alloc: $number"
	else
		echo "dealloc"
	fi
	x=$(( $x + 1 ))
done
