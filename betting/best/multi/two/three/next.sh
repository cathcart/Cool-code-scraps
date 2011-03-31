for i in `ls`;do
test=`grep "runner up" $i|awk '{gsub(/]/,"");print $NF}'`
echo $test
if [ $test = "'cameroon'" ];then 
cp $i four/$i 
fi
done
