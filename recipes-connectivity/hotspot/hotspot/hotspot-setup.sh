#!/bin/bash
# If Hotspot doesn't exist, create one.
DEV=$1
if [ ! -e /etc/NetworkManager/system-connections/Hotspot.nmconnection ]; then
   MAC=`cat /sys/class/net/${DEV}/address|tr -d ':'`
   echo DEV=${DEV} MAC=${MAC} >> /home/@PROJECT_USER@/mac.address
   nmcli con add type wifi ifname ap0 con-name Hotspot autoconnect no ssid "@PROJECT_USER@-${MAC:6:12}" mode ap
   nmcli con modify Hotspot 802-11-wireless.mode ap 802-11-wireless-security.key-mgmt wpa-psk ipv4.method shared 802-11-wireless-security.psk "@PROJECT_USER@${MAC:8:12}"
fi
