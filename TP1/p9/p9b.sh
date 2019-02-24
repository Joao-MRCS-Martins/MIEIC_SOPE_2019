#!/bin/bash
max = $1
i=1

while [$1 -le $max]
do
    if [$i -lt 10]
    then
        mkdir prob0$i
    else
        mkdir prob$i
    fi
    i =$(i+1)
done
