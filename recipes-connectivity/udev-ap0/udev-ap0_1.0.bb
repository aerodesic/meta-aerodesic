SUMMARY = "Add ap0 rules to udev to it is brought up at boot time."

LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=441c28d2cf86e15a37fa47e15a72fbac"

SRC_URI = " \
        file://70-create-ap0.rules	\
	file://COPYING			\
"

S = "${WORKDIR}"

do_install() {
    # Add udev rules
    install -m 0755 -d ${D}${sysconfdir}/udev/rules.d/
    install -m 0644 ${WORKDIR}/70-create-ap0.rules ${D}${sysconfdir}/udev/rules.d/
}

FILES_PN="${sysconfdir}/udev/rules.d/*"

