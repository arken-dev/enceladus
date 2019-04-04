# ------------------------------------------------------------------------------
#
# Copyright 2016 The Charon Platform Authors.
#
# All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.
#
# ------------------------------------------------------------------------------

include_directories(.)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/deps/include)
include_directories(${PROJECT_SOURCE_DIR}/src/lua/json)

set(CXX_FLAGS
    -g
    -Wall
    -std=c++11
    -D_PTHREADS
    -Wno-unused-parameter
    -O2
    -finline-functions
)

file(GLOB src src1/*.cpp)

add_executable(
    enceladus
    ${src}
)

find_package(Boost COMPONENTS system)
find_package(Threads REQUIRED)
find_package(Qt5Core)
find_package(Qt5Network)



# if using boost
SET(Boost_USE_MULTITHREADED ON)

target_link_libraries( enceladus lua charon )
target_link_libraries( enceladus Qt5::Core Qt5::Network )
TARGET_LINK_LIBRARIES( enceladus pthread m ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})
