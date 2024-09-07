obj-m += hello.o

all:
    make -C $APPVEYOR_BUILD_FOLDER/linux-4.1.25 M=$PWD ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- modules
clean:
    make -C $APPVEYOR_BUILD_FOLDER/linux-4.1.25 M=$PWD clean