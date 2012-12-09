#include "Phoenix/Game/HumanPawn.h"

#include <cmath>

namespace etsai {
namespace phoenix {

using std::max;

/*
float meter;
    float maxMeter;
    float meterGainScale;
    float meterUsageRate;
    unsigned int cash;
    bool abilityActive;
    */
HumanPawn::HumanPawn(float xPos, float yPos) : Pawn(xPos, yPos), 
    meter(0), maxMeter(100), meterGainScale(1.0), meterUsageRate(10), cash(0), abilityActive(false),dir(Direction::NEUTRAL) {
}

void HumanPawn::gainMeter(float amount) {
    meter+= max<float>(amount * meterGainScale, maxMeter);
}

void HumanPawn::addCash(unsigned int amount) {
    cash+= amount;
}

void HumanPawn::activateAbility() {
    if (meter >= maxMeter) {
        abilityActive= true;
    }
}

void HumanPawn::setDirection(Direction dir) {
    this->dir= dir;
}

void HumanPawn::tick(double delta) {
    float xDelta(0), yDelta(0);
    Pawn::tick(delta);
    if (abilityActive) {
        meter-= max<float>(meterUsageRate * delta, 0.0);
        abilityActive= meter > 0.0;
    }
    if (dir == UP_LEFT || dir == UP || dir == UP_RIGHT) {
        yDelta-= 1;
    }
    if (dir == DOWN_LEFT || dir == DOWN || dir == DOWN_RIGHT) {
        yDelta+= 1;
    }
    if (dir == UP_LEFT || dir == LEFT || dir == DOWN_LEFT) {
        xDelta-= 1;
    }
    if (dir == UP_RIGHT || dir == RIGHT || dir == DOWN_RIGHT) {
        xDelta+= 1;
    }
    translate(xDelta, yDelta);
}

}
}