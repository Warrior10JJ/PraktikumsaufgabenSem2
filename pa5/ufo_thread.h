#ifndef PRAKTIKUM_UFO_THREAD_H
#define PRAKTIKUM_UFO_THREAD_H
#include <thread>
#include "ufo.h"



class UfoThread {
private:
    std::thread* flyThread;
    Ufo* ufo;
    bool isFlying;
    void runner(const float x,const float y,const float height,const int speed);
public:
    UfoThread(Ufo* pUfo);
    ~UfoThread();

    void startUfo(const float x,const float y,const float height,const int speed);
    bool getIsFlying() const;
};
#endif //PRAKTIKUM_UFO_THREAD_H
