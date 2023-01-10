cmake_minimum_required(VERSION 3.5)

project(blockchain)

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

add_executable(blockchain main.cpp blockchain.cpp block.cpp)

target_link_libraries(blockchain ${OPENSSL_LIBRARIES})
