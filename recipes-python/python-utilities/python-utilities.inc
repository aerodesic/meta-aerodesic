SUMMARY = "Some extra python utilities"
HOMEPAGE = "http://robosity.com"
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
	git://go@repos.ao-cs.com/home/git/python-extra-utilities.git;protocol=ssh 	\
"

FILES_${PN} = "${libdir}"

