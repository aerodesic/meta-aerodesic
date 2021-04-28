LINUX_VERSION ?= "4.18.10"

SRCREV = "d2b2e0421388d5b7acd1cba9bd197ff0ebee95ae"
SRC_URI = " \
    git://github.com/raspberrypi/linux.git;branch=rpi-4.18.y \
    "

#    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch

require linux-raspberrypi-4.inc
