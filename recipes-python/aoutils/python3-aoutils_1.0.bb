#
# Recipe for visioncoach server.
#
inherit distutils3 setuptools3

require python-aoutils.inc

DEPENDS += " \
	python3-distutils-extra-native 	\
	python3-dbus			\
	python3-pygobject 		\
"

RDEPENDS_${PN} += " \
	python3				\
	python3-dbus			\
	python3-threading		\
	python3-pygobject 		\
"

