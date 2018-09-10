DESCRIPTION = "Random assortment of WSGI servers"
SECTION = "devel/python"
PRIORITY = "optional"
LICENSE = "BSD"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/BSD-2-Clause;md5=8bef8e6712b1be5aa76af1ebde9d6378"

SRCNAME = "flup"
PR = "ml0"

SRC_URI = "\
	https://pypi.python.org/packages/source/f/${SRCNAME}/${SRCNAME}-${PV}.tar.gz	\
"

S = "${WORKDIR}/${SRCNAME}-${PV}"

SRC_URI[md5sum] = "a64e7a6374e043480ee92534c735964e"
SRC_URI[sha256sum] = "5eb09f26eb0751f8380d8ac43d1dfb20e1d42eca0fa45ea9289fa532a79cd159"

inherit setuptools3
