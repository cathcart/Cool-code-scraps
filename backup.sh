#!/bin/bash
#BACKUP_DIRECTORY="/media/disk/Backup/"
BACKUP_DIRECTORY="/media/TWSS/Backup/"
TODAYS_BACKUP=$BACKUP_DIRECTORY`date +%a`
DIRECTORY_TO_BACKUP="/home/"$USER
EMERGENCY_BACKUP="/misc/data0/Cathcart/Backup/"
EMAIL="cathcart@tcd.ie"


#this pulls out the last edited directory as a backup
#LAST=`ls -t -l $BACKUP_DIRECTORY|grep ^d|awk '{print $9}'|head -n1`
LAST=`date -d yesterday +%a`
if [ $LAST = "Sun" ]; then
    LAST="Fri"
fi

PREVIOUS_BACKUP=$BACKUP_DIRECTORY$LAST

if [ ! -d $BACKUP_DIRECTORY  ]; then
     echo "Backup drive not mounted" | mail -s "Backup failure" $EMAIL 
     LAST=`ls -t -l $EMERGENCY_BACKUP|grep ^d|awk '{print $9}'|head -n1`
     TODAYS_BACKUP=$EMERGENCY_BACKUP`date +%a`
     PREVIOUS_BACKUP=$EMERGENCY_BACKUP$LAST
fi

# previous-backup source current-backup
rsync -ac --link-dest=$PREVIOUS_BACKUP $DIRECTORY_TO_BACKUP $TODAYS_BACKUP #this is the std local backup
rsync -ac --link-dest=$PREVIOUS_BACKUP/londale lonsdale:/home/tsphy/$USER/ $TODAYS_BACKUP/londale #this is the backup for parsons/londale

echo "Successful backup"|mail -s "Successful backup" $EMAIL
