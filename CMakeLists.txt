cmake_minimum_required(VERSION 3.10)

project(Nightmoonclickbetweenframes)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(ANDROID_NATIVE_API_LEVEL 21)

set(ANDROID_NDK C:/AndroidNDK/android-ndk-r27c)

set(CMAKE_TOOLCHAIN_FILE ${ANDROID_NDK}/build/cmake/android.toolchain.cmake)

set(CMAKE_ANDROID_ARCH_ABI arm64-v8a)

set(ANDROID_PLATFORM android-21)

set(ANDROID_ABIS armeabi-v7a arm64-v8a)

include_directories(${CMAKE_SOURCE_DIR}/src/includes)

foreach(ABI IN LISTS ANDROID_ABIS)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs/${ABI})

    add_library(Nightmoonclickbetweenframes_${ABI} SHARED
        ${CMAKE_SOURCE_DIR}/src/main.cpp
        ${CMAKE_SOURCE_DIR}/src/input.hpp
    )

    set_target_properties(Nightmoonclickbetweenframes_${ABI} PROPERTIES
        COMPILE_FLAGS "-DANDROID_ABI=${ABI}"
        OUTPUT_NAME "Nightmoonclickbetweenframes"
    )

    target_link_libraries(Nightmoonclickbetweenframes_${ABI} log android)
endforeach()

