#include "ufo_thread.h"
//constructor
UfoThread::UfoThread(Ufo *pUfo): flyThread(nullptr), ufo(pUfo), isFlying(false){
}
//destructor
UfoThread::~UfoThread() {
    if (flyThread != nullptr) {
        if (flyThread->joinable()) {
            flyThread->join();//wenn threat noch nciht abgeschlossen, warten bis thrread geschlossen
        }
        delete flyThread;//thread löschen
        flyThread = nullptr;
        isFlying = false;
    }
}

void UfoThread::runner(const float x,const float y,const float height,const int speed) {
    isFlying = true;

    if (ufo != nullptr) {
        //flug von ufo vertical/ballistic aufrufen
        ufo->flyToDest(x, y, height, speed);
    }

    isFlying = false;

}

void UfoThread::startUfo(const float x,const float y,const float height,const int speed) {
    isFlying = true;

    if (flyThread != nullptr) {
        if (flyThread->joinable()) {
            flyThread->join();
        }
        delete flyThread;
    }

    flyThread = new std::thread(&UfoThread::runner, this, x, y, height, speed);
}

bool UfoThread::getIsFlying() const {
    return isFlying;
}
