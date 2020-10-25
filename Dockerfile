FROM ubuntu:16.04

CMD cd $RESIBOTS_DIR
RUN apt-add-repository ppa:dartsim/ppa \ 
    apt-get update
RUN apt-get install build-essential cmake pkg-config git \
    apt-get install libeigen3-dev libassimp-dev libccd-dev libfcl-dev libboost-regex-dev libboost-system-dev libode-dev \
    apt-get install libopenscenegraph-dev \
    apt-get install libxmu-dev libxi-dev \
    apt-get install freeglut3-dev \

RUN apt-get install libtinyxml-dev libtinyxml2-dev \
    apt-get install liburdfdom-dev liburdfdom-headers-dev

RUN git clone git://github.com/dartsim/dart.git
WORKDIR dart
RUN git checkout v6.3.0

RUN mkdir build
WORKDIR build
RUN cmake -DDART_ENABLE_SIMD=ON .. \
    make -j4
RUN make install

CMD cd $RESIBOTS_DIR
RUN git clone https://github.com/resibots/hexapod_common.git
WORKDIR hexapod_common/hexapod_models
RUN ./waf configure --prefix=$RESIBOTS_DIR \
    ./waf install
WORKDIR ../hexapod_controller
RUN ./waf configure --prefix=$RESIBOTS_DIR \
    ./waf \
    ./waf install \

CMD cd $RESIBOTS_DIR
RUN git clone https://github.com/resibots/hexapod_simu.git
WORKDIR hexapod_simu/hexapod_dart
RUN ./waf configure --prefix=$RESIBOTS_DIR \
    ./waf \
    ./waf install

RUN apt-get update \
    apt-get install libeigen3-dev libboost-serialization-dev libboost-filesystem-dev \
    libboost-test-dev libboost-program-options-dev libboost-thread-dev libboost-regex-dev \
    libboost-graph-dev
RUN apt-get install libtbb-dev

CMD cd $RESIBOTS_DIR
RUN git clone https://github.com/resibots/limbo.git
WORKDIR limbo
RUN mkdir exp 
WORKDIR exp
RUN git clone https://github.com/resibots/ite_v2.git
WORKDIR ../..
RUN ./waf configure --exp ite_v2 \
    ./waf --exp ite_v2