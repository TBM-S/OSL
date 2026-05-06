#!/bin/bash
read -p "Enter first number: " num1
read -p "Enter operator (+, -, *, /): " op
read -p "Enter second number: " num2

case $op in
    +) echo "Result: $num1 + $num2 = $(echo "$num1 + $num2" | bc)" ;;
    -) echo "Result: $num1 - $num2 = $(echo "$num1 - $num2" | bc)" ;;
    \*) echo "Result: $num1 * $num2 = $(echo "$num1 * $num2" | bc)" ;;
    /)
        [ "$num2" -eq 0 ] && echo "Error: Division by zero!" || echo "Result: $num1 / $num2 = $(echo "scale=2; $num1 / $num2" | bc)"
        ;;
    *) echo "Error: Invalid operator!" ;;
esac
