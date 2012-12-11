#ifndef ETSAI_PHOENIX_GAME_SINGLEPROJ
#define ETSAI_PHOENIX_GAME_SINGLEPROJ

#include "Phoenix/Game/Pawn.h"
#include "Phoenix/Game/Projectile.h"

namespace etsai {
namespace phoenix {

class SingleProj : public Projectile {
public:
    SingleProj(float xPos, float yPos, float rotation);

    virtual void tick(double delta);

protected:
    float velocity;
    float rotation;
    float xVel, yVel;
    Pawn* owner;
};

}   //namespace etsai
}   //namespace phoenix

#endif