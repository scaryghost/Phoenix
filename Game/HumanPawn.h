#ifndef ETSAI_PHOENIX_GAME_HUMANPAWN
#define ETSAI_PHOENIX_GAME_HUMANPAWN

#include "Phoenix/Game/Pawn.h"

namespace etsai {
namespace phoenix {

class HumanPawn : public Pawn {
public:
    HumanPawn(float xPos, float yPos);

    void gainMeter(float amount);
    void addCash(unsigned int amount);
    void activateAbility();
    virtual void tick(double delta);

protected:
    float meter;
    float maxMeter;
    float meterGainScale;
    float meterUsageRate;
    unsigned int cash;
    bool abilityActive;
};

}   //namespace phoenix
}   //namespace etsai

#endif