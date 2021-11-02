touch file1
echo "Andrey" > file1
touch file2
echo "Starodumov" > file2
cp file* lofsdisk/


cp /bin/{bash,ls} lofsdisk/
sudo cp /bin/{bash,ls} lofsdisk/
ldd /bin/bash
sudo mkdir lofsdisk/lib
cd lofsdisk/
ls
cd lib
sudo mkdir x86_64-linux-gnu
cd ..
sudo mkdir lib64
cp {/lib/x86_64-linux-gnu/libtinfo.so.6,/lib/x86_64-linux-gnu/libdl.so.2,/lib/x86_64-linux-gnu/libc.so.6} lofsdisk/lib/x86_64-linux-gnu/
sudo cp {/lib/x86_64-linux-gnu/libtinfo.so.6,/lib/x86_64-linux-gnu/libdl.so.2,/lib/x86_64-linux-gnu/libc.so.6} lofsdisk/lib/x86_64-linux-gnu/
ldd /bin/ls
sudo cp {/lib/x86_64-linux-gnu/libselinux.so.1,/lib/x86_64-linux-gnu/libc.so.6,/lib/x86_64-linux-gnu/libpcre2-8.so.0,/lib/x86_64-linux-gnu/libdl.so.2,/lib/x86_64-linux-gnu/libpthread.so.0} lofsdisk/lib/x86_64-linux-gnu/
sudo cp /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64/
sudo cp ex2.out lofsdisk/
cd lofsdisk/
ls
sudo mkdir bin
ls
sudo mv bash bin/
sudo mv ls bin/
cd ..
ldd /bin/bash
cp /lib/x86_64-linux-gnu/libtinfo.so.6 lofsdisk/lib/x86_64-linux-gnu/libtinfo.so.6
sudo cp /lib/x86_64-linux-gnu/libtinfo.so.6 lofsdisk/lib/x86_64-linux-gnu/libtinfo.so.6
sudo cp /lib/x86_64-linux-gnu/libdl.so.2 lofsdisk/lib/x86_64-linux-gnu/libdl.so.2
sudo cp /lib/x86_64-linux-gnu/libc.so.6 lofsdisk/lib/x86_64-linux-gnu/libc.so.6
sudo cp /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64/ld-linux-x86-64.so.2
ldd /bin/ls
sudo cp /lib/x86_64-linux-gnu/libselinux.so.1 lofsdisk/lib/x86_64-linux-gnu/libselinux.so.1
sudo cp /lib/x86_64-linux-gnu/libc.so.6 lofsdisk/lib/x86_64-linux-gnu/libc.so.6
sudo cp /lib/x86_64-linux-gnu/libpcre2-8.so.0 lofsdisk/lib/x86_64-linux-gnu/libpcre2-8.so.0
sudo cp /lib/x86_64-linux-gnu/libdl.so.2 lofsdsik/lib/x86_64-linux-gnu/libdl.so.2
sudo cp /lib/x86_64-linux-gnu/libdl.so.2 lofsdsik/lib/x86_64-linux-gnu/libdl.so.2
sudo cp /lib/x86_64-linux-gnu/libdl.so.2 lofsdisk/lib/x86_64-linux-gnu/libdl.so.2
sudo cp /lib/x86_64-linux-gnu/libpthread.so.0 lofsdisk/lib/x86_64-linux-gnu/libpthread.so.0
ldd /bin/cat
sudo cp /lib/x86_64-linux-gnu/libc.so.6 lofsdisk/lib/x86_64-linux-gnu/libc.so.6
sudo cp /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64/ld-linux-x86-64.so.2
ldd /bin/echo
sudo cp /lib/x86_64-linux-gnu/libc.so.6 lofsdisk/lib/x86_64-linux-gnu/libc.so.6
sudo cp /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64/ld-linux-x86-64.so.2
sudo cp ./ex2.out lofsdisk/
sudo chroot lofsdisk/
