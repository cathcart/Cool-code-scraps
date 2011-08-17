#! /bin/bash
 for i in $(ls *LIV.txt); do
   echo $i
   OUTFILE=$(basename $i .txt)

 cat > plot.gnu << EOF
 set term png
 set output "$OUTFILE.png"
 set title "$OUTFILE"
 
 set xlabel "Current (mA)"
 set ylabel "Photocurrent (mA)"
 set y2label "Voltage (V)"
 set key bottom right

 p [*:*] [-0.05:*] '$i' u 1:(-10*\$3) w l axis x1y1 title "Photocurrent", '$i' u 1:2 w l axis x1y2 title "Voltage"
EOF
 gnuplot plot.gnu
 done
 rm plot.gnu
