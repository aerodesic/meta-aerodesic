SUMMARY = "Download lots of useful MIBs for SNMP"
HOMEPAGE = "https://salsa.debian.org/debian/snmp-mibs-downloader"
SECTION = "devtools"
LICENSE = "BSD"
LIC_FILES_CHKSUM = "file://debian/copyright;md5=97b7fe3ba9a2d0e444082e69c7b37f6b"
PR = "r1"

DEPENDS = " \
	libsmi	\
	bash	\
"

RDEPENDS_${PN} = " \
	libsmi	\
	bash	\
"

SRCREV ?= "${AUTOREV}"

S = "${WORKDIR}/git"

SRC_URI = " \
    git://salsa.debian.org/debian/${BPN};protocol=https	\
"

EXTRA_OEMAKE = "DESTDIR=${D} INSTALL=install"

do_compile() {
    oe_runmake
}


do_install() {
    # Create target directories

    install -m 755 -d ${D}${bindir}
    install -m 755 -d ${D}${sysconfdir}/snmp-mibs-downloader
    install -m 755 -d ${D}${datadir}/snmp/mibs-downloader/mibrfcs
    install -m 755 -d ${D}${datadir}/snmp/mibs-downloader/mibiana
    install -m 755 -d ${D}${datadir}/snmp/mibs/ietf
    install -m 755 -d ${D}${datadir}/snmp/mibs/iana

    oe_runmake install
}

FILES_${PN} = "${datadir} ${sysconfdir} ${bindir}"

BBCLASSEXTEND = "native nativesdk"

