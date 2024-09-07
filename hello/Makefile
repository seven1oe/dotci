KDIR  := $APPVEYOR_BUILD_FOLDER/linux-4.1.25
PWD   := $(shell pwd)
obj-m := mymodule.o

default:
	$(MAKE) -C $(KDIR) M=$(PWD) ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- INSTALL_MOD_PATH=$APPVEYOR_BUILD_FOLDER/modules modules_install
