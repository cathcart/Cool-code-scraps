#!/bin/bash

for i in `ls out*[0-9]`;do
	awk 'NF>1{gsub(/-/," ");print}' $i>tmp
	mv tmp $i
done
