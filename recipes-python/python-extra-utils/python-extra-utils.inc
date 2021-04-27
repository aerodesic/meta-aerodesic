SUMMARY = "Extra python utilities"
HOMEPAGE = "http://www.aerodesic.com"
SECTION = "utils"
LICENSE = "GPLv2"
PR = "r1"
LIC_FILES_CHKSUM = "file://LICENSE.txt;md5=b234ee4d69f5fce4486a80fdaf4a4263"

inherit pypi

DEPENDS = " \
	intltool-native 		\
"

S = "${WORKDIR}/git"

SRC_URI = " \
	git://git@github.com/aerodesic/extra-utils.git;protocol=ssh	\
"

FILES_${PN} = "${libdir}"

