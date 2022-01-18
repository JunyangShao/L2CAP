#!/usr/bin/python3
from bcc import BPF
BPF(src_file="./code-simplified.c", cflags=["-fmacro-backtrace-limit=0"]).trace_print()
