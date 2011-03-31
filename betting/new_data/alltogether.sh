#!/bin/bash

>all_data

for i in `ls out*`;do
echo $i
python group_data.py $i>>all_data
done
