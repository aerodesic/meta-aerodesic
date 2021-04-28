#!/bin/bash
DEV=$1
/usr/sbin/iw phy phy0 interface add ${DEV} type __ap
# Disable power down on both interfaces (probably only need to do wlan0...)
/usr/sbin/iw dev ${DEV} set power_save off
/usr/sbin/iw dev wlan0 set power_save off
sleep 5
# Recycle the devices so they start in the correct order
ip link set wlan0 down
ip link set ap0 down
ip link set ap0 up
ip link set wlan0 up
