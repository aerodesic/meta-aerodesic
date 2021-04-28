SUMMARY = "Pi-Plates library for DAQC2Plates"
HOMEPAGE = "https://pi-plates.com"
LICENSE = "BSD"
LIC_FILES_CHKSUM = "file://${WORKDIR}/LICENSE;md5=aec936b1ad0df114b61a510495ca0ab0"

SRC_URI += "	\
	file://LICENSE		\
"

DEPENDS += " \
"

RDEPENDS_${PN} += " \
	python3-rpi-gpio	\
	python3-spidev		\
	python3-six		\
"


# PYPI_PACKAGE = "Pi-Plates"

BBCLASSEXTEND = "native nativesdk"
