#include "ufo_thread.h"
//constructor
UfoThread::UfoThread(Ufo *pUfo): flyThread(nullptr), ufo(pUfo), isFlying(false){
}
//destructor
UfoThread::~UfoThread() {
    if (flyThread != nullptr) {
        if (flyThread->joinable()) {
            flyThread->join();
        }
        delete flyThread;
        flyThread = nullptr;
    }
}

void UfoThread::runner(const float x,const float y,const float height,const int speed) {
    isFlying = true; // Flug beginnt

    if (ufo != nullptr) {
        // Ruft die Fluglogik des UFOs auf (Vertical oder Ballistic)
        ufo->flyToDest(x, y, height, speed);
    }

    isFlying = false; // Flug beendet

}

void UfoThread::startUfo(const float x,const float y,const float height,const int speed) {
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

bool UfoThread::getIsFlying() const {
    return isFlying;
}
