SUMMARY = "Python interface for wiringpi"
HOMEPAGE = "https://github.com/WiringPi"
LICENSE = "GPL-3.0"

LIC_FILES_CHKSUM = "file://LICENSE.txt;md5=e6a600fd5e1d9cbde2d983680233ad02"

SRCREV = "08cf3e43c12ea1f38ffcb01daccfa5d20b8354b0"
SRC_URI = "\
	gitsm://github.com/WiringPi/WiringPi-Python.git	\
"

SRC_URI[md5sum] = "5d73b2c6bd84dec386635cb9d27dc344"
SRC_URI[sha256sum] = "53bb456ebfb14f703d6ac708bf459dc0566c4c2fe888780a083a61543039a176"

S = "${WORKDIR}/git"
B = "${S}"

DEPENDS += "swig-native"
RDEPENDS_${PN} = "wiringpi"
