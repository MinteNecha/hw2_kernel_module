#!/bin/bash
read -p "Enter your student number: " std_num
read -p "Enter your names: " value1
read -p "Enter your surname: " value2
read -p "Enter your age: " value3
sudo insmod hw2.ko studentnumber="$std_num" names="$value1" surname="$value2" age="$value3"
sudo dmesg | tail -n 7
sudo rmmod hw2 
sudo dmesg | tail -n -1
