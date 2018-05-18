DESCRIPTION = "dpkg-sig signer of .debs"
HOMEPAGE = "https://packages.debian.org/sid/dpkg-sig"
SECTION = "devel"
LICENSE = "GPL"
LIC_FILES_CHKSUM = "file://copyright;md5=e0e12c8ee5af2ebee420a8ae2ad35f2f"

RDEPENDS_${PN} = "perl gnupg perl-module-digest-md5 libconfig-file-perl"

SRC_URI = " \
	http://http.debian.net/debian/pool/main/d/dpkg-sig/${PN}_${PV}.tar.gz \
"

do_install () {
    install -d ${D}${bindir}
    install
}

FILES_${PN} = "${bindir}/*"


