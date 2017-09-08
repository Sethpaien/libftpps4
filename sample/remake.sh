#!/bin/bash
cd ..
make
cp libftpps4.a ../libPS4/
cd sample
make clean
reset
make
nc 192.168.0.17 9023 < sample.bin

