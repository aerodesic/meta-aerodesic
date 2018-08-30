SUMMARY = "Python interface for wiringpi"
HOMEPAGE = "https://github.com/WiringPi"
LICENSE = "GPL-3.0"

LIC_FILES_CHKSUM = "file://LICENSE.txt;md5=e6a600fd5e1d9cbde2d983680233ad02"

SRCREV = "08cf3e43c12ea1f38ffcb01daccfa5d20b8354b0"
SRC_URI = "\
	gitsm://github.com/WiringPi/WiringPi-Python.git	\
"

S = "${WORKDIR}/git"
B = "${S}"

DEPENDS += "swig-native"
RDEPENDS_${PN} = "wiringpi"
