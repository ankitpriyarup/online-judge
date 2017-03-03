#!/bin/bash

if [[ $# -eq 0 ]] ; then
    echo 'Need source file as argument'
    exit 1
fi

source_file=$1
prog_name="${source_file%.*}"

for i in {1..10}
do
    echo File $i
    cp $prog_name/I.$i $prog_name.in

    g++ $source_file
    ./a.out

    cp $prog_name.out O.$i
    diff O.$i $prog_name/O.$i
done

rm O.*
