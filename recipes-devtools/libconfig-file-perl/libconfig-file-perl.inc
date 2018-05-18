SUMMARY = "Perl module to Parse a simple configuration file."

DESCRIPTION = "Config::File parses simple configuration files and store its values in an anonymous hash reference."

HOMEPAGE = "http://my.huhoo.net/"

SECTION = "libs"
LICENSE = "GPL"

LIC_FILES_CHKSUM = "file://LICENSE;md5=751419260aa954499f7abaabaa882bbe"

SRC_URI = "https://www.cpan.org/modules/by-module/Config/Config-File-${PV}.tar.gz;subdir=${BP}"

SRC_URI[md5sum] = "ea1f012b4336697be1c2e4cc2c3396e0"
SRC_URI[sha256sum] = "7ad5e4466da1f59ce95111432345a4d4beeda602f8c28be6e09f79e32043916a"

S = "${WORKDIR}/${BPN}-${PV}/Config-File-${PV}"

# EXTRA_CPANFLAGS = "INC=-I${STAGING_INCDIR}/libxml2 LIBS=-L${STAGING_LIBDIR}"
# EXTRA_CPANFLAGS = "INC=-I${STAGING_INCDIR}/libxml2 LIBS=-L${STAGING_LIBDIR}"

inherit cpan_build allarch

#do_compile() {
#     export LIBC="$(find ${STAGING_DIR_TARGET}/${base_libdir}/ -name 'libc-*.so')"
#     cpan_do_compile
#}

# BBCLASSEXTEND = "native"

