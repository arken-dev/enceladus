# ------------------------------------------------------------------------------
#
# Copyright 2016 The Arken Platform Authors.
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

link_directories( ${PROJECT_SOURCE_DIR}/deps )

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/clib/arken/net/HttpServer)

set(CXX_FLAGS
    -g
    -Wall
    -std=c++11
    -O2
    -finline-functions
)

set(ENCELADUS_MODEL "" CACHE STRING
  "enceladus concurrency model")

set_property(
  CACHE ENCELADUS_MODEL PROPERTY STRINGS
  "" model-1 model-2 model-3
)

if(ENCELADUS_MODEL STREQUAL "")
  set(ENCELADUS_MODEL "model-3")
endif()

message("ENCELADUS CONCURRENCY MODEL.....: ${ENCELADUS_MODEL}")

if(ENCELADUS_MODEL STREQUAL "model-1")
  set(ENCELADUS_MODEL "src1")
endif()

if(ENCELADUS_MODEL STREQUAL "model-2")
  set(ENCELADUS_MODEL "src2")
endif()

if(ENCELADUS_MODEL STREQUAL "model-3")
  set(ENCELADUS_MODEL "src3")
endif()


file(GLOB src ${ENCELADUS_MODEL}/*.cpp)

#add_executable(
#    enceladus
#    ${PROJECT_SOURCE_DIR}/src/arken/net/httpserver/httpserver.cpp
#    ${src}
#)

add_library(
  arken.net.HttpServer.enceladus SHARED
  ${PROJECT_SOURCE_DIR}/src/arken/net/httpserver/httpserver.cpp
  ${src}
)

set_target_properties(arken.net.HttpServer.enceladus PROPERTIES PREFIX "" OUTPUT_NAME enceladus)


find_package(Boost COMPONENTS system thread)
find_package(Threads REQUIRED)

# if using boost
SET(Boost_USE_MULTITHREADED ON)

#target_link_libraries( enceladus lua arken curl json )
#target_link_libraries( enceladus Qt5::Core Qt5::Network )
#TARGET_LINK_LIBRARIES( enceladus pthread m ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})
target_link_libraries(
  arken.net.HttpServer.enceladus
  arken
  pthread
  m
  ${CMAKE_THREAD_LIBS_INIT}
  ${Boost_LIBRARIES}
)
