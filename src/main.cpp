#include <jni.h>
#include "input.hpp"
#include <android/log.h>
#include <thread>
#include <atomic>
#include <chrono>

using namespace std::chrono;

// Estado del clic
ClickState clickState = {false, 0, high_resolution_clock::now()};
std::atomic<bool> running(true);

// Proceso de entrada con polling optimizado a alta frecuencia
void inputPollingThread() {
    auto lastTime = high_resolution_clock::now();
    while (running) {
        auto now = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(now - lastTime);

        // Solo procesar si ha pasado suficiente tiempo para un polling rate ultra alto
        if (duration.count() > 10) { // Más de 100,000 Hz (10 ns por ciclo)
            lastTime = now;

            // Leer el estado actual del clic
            clickState.isClicking = true; // Simula un clic activo (debe adaptarse a los eventos reales)

            // Procesar el clic
            handleClick(clickState);

            // Resetear el estado si el conteo es muy alto
            if (clickState.clickCount > 12) {
                resetClickState(clickState);
            }
        }
    }
}

// Inicializar el mod
extern "C" JNIEXPORT void JNICALL
Java_com_yourpackage_GameMod_initializeMod(JNIEnv *env, jobject thiz) {
    LOGD("Mod de Geometry Dash iniciado.");

    // Crear un hilo separado para el polling
    std::thread(inputPollingThread).detach();
}

// Procesar fotogramas (mantiene el mod activo)
extern "C" JNIEXPORT void JNICALL
Java_com_yourpackage_GameMod_processFrame(JNIEnv *env, jobject thiz) {
    // No se necesita procesamiento adicional aquí; todo ocurre en el hilo separado
}

// Finalizar el mod al salir
extern "C" JNIEXPORT void JNICALL
Java_com_yourpackage_GameMod_terminateMod(JNIEnv *env, jobject thiz) {
    running = false; // Detener el hilo de polling
    LOGD("Mod terminado.");
}
