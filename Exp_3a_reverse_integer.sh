#!/bin/bash
# Shell Script to reverse a given digit using a loop

echo "Enter a number:"
read num

reverse=0

while [ $num -gt 0 ]
do
    rem=$(expr $num % 10)    # Get last digit
    reverse=$(expr $reverse \* 10 + $rem)  # Append digit
    num=$(expr $num / 10)    # Remove last digit
done

echo "$reverse"
