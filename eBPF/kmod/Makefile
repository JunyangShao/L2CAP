obj-m += l2cap-probe.o
KDIR = /lib/modules/$(shell uname -r)/build
all:
	$(MAKE) -C $(KDIR) M=$(shell pwd) modules
clean:
	rm -rf *.o *.ko *.mod.* .c* .t*
