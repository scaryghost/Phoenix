#ifndef ETSAI_PHOENIX_GAME_SINGLE
#define ETSAI_PHOENIX_GAME_SINGLE

#include "Phoenix/Engine/Weapon.h"
#include "Phoenix/Engine/Pawn.h"

namespace etsai {
namespace phoenix {

/**
 * Default weapon the player starts with.
 * @author etsai
 */
class Single : public Weapon {
public:
    /**
     * Attach the weapon at the position (xPos, yPos) to the owner
     * @param   xPos    X coordinate to attach to
     * @param   yPos    Y coordinate to attach to
     * @param   owner   Owner of the weapon
     */
    Single(float xPos, float yPos, Pawn* owner);

    virtual void consumeAmmo();
    virtual void draw();
    /**
     * Spawn one SingleProj projectile
     */
    virtual void doFireEffect();
};

}   //namespace phoenix
}   //namespace etsai

#endif
