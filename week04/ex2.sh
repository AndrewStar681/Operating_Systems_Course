#!/bin/bash
gcc ex2.c -o ex2

./ex2 &
PAR_PID=$!

for i in {1..5}
    do
        pstree $PAR_PID
done

kill $PAR_PID
