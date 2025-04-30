#!/bin/bash
# Shell Script to perform basic calculator operations

echo "Enter first number:"
read a
echo "Enter second number:"
read b

echo "Select operation:"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"

read choice

case $choice in
    1) result=$(expr $a + $b)
       echo "Result of addition: $result"
       ;;
    2) result=$(expr $a - $b)
       echo "Result of subtraction: $result"
       ;;
    3) result=$(expr $a \* $b)
       echo "Result of multiplication: $result"
       ;;
    4) if [ $b -ne 0 ]
       then
           result=$(expr $a / $b)
           echo "Result of division: $result"
       else
           echo "Error: Division by zero is not allowed."
       fi
       ;;
    *) echo "Invalid choice."
       ;;
esac
