#!/usr/bin/python3
from bcc import BPF
BPF(src_file="./code.c").trace_print()