DESCRIPTION = "wxWidgets is a cross platform application framework utilizing native python."
HOMEPAGE = "http://www.wxpython.org"

LICENSE = "WXwindows"
LIC_FILES_CHKSUM = "file://licence/licence.txt;md5=18346072db6eb834b6edbd2cdc4f109b"

DEPENDS = "wxwidgets"

SRC_URI = "${SOURCEFORGE_MIRROR}/wxpython/wxPython-src-${PV}.tar.bz2"
SRC_URI[md5sum] = "922b02ff2c0202a7bf1607c98bbbbc04"
SRC_URI[sha256sum] = "d54129e5fbea4fb8091c87b2980760b72c22a386cb3b9dd2eebc928ef5e8df61"

S = "${WORKDIR}/wxPython-src-${PV}/wxPython"

inherit pkgconfig pythonnative python-dir distutils

#CFLAGS += "-I${STAGING_INCDIR}/wx-3.1/ -I${STAGING_LIBDIR}/wx/include/${TARGET_PREFIX}gtk2-unicode-3.1/"
CFLAGS += "`wx-config --cppflags`"
CFLAGS += "-std=gnu++11"

# Enable output on stdout for buildpaths
export WXDEBUG = "findprogress"

# EXTRA_OECONF_append_raspberrypi3 = "--enable-toolbook"

# remove -L/usr/X11R6/lib hardcodes
do_configure_prepend() {
	sed -i -e s:/usr/X11R6/lib::g ${S}/config.py
	# Change 2_8 compatibility to OFF
	# sed -i "s/#define WXWIN_COMPATIBILITY_2_8 1/#define WXWIN_COMPATIBILITY_2_8 0/" ${S}/../include/wx/gtk/setup0.h
}

# G. Oliver <go@aerodesic.com> misplled? (was "do_iinstall_append")
do_install_append() {
    cp -a ${D}${STAGING_DIR_HOST}/* ${D}
    rm -rf ${D}${STAGING_DIR}	
}
