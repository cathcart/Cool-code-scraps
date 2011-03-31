grep -v "Group" $1|awk '{sub(/[0-9]./,"");gsub("-"," ");if($2~/[a-z]/){printf("%s-%s %f %f %f\n",$1,$2,$3,$7,$8)}else{printf("%s %f %f %f\n",$1,$2,$6,$7)}}'
