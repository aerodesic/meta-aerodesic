SUMMARY = "threading2 package for python"
SECTION = "python"
LICENSE = "GPL"
PR = "r1"

inherit pypi distutils setuptools

DEPENDS = " \
	python-distutils-extra-native 	\
	intltool-native 		\
"

RDEPENDS_${PN} = " \
	python				\
"

S = "${WORKDIR}/git"

SRC_URI = " \
	https://github.com/rfk/${PN}.git \
"

do_install_append() {
	echo "${PN}" > ${D}${PYTHON_SITEPACKAGES_DIR}/${PN}-${PV}.pth
}

FILES_${PN} = "${libdir}"

