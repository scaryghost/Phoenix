#ifndef ETSAI_PHOENIX_GAME_SINGLE
#define ETSAI_PHOENIX_GAME_SINGLE

#include "Phoenix/Game/Weapon.h"

namespace etsai {
namespace phoenix {

class Single : public Weapon {
public:
    Single();

    virtual void consumeAmmo();
    virtual void draw();
};

}   //namespace phoenix
}   //namespace etsai

#endif