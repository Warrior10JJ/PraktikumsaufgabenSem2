#ifndef PRAKTIKUM_UFO_THREAD_H
#define PRAKTIKUM_UFO_THREAD_H
#include <QObject>
#include <thread>
#include "ufo.h"

class UfoThread :public QObject{
    Q_OBJECT
        signals:
            void stopped(std::vector<float>);
private:
    std::thread* flyThread;
    Ufo* ufo;
    bool isFlying;

    void runner(const float x,const float y,const float height,const int speed) {
        isFlying = true;

        if (ufo != nullptr) {
            //flug von ufo vertical/ballistic aufrufen
            ufo->flyToDest(x, y, height, speed);
        }

        isFlying = false;
        emit stopped(ufo->getPosition());
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
        flyThread = new std::thread(&UfoThread::runner, this, x, y, height, speed);
    }

    bool getIsFlying() const {
        return isFlying;
    }
};
#endif //PRAKTIKUM_UFO_THREAD_H