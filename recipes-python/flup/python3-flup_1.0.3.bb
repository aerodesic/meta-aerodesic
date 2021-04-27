DESCRIPTION = "Random assortment of WSGI servers"
SECTION = "devel/python"
PRIORITY = "optional"
LICENSE = "BSD"
LIC_FILES_CHKSUM = "file://${WORKDIR}/LICENSE.txt;md5=7731c23fc0a35391a01f9473e08b01ba"

SRCNAME = "flup"
PR = "ml0"

SRC_URI = "\
	file://LICENSE.txt								\
	https://pypi.python.org/packages/source/f/${SRCNAME}/${SRCNAME}-${PV}.tar.gz	\
"

S = "${WORKDIR}/${SRCNAME}-${PV}"

SRC_URI[md5sum] = "a64e7a6374e043480ee92534c735964e"
SRC_URI[sha256sum] = "5eb09f26eb0751f8380d8ac43d1dfb20e1d42eca0fa45ea9289fa532a79cd159"

inherit setuptools3
