#ifndef INCLUDES_HPP
#define INCLUDES_HPP

// Librerías estándar
#include <jni.h>
#include <android/log.h>
#include <unistd.h>
#include <functional>

// Macros de log para depuración
#define LOG_TAG "ModIncludes"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

// Otras configuraciones globales pueden ir aquí

#endif // INCLUDES_HPP