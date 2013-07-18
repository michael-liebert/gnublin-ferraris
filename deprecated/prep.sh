#!/bin/bash

if [ ! -e /sys/class/gpio/gpio11 ]
    then echo 11 > /sys/class/gpio/export
fi

echo in > /sys/class/gpio/gpio11/direction
echo falling > /sys/class/gpio/gpio11/edge

