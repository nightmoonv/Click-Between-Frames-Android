cmake_minimum_required(VERSION 3.10)

project(ClickAnywhere)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(ANDROID_NDK C:/AndroidNDK/android-ndk-r27c)

set(CMAKE_TOOLCHAIN_FILE ${ANDROID_NDK}/build/cmake/android.toolchain.cmake)

set(ANDROID_ABIS "armeabi-v7a" "arm64-v8a")
set(ANDROID_PLATFORM android-21)

foreach(ABI IN LISTS ANDROID_ABIS)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${ABI})

    add_library(ClickAnywhere_${ABI} SHARED ClickAnywhere.cpp)

    set_target_properties(ClickAnywhere_${ABI} PROPERTIES
        COMPILE_FLAGS "-DANDROID_ABI=${ABI}"
        OUTPUT_NAME "ClickAnywhere"
    )

    target_link_libraries(ClickAnywhere_${ABI} log android)
endforeach()
