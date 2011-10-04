#!/bin/bash

email="YOUR EMAIL"

#first run the slurm c program

final|awk 'FNR>2{print}'>tmp

report=$(python jobs.py)

echo $report|mail -s "Status of Parsons calculations" $email
