DEPEND = "virtual/kernel"

do_deploy_append() {
	install -d -m 0755 ${DEPLOYDIR}/${BOOTFILES_DIR_NAME}

	echo "# Enable 2 framebuffers"                                     >> ${DEPLOYDIR}/${BOOTFILES_DIR_NAME}/config.txt
	echo "max_framebuffers=2"                                          >> ${DEPLOYDIR}/${BOOTFILES_DIR_NAME}/config.txt

# Disabled for now but left in config.txt

	echo '## ' "# Enable USB OTG"                                      >> ${DEPLOYDIR}/${BOOTFILES_DIR_NAME}/config.txt
	echo '## ' "dtoverlay=dwc2"                                        >> ${DEPLOYDIR}/${BOOTFILES_DIR_NAME}/config.txt

	echo '## ' "# Disable SPI"                                         >> ${DEPLOYDIR}/${BOOTFILES_DIR_NAME}/config.txt
	echo '## ' "dtparam=spi=off"                                       >> ${DEPLOYDIR}/${BOOTFILES_DIR_NAME}/config.txt

	echo '## ' "# Disable Slash colors"                                >> ${DEPLOYDIR}/${BOOTFILES_DIR_NAME}/config.txt
	echo '## ' "disable_splash=1"                                      >> ${DEPLOYDIR}/${BOOTFILES_DIR_NAME}/config.txt

#	echo '## ' "# Enable hardware random"                              >> ${DEPLOYDIR}/${BOOTFILES_DIR_NAME}/config.txt
#	echo '## ' "dtparam=random=on"                                     >> ${DEPLOYDIR}/${BOOTFILES_DIR_NAME}/config.txt

	echo '## ' "# Enable PWM audio out"                                >> ${DEPLOYDIR}/${BOOTFILES_DIR_NAME}/config.txt
	echo '## ' "dtoverlay=pwm-2chan,pin=18,func=2,pin2=13,func2=4"     >> ${DEPLOYDIR}/${BOOTFILES_DIR_NAME}/config.txt
}
