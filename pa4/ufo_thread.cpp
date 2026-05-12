#include "ufo_thread.h"
//constructor
UfoThread::UfoThread(Ufo *pUfo) {
    this->flyThread = nullptr;
    this->isFlying = false;

}
//destructor
UfoThread::~UfoThread() {
}

void UfoThread::runner(const float x,const float y,const float height,const int speed) {
}

void UfoThread::startUfo(const float x,const float y,const float height,const int speed) {
}

bool UfoThread::getIsFlying() const {
    return isFlying;
}
