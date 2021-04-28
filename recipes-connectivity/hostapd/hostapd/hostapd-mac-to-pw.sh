#!/bin/bash
DEV=$1
MAC=`cat /sys/class/net/${DEV}/address|tr -d ':'`
# Change name a password for accesspoint
/bin/sed -e "s/@NAME@/vcoach-${MAC:6:12}/" -e "s/@PASSWORD@/visioncoach${MAC:8:12}/" -i @SYSCONFDIR@/hostapd.conf
