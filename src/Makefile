obj-m += hello-1.o
obj-m += hello2.o
CONFIG_MODULE_SIG=n

PWD := $(CURDIR)
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
