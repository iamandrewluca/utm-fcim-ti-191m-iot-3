#ifndef EMBEDDED_BARRIER_HPP
#define EMBEDDED_BARRIER_HPP

#include <Arduino.h>

enum Dir {
    UNDEFINED,
    LEFT,
    RIGHT,
};

// Use own constants for LOW and HIGH
// This makes reversing them faster
// In debug mode is easier with them reversed
#define B_HIGH HIGH
#define B_LOW LOW

class Barrier {
public:
    explicit Barrier(int left = B_HIGH, int right = B_HIGH);

    void setCurrent(int left, int right);

    Dir getDirection();

private:
    int leftPrevious = B_HIGH;
    int rightPrevious = B_HIGH;
    int leftCurrent = B_HIGH;
    int rightCurrent = B_HIGH;
};

#endif //EMBEDDED_BARRIER_HPP
