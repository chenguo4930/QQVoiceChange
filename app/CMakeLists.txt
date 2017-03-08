cmake_minimum_required(VERSION 3.4.1)

#查找系统库  liblog.so
find_library( log-lib
              log )
#变量
set(distribution_DIR ../../../../libs)

add_library( fmod
             SHARED
             IMPORTED )

set_target_properties( fmod
                       PROPERTIES IMPORTED_LOCATION
                       #ANDROID_ABI 预编译的变量，使用对应的编译工具链编译
                       ${distribution_DIR}/${ANDROID_ABI}/libfmod.so)

 add_library( fmodL
              SHARED
              IMPORTED)
 set_target_properties( fmodL
                        PROPERTIES IMPORTED_LOCATION
                        ${distribution_DIR}/${ANDROID_ABI}/libfmodL.so)

#linux编译特性，表示使用c++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

add_library( qqvoicer
             SHARED
             src/main/cpp/qqvoicer.cpp )
#需要预编译头文件的提示
include_directories(src/main/cpp/inc)

target_link_libraries(  qqvoicer
                        fmod
                        fmodL
                        ${log-lib})