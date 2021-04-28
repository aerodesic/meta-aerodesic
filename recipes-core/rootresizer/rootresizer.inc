SUMMARY = "Root resizer"
HOMEPAGE = "http://www.cpac.com"
MAINTAINER = "Gary Oliver <go@ao-cs.com>"
SECTION = "gentest"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=441c28d2cf86e15a37fa47e15a72fbac"

inherit systemd

PR = "r0"

DEPENDS = " \
"

RDEPENDS_${PN} = " \
	bash			\
	coreutils		\
	gnupg			\
	python3			\
	parted			\
	e2fsprogs-resize2fs	\
	util-linux		\
"

S = "${WORKDIR}"

SRC_URI = " \
	file://${BPN}			\
	file://${BPN}.service		\
	file://${BPN}.sh		\
	file://COPYING			\
"

do_install() {
	install -m 0755 -d ${D}${sbindir}
	install -m 0755 ${S}/${PN} ${S}/${PN}.sh ${D}${sbindir}

	install -d ${D}${systemd_system_unitdir}/
	install -m 0644 ${S}/${PN}.service ${D}${systemd_system_unitdir}/
}

SYSTEMD_SERVICE_${PN} = "rootresizer.service"

FILES_${PN} += "${sbindir} ${systemd_system_unitdir}"

