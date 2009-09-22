#!/bin/sh


[ -z $4 ] && echo "Usage: $0 image kernel grub-stage-1 grub-stage-2" && exit 1

IMAGE=$1
KERNEL=$2
STAGE1=$3
STAGE2=$4

if [ ! -e $STAGE1 ] || [ ! -e $STAGE2 ] ; then
	echo Please obtain stage1 and stage2 grub images, and place them in the extras directory 
	exit 1
fi

[ -e $IMAGE ] && rm -f $IMAGE

dd if=/dev/zero of=$IMAGE bs=512 count=2880

yes | mkfs.msdos $IMAGE
#newfs_msdos -f 1440 $IMAGE

mmd -i $IMAGE ::boot
mmd -i $IMAGE ::boot/grub

mcopy -i $IMAGE $STAGE1 $STAGE2 ::boot/grub

echo "Installing grub boot block"

grub --device-map=/dev/null <<EOF

device (fd0) $IMAGE
root (fd0)
setup (fd0)
quit

EOF

mcopy -i $IMAGE - ::boot/grub/menu.lst <<EOF
title Kernel: $(basename $KERNEL)
root (fd0)
kernel /$(basename $KERNEL)
EOF

echo 'Adding kernel'
mcopy -i $IMAGE $KERNEL ::/

echo 'Rootfs done'

