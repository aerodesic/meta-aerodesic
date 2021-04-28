# Fetch some files for overriding configuration of default system.
FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

# Leave disabled - NetworkManager deals with it
SYSTEMD_AUTO_ENABLE_${PN} = "disable"

# Override dnsmasq.service to wait for network-online rather than just network
SRC_URI += "\
	file://dnsmasq.service	\
"

do_install_append() {
	install -m 0755 -d ${D}${systemd_unitdir}/system/
	install -m 0644 ${WORKDIR}/${PN}.service ${D}${systemd_unitdir}/system/
}
