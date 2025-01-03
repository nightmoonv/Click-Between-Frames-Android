cmake_minimum_required(VERSION 3.21)

project(NightmoonGDClickBetweenFrames)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(ANDROID_PLATFORM android-21)
set(ANDROID_ABIS armeabi-v7a arm64-v8a)
set(ANDROID_NATIVE_API_LEVEL 21)
set(ANDROID_NDK C:/AndroidNDK/android-ndk-r27c)
set(CMAKE_TOOLCHAIN_FILE ${ANDROID_NDK}/build/cmake/android.toolchain.cmake)
set(CMAKE_ANDROID_ARCH_ABI av8a)

include_directories(${CMAKE_SOURCE_DIR}/src/includes)

foreach(ABI IN LISTS ANDROID_ABIS)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs/${ABI})

    if(${ABI} STREQUAL "arm64-v8a")
        set(ARCH_SUFFIX "android64")
    else()
        set(ARCH_SUFFIX "android32")
    endif()

    add_library(NightmoonGD.Click_between_frames_${ABI} SHARED
        ${CMAKE_SOURCE_DIR}/src/main.cpp
        ${CMAKE_SOURCE_DIR}/src/input.hpp
    )

    set_target_properties(NightmoonGD.Click_between_frames_${ABI} PROPERTIES
        COMPILE_FLAGS "-DANDROID_ABI=${ABI}"
        OUTPUT_NAME "NightmoonGD.Click_between_frames.${ARCH_SUFFIX}"
    )

    target_link_libraries(NightmoonGD.Click_between_frames_${ABI} log android)
endforeach()
