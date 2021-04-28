# Fetch some files for overriding configuration of default system.
FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SYSTEMD_AUTO_ENABLE_${PN} = "enable"

SRC_URI += "file://dhcpcd.conf"
# SRC_URI[dhcpcd.conf.sha256sum] = "xxx"

do_install_append() {
    # Install our modified dhcpcd.conf
    install -d -m 0755 ${sysconfdir}
    install -m 0644 ${WORKDIR}/${PN}.conf ${D}${sysconfdir}
}

FILES_${PN} += "${sysconfdir}"
