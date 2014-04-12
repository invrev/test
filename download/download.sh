#!/bin/sh

input_file=${1}
while read line
do
    wget ${line}
done < ${input_file}
