#!/bin/bash

wget -O boost_1_86_0.tar.gz https://archives.boost.io/release/1.86.0/source/boost_1_86_0.tar.gz
tar xzvf boost_1_86_0.tar.gz
cd boost_1_86_0/

./bootstrap.sh --prefix=/usr/
./b2
./b2 install