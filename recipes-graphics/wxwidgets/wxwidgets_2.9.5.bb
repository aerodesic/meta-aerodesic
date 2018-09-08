DESCRIPTION = "wxWidgets is a cross platform application framework utilizing native widgets."
HOMEPAGE = "http://www.wxwidgets.org"
SECTION = "libs"

LICENSE = "WXwindows"
LIC_FILES_CHKSUM = "file://docs/licence.txt;md5=18346072db6eb834b6edbd2cdc4f109b"

DEPENDS = "webkitgtk gstreamer gst-plugins-base gtk+ jpeg tiff libpng zlib expat libxinerama libglu"
# DEPENDS = "webkitgtk gtk+ jpeg tiff libpng zlib expat libxinerama libglu"
# DEPENDS = "gtk+ jpeg tiff libpng zlib expat libxinerama libglu libnotify"

SRC_URI = "${SOURCEFORGE_MIRROR}/wxwindows/wxWidgets-${PV}.tar.bz2"
SRC_URI[md5sum] = "e98c5f92805493f150656403ffef3bb0"
SRC_URI[sha256sum] = "b74ba96ca537cc5d049d21ec9ab5eb2670406a4aa9f1ea4845ea84a9955a6e02"

S = "${WORKDIR}/wxWidgets-${PV}"

inherit autotools-brokensep pkgconfig binconfig

EXTRA_AUTORECONF = " -I ${S}/build/aclocal"
EXTRA_OECONF = " \
	--enable-compat28=yes \
	--with-opengl \
	--without-sdl \
	--disable-gpe \
	--disable-rpath \
	--enable-mediactrl \
	--enable-webviewwebkit \
    "

#	--with-gtk=2
#	--disable-gtktest
#	--disable-html
#	--disable-visibility
#	--disable-mediactrl
#	--disable-webviewwebkit

# CXXFLAGS := "${@oe_filter_out('-fvisibility-inlines-hidden', '${CXXFLAGS}', d)}"
CXXFLAGS_remove ="-fvisibility-inlines-hidden"
CXXFLAGS += "-std=gnu++11"

# Broken autotools :/
do_configure_prepend() {
	echo PKG_CONFIG_PATH=${PKG_CONFIG_PATH}
	# Add symbolic link for accessing webkit stuff
	ln -sf wx/html ${S}/include/webkit
}

do_configure() {
	oe_runconf
}

# wx-config contains entries like this:
# this_prefix=`check_dirname "/build/v2013.06/build/tmp-angstrom_v2013_06-eglibc/work/cortexa8hf-vfp-neon-angstrom-linux-gnueabi/wxwidgets/2.9.5-r0/wxWidgets-2.9.5"`
do_install_prepend() {
	# sed -i -e s:${S}:${STAGING_DIR_HOST}${prefix}:g ${S}/wx-config
	sed -i -e s:${S}:${COMPONENTS_DIR}/${PACKAGE_ARCH}/${PN}${prefix}:g ${S}/wx-config
}

# wx-config doesn't handle the suffixed libwx_media, xrc, etc, make a compat symlink
do_install_append() {
	ls -l 
	for lib in adv aui core html media propgrid qa ribbon richtext stc webview xrc ; do
		# Don't link to files that don't exist - webview especially - wxpython gets confused.
		if [ -e ${D}${libdir}/libwx_gtk2u_$lib-2.9.so.5.0.0 ]; then
			ln -sf libwx_gtk2u_$lib-2.9.so.5.0.0 ${D}${libdir}/libwx_gtk2u_$lib-2.9.so
		fi
	done
}

SYSROOT_PREPROCESS_FUNCS += "wxwidgets_sysroot_preprocess"
wxwidgets_sysroot_preprocess () {
#     sed -i -e 's,includedir="/usr/include",includedir="${STAGING_INCDIR}",g' ${SYSROOT_DESTDIR}${libdir}/wx/config/*
#    sed -i -e 's,libdir="/usr/lib",libdir="${STAGING_LIBDIR}",g' ${SYSROOT_DESTDIR}${libdir}/wx/config/*
	sed -i -e 's:includedir="/usr/include":includedir="${COMPONENTS_DIR}/${PACKAGE_ARCH}/${PN}${prefix}/include/wx-3.1":g' ${SYSROOT_DESTDIR}${libdir}/wx/config/*
	sed -i -e 's:libdir="/usr/lib":libdir="${COMPONENTS_DIR}/${PACKAGE_ARCH}/${PN}${libdir}":g'                            ${SYSROOT_DESTDIR}${libdir}/wx/config/*
}

FILES_${PN} += "${bindir} ${libdir}/wx/config ${libdir}"
FILES_${PN}-dev += "${libdir}/wx/include ${datadir}/bakefile"
