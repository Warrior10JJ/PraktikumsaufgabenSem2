#ifndef PRAKTIKUM_UFO_THREAD_H
#define PRAKTIKUM_UFO_THREAD_H
#include <thread>
#include "ufo.h"


class UfoThread {
private:
    std::thread* flyThread;
    Ufo* ufo;
    bool isFlying;
public:
    UfoThread(Ufo* pUfo);
    ~UfoThread();
    void runner(const float x,const float y,const float height,const int speed);
    void startUfo(const float x,const float y,const float height,const int speed);
    bool getIsFlying() const;
};
#endif //PRAKTIKUM_UFO_THREAD_H
