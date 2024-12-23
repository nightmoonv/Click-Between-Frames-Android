#ifndef INCLUDES_HPP
#define INCLUDES_HPP

// Librer�as est�ndar
#include <jni.h>
#include <android/log.h>
#include <unistd.h>
#include <functional>

// Macros de log para depuraci�n
#define LOG_TAG "ModIncludes"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

// Otras configuraciones globales pueden ir aqu�

#endif // INCLUDES_HPP