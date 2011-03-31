#!/bin/bash

for i in `seq 1000`;do
python round16.py>multi/file$i
done
