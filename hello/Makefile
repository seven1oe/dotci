KDIR  := /home/appveyor/projects/dotci/linux-4.1.25
PWD   := $(shell pwd)
obj-m := mymodule.o

default:
	$(MAKE) -C $(KDIR) M=$(PWD) ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- modules
install:
	$(MAKE) -C $(KDIR) M=$(PWD) ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- INSTALL_MOD_PATH=/home/appveyor/projects/dotci/modules modules_install