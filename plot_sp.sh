#! /bin/bash
 for i in $(ls *-sp-*.txt); do
   echo $i
   sp=$(echo $i|awk '{gsub(/.txt/,"")gsub(/mA/,"");print}'|awk 'BEGIN{FS = "-" }{for (i=3; i<NF+1; i++){print $i}}')
   OUTFILE=$(basename $i .txt)

   t=2 
   PLOT="p '$i' u 1:$t w l title \"$(echo $sp|awk '{print $1}') mA\" "
   #echo $PLOT
   line=$(echo $sp|awk '{print $1}')
   for j in $(echo $sp|awk '{for(k=2;k<NF+1;k++){print $k}}');do
     t=$(($t+2))
     echo $(head -n1 $i|awk -v t=$t '{print $t}')
     PLOT=$PLOT", '$i' u 1:$t w l title \"$j mA\" "
   done
   #echo $PLOT
  
 cat > plot.gnu << EOF
 set term png
 set output "$OUTFILE.png"
 set title "$OUTFILE"
 
 set xlabel "Wavelength (nm)"
 set ylabel "Output power (dBm)"

 $PLOT
EOF
 gnuplot plot.gnu
 done
 rm plot.gnu
