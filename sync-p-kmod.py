#!/usr/bin/python3
import os
from random import randint

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
