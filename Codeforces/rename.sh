#!/bin/bash

files=$(ls | grep Codeforces_)

for i in $files
do
    c=${i:11}
    echo $c
    mv $i $c 
done