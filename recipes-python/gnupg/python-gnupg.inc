SUMMARY = "A python module interface to gnupg."
DESCRIPTION = "Interface library for more direct connection to gnupg."

HOMEPAGE = "http://gnupg.readthedocs.io/en/latest"

LICENSE = "BSD"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/BSD;md5=3775480a712fc46a69647678acb234cb"

SRC_URI[md5sum] = "2f25c27c98b33335b7e4e64c90ac9276"
SRC_URI[sha256sum] = "2d158dfc6b54927752b945ebe57e6a0c45da27747fa3b9ae66eccc0d2147ac0d"

PYPI_PACKAGE = "python-gnupg"

DEPENDS += "gnupg"
RDEPENDS_${PN} += "gnupg"

