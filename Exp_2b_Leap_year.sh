#!/bin/bash
# Shell Script to check if a given year is a leap year

echo "Enter a year:"
read year

# Check if year is divisible by 400 (leap year)
if [ $(($year % 400)) -eq 0 ]
then
    echo "$year is a leap year."
# Check if year is divisible by 100 (not a leap year)
elif [ $(($year % 100)) -eq 0 ]
then
    echo "$year is not a leap year."
# Check if year is divisible by 4 (leap year)
elif [ $(($year % 4)) -eq 0 ]
then
    echo "$year is a leap year."
# Otherwise, not a leap year
else
    echo "$year is not a leap year."
fi
