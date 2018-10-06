SUMMARY = "AO Utilities"
HOMEPAGE = "http://www.ao-cs.com"
SECTION = "utils"
LICENSE = "GPLv2"
PR = "r1"
OLD_PV := "${PV}"
PV = "${OLD_PV}+git${SRCPV}"
LIC_FILES_CHKSUM = "file://LICENSE.txt;md5=b234ee4d69f5fce4486a80fdaf4a4263"

SRCREV = "${AUTOREV}"

inherit pypi

DEPENDS = " \
	intltool-native 		\
"

S = "${WORKDIR}/git"

SRC_URI = " \
	git://go@repos.ao-cs.com/home/git/aoutils.git;protocol=ssh 	\
"

FILES_${PN} = "${libdir}"

