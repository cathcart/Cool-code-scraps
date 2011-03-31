for i in `ls`;do
test=`tail -n2 $i|awk 'NF>1{print $5}'`
if [ $test = "germany" ];then 
cp $i three/$i 
fi
done
