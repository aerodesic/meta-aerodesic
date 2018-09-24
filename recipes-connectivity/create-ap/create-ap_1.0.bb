DESCRIPTION = "Create an access point and bridge."
HOMEPAGE = "http://github.com/oblique/create_ap"
LICENSE = "BSD"
SECTION = "networking"

LIC_FILES_CHKSUM = "file://LICENSE;md5=47819091dc3777f6899ac4e6dbff2613"

inherit systemd

SRCREV="f906559f44afe6397a1775d0d2bc99d1e622b2fd"
SRC_URI = "git://github.com/oblique/create_ap.git"

SRC_URI[md5sum] = "757d6537294e113eba6e1410b931fa86"
SRC_URI[sha256sum] = "e3abcddbc032246316588b4bb07898c0fde0c86f0386d11ed6e59c1fffaa6643"

S="${WORKDIR}/git"

do_install () {
	oe_runmake install DESTDIR=${D} SBINDIR=${sbindir} MANDIR=${mandir} INCLUDEDIR=${includedir}
}

RDEPENDS_${PN} += "bash"

FILES_${PN} += "${sbindir} ${mandir} /usr/lib/systemd/system ${datadir}/bash-completion"
