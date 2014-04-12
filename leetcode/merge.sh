#!/bin/sh
file_path=${1}
proc_="${PWD}/detail_leetcode.pl"
echo "started."
while read line
do
    ${proc_} ${line}
done < ${file_path}
echo "completed."
