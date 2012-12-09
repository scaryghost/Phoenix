#ifndef ETSAI_PHOENIX_GAME_PROJECTILE
#define ETSAI_PHOENIX_GAME_PROJECTILE

#include "Phoenix/Core/Actor.h"

namespace etsai {
namespace phoenix {

class Projectile : public Actor {
public:
    Projectile(float xPos, float yPos);

    virtual void touch(Actor* actor);
    virtual void tick(double delta);

protected:
    float damage;
};

}   //namespace phoenix
}   //namespace etsai

#endif