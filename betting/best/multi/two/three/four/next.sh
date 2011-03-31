for i in `ls`;do
test=`grep "runner up" $i|awk '{print $6}'`
echo $test
if [ $test = "spain" ];then 
cp $i five/$i 
fi
done
