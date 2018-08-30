SUMMARY = "Python interface for wiringpi - new version"
HOMEPAGE = "https://github.com/Gadgetoid"
LICENSE = "GPL-3.0"

LIC_FILES_CHKSUM = "file://WiringPi/COPYING.LESSER;md5=e6a600fd5e1d9cbde2d983680233ad02"

SRCREV = "620be8c3264ed23a7d45d0a473ffeec3c2a4bc5e"

SRC_URI = "\
	gitsm://github.com/Gadgetoid/WiringPi2-Python.git \
"

S = "${WORKDIR}/git"
B = "${S}"

DEPENDS += "swig-native"
RDEPENDS_${PN} = "wiringpi"
