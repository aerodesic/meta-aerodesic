#
# Recipe for visioncoach server.
#
inherit distutils setuptools

require python-aoutils.inc

DEPENDS += " \
	python-distutils-extra-native 	\
	python-dbus			\
"

RDEPENDS_${PN} += " \
	python				\
	python-dbus			\
	python-threading		\
"

