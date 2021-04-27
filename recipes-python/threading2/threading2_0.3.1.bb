#
# Recipe for threading2
#
SRCREV = "895b4798fd3dff7060ddbf49672cabecb83678b5"

inherit distutils3 setuptools3

DEPENDS+= " \
	python3-distutils-extra-native 	\
"

RDEPENDS_${PN} += " \
	python3				\
"

require threading2.inc
