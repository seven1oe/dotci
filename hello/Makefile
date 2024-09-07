obj-m += hello.o

all:
    make -C $APPVEYOR_BUILD_FOLDER/linux-4.1.25 M=$(PWD) modules
clean:
    make -C $APPVEYOR_BUILD_FOLDER/linux-4.1.25 M=$(PWD) clean