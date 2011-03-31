#!/bin/bash

files=`ls`

for i in $files;do
	test=`tail -n1 $i`
	echo $test
	echo $1
	if [ $test = $1 ];then
		cp $i runner_up/$i
	fi
done
