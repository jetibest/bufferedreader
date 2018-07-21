#!/bin/bash

for i in {1..4}
do
    ./run.sh $i | diff - test.${i}.txt && echo "Test $i: PASS" || echo "Test $i: FAIL"
done
