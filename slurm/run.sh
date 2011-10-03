#!/bin/bash

email="cathcart@tcd.ie"

#first run the slurm c program

final|awk 'FNR>2{print}'>tmp

report=$(python jobs.py)

echo $report|mail -s "Status of Parsons calculations" $email
