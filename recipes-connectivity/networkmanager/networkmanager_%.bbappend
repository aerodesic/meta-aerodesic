# Fetch some files for overriding configuration of default system.
FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
        file://NetworkManager.conf	\
"

do_install_append() {
    install -d -m 0755 ${D}${sysconfdir}/NetworkManager/
    install -m 0755 ${WORKDIR}/NetworkManager.conf ${D}${sysconfdir}/NetworkManager/
}

FILES_${PN} += "${sysconfdir}/NetworkManager"

