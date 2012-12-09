#ifndef ETSAI_PHOENIX_GAME_HUMANPAWN
#define ETSAI_PHOENIX_GAME_HUMANPAWN

#include "Phoenix/Game/Pawn.h"

namespace etsai {
namespace phoenix {

class HumanPawn : public Pawn {
public:
    enum Direction {
        UP_LEFT= 0,
        UP,
        UP_RIGHT,
        LEFT,
        NEUTRAL,
        RIGHT,
        DOWN_LEFT,
        DOWN,
        DOWN_RIGHT
    };

    HumanPawn(float xPos, float yPos);

    void gainMeter(float amount);
    void addCash(unsigned int amount);
    void activateAbility();
    void setDirection(Direction dir);
    virtual void tick(double delta);

protected:
    float meter;
    float maxMeter;
    float meterGainScale;
    float meterUsageRate;
    unsigned int cash;
    bool abilityActive;
    Direction dir;
};

}   //namespace phoenix
}   //namespace etsai

#endif