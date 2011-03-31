#!/bin/bash

months=`seq 1 12`
years=`seq 1901 2000`
for year in  $years ;do
for month in $months;do
cal $month $year |awk 'BEGIN{line=0}{line+=1;if(line==3){print NF}}'
done
done
