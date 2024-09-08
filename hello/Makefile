obj-m := hello.o
default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
	$(MAKE) -C $(KDIR) M=$(PWD) modules_install