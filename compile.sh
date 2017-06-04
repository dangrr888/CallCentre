#! /bin/bash -

ROOT_DIR=${PWD}
BOOST_HEADERS_DIR=/usr/local/boost_installed/include
CALLCANETRE_IMPL_DIR=${ROOT_DIR}/src/main/C++
CALLCENTRE_HEADERS_DIR=${ROOT_DIR}/src/include/main

# Compile sourcefiles #
cd ${CALLCANETRE_IMPL_DIR}
g++ -o bin/callcentre ${CALLCENTRE_IMPL_DIR}/*.cpp --std=c++14 -I${BOOST_HEADERS_DIR} -I${CALLCENTRE_HEADERS_DIR}

exit $?