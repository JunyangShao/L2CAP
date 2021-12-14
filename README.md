In order to reproduce the demo, please goto P website and install P https://github.com/p-org/P
Then replace the `/home/junyangshao/Desktop/P/publish/pc` with just `pc` in `compile.sh`
And also replace `/home/junyangshao/Desktop/L2CAP_P/L2CAP/` in `test.sh` with your path too
For bugfree test, modify `BT_CONFIG_timeout` and `BT_CONNECTED_timeout` to `0` in PSrc/Types.p
For liveness bug reproduce, modify `BT_CONFIG_timeout` and `BT_CONNECTED_timeout` to non `0` in PSrc/Types.p

Commands to reproduce:
`sh compile.sh && sh test.sh`
