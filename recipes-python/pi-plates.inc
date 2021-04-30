SUMMARY = "Control application for generator test"
HOMEPAGE = "http://www.robosity.com"
SECTION = "gentest"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://extra/COPYING;md5=441c28d2cf86e15a37fa47e15a72fbac"
PR = "r1"
REPO_NAME = "GenTestControl"
BRANCH ?= ""
SRCREV ?= "${AUTOREV}"

inherit pypi distutils3 setuptools3 systemd

DEPENDS = " \
    python3-distutils-extra-native      \
    intltool-native                     \
    python3-dbus                        \
    python3-pygobject                   \
    python3-spidev                      \
    python3-aoutils                     \
"

RDEPENDS_${PN} += " \
    python3-core                        \
    python3-threading                   \
    python3-pygobject                   \
    python3-spidev                      \
    python3-dbus                        \
    python3-rpi-gpio                    \
    python3-systemd                     \
    python3-aoutils                     \
    bash                                \
"

S = "${WORKDIR}/git"

SRC_URI = " \
    git://git@github.com/aerodesic/${REPO_NAME};protocol=ssh;branch=main        \
    file://${BPN}.conf                                                          \
    file://${BPN}.service                                                       \
"

SYSTEMD_SERVICE_${PN} = "${PN}.service"

do_install_append() {
    echo "${PN}" > ${D}${PYTHON_SITEPACKAGES_DIR}/${PN}-${PV}.pth

    chmod +x ${D}${sbindir}/${PN}

    install -m 755 -d ${D}${sysconfdir}/dbus-1/system.d
    install -m 644 ${WORKDIR}/${PN}.conf ${D}${sysconfdir}/dbus-1/system.d
    install -m 755 -d ${D}${datadir}/dbus-1/system.d
    install -m 644 ${WORKDIR}/${PN}.conf ${D}${datadir}/dbus-1/system.d

    install -d ${D}${systemd_unitdir}/system
    install -m 0644 ${WORKDIR}/${PN}.service ${D}${systemd_unitdir}/system

    install -m 755 -d ${D}/home/gentest/
}

# Has a password
def hash_default_password(pw):
    if len(pw) != 0:
        import crypt
        pw=crypt.crypt(pw)

    # Return escaping any $ characters to allow passage through shell
    return pw.replace('$', '\\$')

# Conditionally assign UPSCNTL_CRYPT_PASSWORD only if UPSCNTL_PASSWORD is defined
UPSCNTL_CRYPT_PASSWORD := "${@hash_default_password('${UPSCNTL_PASSWORD}')}"

pkg_postinst_ontarget_${PN}() {
#!/bin/sh -e
# Add key to system key ring
gpg -q --import ${datadir}/${PN}/package_signing.key
if [ -n "${GENTEST_CRYPT_PASSWORD}" ]; then
  usermod -p "${GENTEST_CRYPT_PASSWORD}" gentest 
fi
}

# Remove file from system key ring
pkg_prerm_${PN}() {
#!/bin/sh -e
gpg -q --yes --batch --delete-key ${DEB_GPG_NAME}
}

FILES_${PN} = "${libdir} ${sbindir} ${sysconfdir} ${datadir} ${systemd_unitdir} /home/gentest"

SYSTEMD_AUTO_ENABLE_${PN} = "enable"

