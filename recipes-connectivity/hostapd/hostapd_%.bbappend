# Fetch some files for overriding configuration of default system.
FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SYSTEMD_AUTO_ENABLE_${PN} = "disable"

RDEPENDS_${PN} += " bash"

# Add a file to muck password into vcoach-<mac suffix>
SRC_URI += " \
	file://hostapd-mac-to-pw.sh	\
	file://hostapd.conf		\
"

do_install_append() {
    install -d -m 0755 ${sbindir}
    install -m 0755 ${WORKDIR}/hostapd-mac-to-pw.sh ${D}${sbindir}

    install -d -m 0755 ${sysconfdir}
    install -m 0644 ${WORKDIR}/hostapd.conf ${D}${sysconfdir}

    # Fix up symbolic directories in mac address fixup file
    sed -i -e 's#@SYSCONFDIR@#${sysconfdir}#g' ${D}${sbindir}/hostapd-mac-to-pw.sh
    sed -i -e 's#@SBINDIR@#${sbindir}#g' ${D}${sbindir}/hostapd-mac-to-pw.sh
    sed -i -e 's#@BINDIR@#${bindir}#g' ${D}${sbindir}/hostapd-mac-to-pw.sh
}

FILES_${PN} += "${sysconfdir} ${sbindir}"
