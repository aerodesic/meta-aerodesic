SUMMARY = "Startup script and systemd unit file for the Weston Wayland compositor"

LICENSE = "CLOSED"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

SRC_URI = " \
    file://init \
    file://weston.service \
    file://weston-start \
    file://default.weston-systemd \
    file://default.weston \
    file://weston.ini \
"

S = "${WORKDIR}"

PROVIDES += "weston-init"

do_install() {
	install -Dm755 ${WORKDIR}/init ${D}/${sysconfdir}/init.d/weston
	install -Dm0644 ${WORKDIR}/weston.service ${D}${systemd_system_unitdir}/weston.service

	# Install weston-start script
	install -Dm755 ${WORKDIR}/weston-start ${D}${bindir}/weston-start
	sed -i 's,@DATADIR@,${datadir},g' ${D}${bindir}/weston-start
	sed -i 's,@LOCALSTATEDIR@,${localstatedir},g' ${D}${bindir}/weston-start

	# Add weston default config
	install -Dm 0755 ${WORKDIR}/default.weston ${D}${sysconfdir}/default/weston
	install -Dm 0755 ${WORKDIR}/default.weston-systemd ${D}${sysconfdir}/default/weston-systemd

	# Add weston.ini to etc
	install -Dm 0755 ${WORKDIR}/weston.ini ${D}${sysconfdir}
}

# inherit allarch update-rc.d distro_features_check systemd useradd
inherit allarch update-rc.d features_check systemd useradd

# Add user 'display' for weston services
USERADD_PACKAGES = "${PN}"
USERADD_PARAM_${PN} = "-u 1001 display -g display"
GROUPADD_PARAM_${PN} = "-g 1001 display"

# rdepends on weston which depends on virtual/egl
REQUIRED_DISTRO_FEATURES = "opengl"

DEPENDS = "libpam"
RDEPENDS_${PN} = "weston kbd bash framebuffer libpam"

INITSCRIPT_NAME = "weston"
INITSCRIPT_PARAMS = "start 9 5 2 . stop 20 0 1 6 ."

SYSTEMD_SERVICE_${PN} = "weston.service"

FILES_${PN} += "${sbindir}/* ${sysconfdir}/default /usr/share/bitmaps/"
