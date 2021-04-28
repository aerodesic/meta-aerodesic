# Fix up postinstall problem
do_install_append() {
  # Removed
}

# Make original postinst go away
pkg_postinst_${PN} = ''

# Add postinst that only gets run on actual startup of device
pkg_postinst_ontarget_${PN} () {
    # The exit status is 143 when the service is stopped
    if ${@bb.utils.contains('DISTRO_FEATURES', 'systemd', 'true', 'false', d)}; then
        sed -i '/ExecStart/a SuccessExitStatus=143' $D${systemd_system_unitdir}/haveged.service
    fi
}


