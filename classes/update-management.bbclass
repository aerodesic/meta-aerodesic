
# Postprocess the image and collect all debs in tmp/deploy/debs/*/*.deb.
# Two support directories exist (or are created) to facilitate generation of updates.
# If 'updated-cache' exists, debs that are different to those in this directory
# are copied to updated-debs.  If updated-cache does not exist, it is created
# and filled with a copy of the files in the deployed debs dir.
# 
do_update_management() {
    if [ ! -d updated-cache ]; then
        # Create cache and link deployed debs to it.
        mkdir updated-cache
        for file in tmp/deploy/deb/*/*.deb; do
            ln -sf $file updated-cache/`basename $file`
        done
        rm -rf updated-debs
    else
        # Start with a fresh updated folder
        rm -rf updated-debs
        mkdir updated-debs

        # Any file that doesn't exist in the original is copied
        for file in tmp/deploy/deb/*/*.deb; do
           if [ ! -e updated-cache/`basename $file` ]; then
               cp $file updated-debs/`basename $file`
           fi
        done
    fi
}

IMAGE_POSTPROCESS_COMMAND = "do_update_management"

