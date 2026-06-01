#ifndef PRAKTIKUM_UFO_THREAD_H
#define PRAKTIKUM_UFO_THREAD_H
#include <thread>
#include "ufo.h"



class UfoThread {
private:
    std::thread* flyThread;
    Ufo* ufo;
    bool isFlying;

    void runner(const float x,const float y,const float height,const int speed) {
        isFlying = true; // Flug beginnt

        if (ufo != nullptr) {
            // Ruft die Fluglogik des UFOs auf (Vertical oder Ballistic)
            ufo->flyToDest(x, y, height, speed);
        }

        isFlying = false; // Flug beendet

    }

public:
    //constructor
    UfoThread(Ufo *pUfo): flyThread(nullptr), ufo(pUfo), isFlying(false){
    }
   //destructor
    ~UfoThread() {
        if (flyThread != nullptr) {
            if (flyThread->joinable()) {
                flyThread->join();
            }
            delete flyThread;
            flyThread = nullptr;
        }
    }

    void startUfo(const float x,const float y,const float height,const int speed) {
        isFlying = true;
        if (flyThread != nullptr) {
            if (flyThread->joinable()) {
                flyThread->join();
            }
            delete flyThread;
        }

        // Neuen Thread erstellen und runner-Funktion aufrufen
        // Da runner eine Member-Funktion ist, muss 'this' als Kontext mitgegeben werden
        flyThread = new std::thread(&UfoThread::runner, this, x, y, height, speed);
    }

    bool getIsFlying() const {
        return isFlying;
    }
};
#endif //PRAKTIKUM_UFO_THREAD_H
