#ifndef INPUT_HPP
#define INPUT_HPP

#include <functional>
#include <android/log.h>
#include <unistd.h>

#define LOG_TAG "InputHandler"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

class InputHandler {
public:
    // Constructor
    InputHandler() = default;

    // Simula un clic en el juego
    void simulateClick() {
        LOGD("Simulando clic.");
        // Aquí puedes agregar la lógica personalizada para enviar eventos de clic
    }

    // Configura el intervalo de clics
    void setClickInterval(int fps) {
        if (fps <= 0) {
            LOGD("FPS inválidos: %d", fps);
            return;
        }
        frameInterval = 1000000 / fps; // Microsegundos por frame
        LOGD("Intervalo entre clics configurado a %d microsegundos.", frameInterval);
    }

    // Ejecuta la lógica de clics en un bucle
    void run() {
        while (true) {
            simulateClick();
            usleep(frameInterval);
        }
    }

private:
    int frameInterval = 0; // Intervalo entre clics en microsegundos
};

#endif // INPUT_HPP