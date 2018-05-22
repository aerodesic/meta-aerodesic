SUMMARY = "Add wired and wireless systemd startup information."

LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=441c28d2cf86e15a37fa47e15a72fbac"

SRC_URI = " \
        file://wired.network \
        file://wireless.network \
	file://COPYING \
"

S = "${WORKDIR}"

do_install() {
    # Add wired and wireless network configs to systemd
    install -m 0755 -d ${D}${sysconfdir}/systemd/network/
    install -m 0644 ${WORKDIR}/wired.network ${D}${sysconfdir}/systemd/network
    install -m 0644 ${WORKDIR}/wireless.network ${D}${sysconfdir}/systemd/network
}

FILES_PN="${sysconfdir}/systemd/network/* ${sysconfdir}/systemd/multi-user.target.wants/*"

