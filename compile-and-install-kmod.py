#!/usr/bin/python3
import os
from random import randint

os.system("cd eBPF/kmod/ && sudo make && sudo rmmod l2cap-probe && sudo insmod l2cap-probe.ko")
