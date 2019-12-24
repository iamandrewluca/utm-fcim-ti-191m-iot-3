#include "Barrier.hpp"

Barrier::Barrier(int left, int right) {
    this->setCurrent(left, right);
}

void Barrier::setCurrent(int left, int right) {
    this->leftPrevious = this->leftCurrent;
    this->rightPrevious = this->rightCurrent;
    this->leftCurrent = left;
    this->rightCurrent = right;
}

Dir Barrier::getDirection() {
    if (this->leftPrevious == B_LOW && this->rightPrevious == B_LOW) {
        if (this->leftCurrent == B_LOW && this->rightCurrent == B_HIGH) {
            return LEFT;
        }

        if (this->leftCurrent == B_HIGH && this->rightCurrent == B_LOW) {
            return RIGHT;
        }
    }

    return UNDEFINED;
}
