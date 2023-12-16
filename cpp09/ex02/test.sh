#!/bin/bash

test=0

if [ -f log.txt ]
then
    rm log.txt
fi

run()
{
    test=$((test+1))
    echo "Test $test: $1 elements"
    for i in `seq 1 $2`
    do
        ARG=`seq -w 1 10000 | shuf -n $1 | paste -s -d ' '`
        output=`./PmergeMe $ARG`
        if echo $output | grep -q "Error"
        then
            echo "KO"
            echo $ARG >> log.txt
            echo -e "\n" >> log.txt
            return
        fi
    done
    echo -e "OK\n"
}

run 1 300
run 10 300
run 100 300
run 1000 200
run 3000 100
run 10000 20