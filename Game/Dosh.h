#ifndef ETSAI_PHOENIX_GAME_DOSH
#define ETSAI_PHOENIX_GAME_DOSH

#include "Phoenix/Engine/Actor.h"
#include "Phoenix/Game/SingleProj.h"

namespace etsai {
namespace phoenix {

/**
 * Money projectile that killed enemies may randomly spawn.
 * @author etsai
 */
class Dosh : public SingleProj {
public:
    /**
     * Spawn a dosh projectile at the given coordinates (xPos, yPos)
     * @param   xPos    X coordinate to spawn at
     * @param   yPos    Y coordinate to spawn at
     * @param   value   Amount of money the projectile will give
     */
    Dosh(float xPos, float yPos, unsigned int value);

    /**
     * If the Actor touching is a HumanPawn, give it some money
     * @param   actor   The Actor touching the dosh projectile
     */
    virtual void touch(Actor* actor);
    virtual void draw();

protected:
    unsigned int value;     //< Amount of money to give
};

}   //namespace phoenix
}   //namespace etsai

#endif
