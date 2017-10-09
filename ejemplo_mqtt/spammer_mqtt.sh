#!/bin/bash

for i in $(seq 1 100); do 
    mosquitto_pub -h localhost -t out -m 100 
    sleep 5
done
