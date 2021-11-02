fallocate -l 60M lofs.img
losetup -a
losetup -f 
sudo losetup -f lofs.img
sudo mkfs.ext4 /dev/loop0
losetup -a | grep 'lofs.img'
mkdir lofsdisk
sudo mount -o loop /dev/loop0 lofsdisk/
echo "All is done"
