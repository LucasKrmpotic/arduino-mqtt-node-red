#!/bin/bash

TOPIC='in'
MAX=1000
TIME=2

for i in $(seq 1 $MAX); do 
    mosquitto_pub -h localhost -t "$TOPIC" -m $i 
    sleep $TIME
done
