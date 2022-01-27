#!/usr/bin/python3
import os
from random import randint

# Step 0: statically find the register containing the arguments we want for `l2cap_recv_frame`
# Should be done by:
# 1. Uncomment line 136 ~ 139 in ../eBPF/kmod/ish.c
# 2. In terminal 1: sudo ../eBPF/hook.py
# 3. In terminal 2: cd ../eBPF/kmod/ && sudo make && sudo rmmod ish && sudo insmod ish.ko
# 4. Connect to some Bluetooth Device.
# 5. In terminal 2: sudo dmesg
# 6. Compare the output in terminal 1 and terminal 2, find the registers that match the arguments.
# 7. Comment line 136 ~ 139 in ../eBPF/kmod/ish.c
# Noted that this is a one-time effort after Kernel compilation, so no need to write it into the script.

# Step 1: register the kprobe and start P service.
#   Step 1-1: generate instance ID for communication
servid = randint(0, 99999999)

f = open("./eBPF/kmod/l2cap-probe-template.c","r")
f2 = open("./eBPF/kmod/l2cap-probe.c","w")
for i in f:
    j = i
    if 'P Server ID = $TEMPLATE' in j:
        j = j.replace("$TEMPLATE", str(servid))
    f2.write(j)
f.close()
f2.close()

f = open("./C/L2CAP.c.template",'r')
f2 = open("./C/L2CAP.c",'w')
for i in f:
    j = i
    if 'P Server ID = $TEMPLATE' in j:
        j = j.replace("$TEMPLATE", str(servid))
    f2.write(j)
f.close()
f2.close()
#   Step 1-2: recompile, insmod, start P service.
os.system("cd C && sh build.sh")
os.system("cd eBPF/kmod/ && sudo make && sudo rmmod l2cap-probe && sudo insmod l2cap-probe.ko")
os.system("clear && ./C/pserv")

# Step 2: connect to some bluetooth devices