SUMMARY = "threading2 package for python"
SECTION = "python"
LICENSE = "GPL"
PR = "r1"

inherit pypi

S = "${WORKDIR}/git"

SRC_URI = " \
	https://github.com/rfk/${PN}.git \
"

DEPENDS += " \
	intltool-native 		\
"

do_install_append() {
	echo "${PN}" > ${D}${PYTHON_SITEPACKAGES_DIR}/${PN}-${PV}.pth
}

FILES_${PN} = "${libdir}"

