#ifndef ETSAI_PHOENIX_GAME_SINGLE
#define ETSAI_PHOENIX_GAME_SINGLE

#include "Phoenix/Engine/Weapon.h"
#include "Phoenix/Engine/Pawn.h"

namespace etsai {
namespace phoenix {

class Single : public Weapon {
public:
    Single(float xPos, float yPos, Pawn* owner);

    virtual void consumeAmmo();
    virtual void draw();
    virtual void doFireEffect();
};

}   //namespace phoenix
}   //namespace etsai

#endif
