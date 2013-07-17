#!/bin/bash
LOG=adc.log
THRESHOLD=2700
VAL=0;
while true
do
    VAL=`gnublin-adcint -c 1 -b`
    if [ $VAL -gt $THRESHOLD ]
    then
	echo "$VAL $(date) !!!!!!!!!!!!!!!!!!!!!!!" | tee -a $LOG
	echo "$VAL $(date)" >> peaks.log
    else
	echo "$VAL $(date)" | tee -a $LOG 
    fi
done

