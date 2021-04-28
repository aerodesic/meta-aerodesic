FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

# PACKAGECONFIG_remove_rpi = "${@bb.utils.contains('MACHINE_FEATURES', 'vc4graphics', 'fbdev', '', d)}"
# 
# EXTRA_OECONF_append_rpi = " \
#     --disable-xwayland-test \
#     --disable-simple-egl-clients \
#     ${@bb.utils.contains('MACHINE_FEATURES', 'vc4graphics', '', ' \
#         --disable-resize-optimization \
#         --disable-setuid-install \
#     ', d)} \
# "

# These patches were borrowed from automotivelinux.org to enable weston running as non-root
xxxSRC_URI_append = " \
    file://0001-Allow-regular-users-to-launch-Weston.patch \
"

PROVIDES = "userland"

EXTRA_OECONF_append_rpi = " --with-pam --enable-sys-uid"
DEPENDS += " xcb-proto"

