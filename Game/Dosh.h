#ifndef ETSAI_PHOENIX_GAME_DOSH
#define ETSAI_PHOENIX_GAME_DOSH

#include "Phoenix/Engine/Actor.h"
#include "Phoenix/Game/SingleProj.h"

namespace etsai {
namespace phoenix {

class Dosh : public SingleProj {
public:
    Dosh(float xPos, float yPos, unsigned int value);

    virtual void touch(Actor* actor);
    virtual void draw();

protected:
    unsigned int value;
};

}   //namespace phoenix
}   //namespace etsai

#endif
