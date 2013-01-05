#ifndef ETSAI_PHOENIX_GAME_SINGLEPROJ
#define ETSAI_PHOENIX_GAME_SINGLEPROJ

#include "Phoenix/Engine/Pawn.h"
#include "Phoenix/Engine/Projectile.h"

namespace etsai {
namespace phoenix {

class SingleProj : public Projectile {
public:
    SingleProj(float xPos, float yPos, float rotation);

    virtual void tick(double delta);
    virtual void draw();

protected:
    float velocity;
    float rotation;
    float xVel, yVel;
    Pawn* owner;
};

}   //namespace etsai
}   //namespace phoenix

#endif
