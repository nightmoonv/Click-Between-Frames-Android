#ifndef INPUT_HPP
#define INPUT_HPP

#include <android/log.h>
#include <chrono>
#include <thread>

#define LOG_TAG "ModIncludes"  // Asegúrate de que sea único

// Esta macro nos permite imprimir mensajes para depuración
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

// Definimos una estructura para manejar el estado de los clics
struct ClickState {
    bool isClicking;
    int clickCount;
    std::chrono::high_resolution_clock::time_point lastClickTime;
};

// Aumenta el polling rate de los clics
void handleClick(ClickState& clickState) {
    using namespace std::chrono;

    // Si el jugador está clickeando
    if (clickState.isClicking) {
        auto now = high_resolution_clock::now();
        auto timeSinceLastClick = duration_cast<milliseconds>(now - clickState.lastClickTime).count();

        // Si ha pasado más de un tiempo mínimo entre clics, incrementamos el contador
        if (timeSinceLastClick > 10) {  // Ajusta este valor para cambiar la frecuencia de clics
            clickState.clickCount++;
            clickState.lastClickTime = now;

            // Aquí podemos aplicar un "boost" a los CPS cuando hay mucho spam
            if (clickState.clickCount > 8) {  // Si el jugador está haciendo spam de clics
                clickState.clickCount = 12;  // Aumentamos el CPS a 12, por ejemplo
            }

            // Imprimir el número de CPS por consola para depuración
            LOGD("CPS: %d", clickState.clickCount);
        }
    }
}

// Resetea el contador de clics, por ejemplo cuando el jugador deja de hacer spam
void resetClickState(ClickState& clickState) {
    clickState.clickCount = 0;
}

#endif  // INPUT_HPP
