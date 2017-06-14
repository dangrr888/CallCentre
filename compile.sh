#! /bin/bash -

ROOT_DIR=${PWD}
BOOST_HEADERS_DIR=/usr/local/boost_installed/include
CALLCENTRE_IMPL_DIR=${ROOT_DIR}/src/C++/main
CALLCENTRE_HEADERS_DIR=${ROOT_DIR}/src/include/main
OUTPUT_DIR=${ROOT_DIR}/bin

# Compile sourcefiles #
g++ -o ${OUTPUT_DIR}/callcentre ${CALLCENTRE_IMPL_DIR}/*.cpp --std=c++14 -I${BOOST_HEADERS_DIR} -I${CALLCENTRE_HEADERS_DIR}

exit $?