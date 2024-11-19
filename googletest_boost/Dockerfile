FROM ubuntu:22.04

RUN apt update && apt install -y \
wget \
lsb-release \
software-properties-common \
gpg \
cmake \
libboost-all-dev \
git

RUN wget https://apt.llvm.org/llvm.sh
RUN chmod u+x llvm.sh
RUN ./llvm.sh 18

ENV CC=clang-18
ENV CXX=clang++-18
