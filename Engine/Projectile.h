#ifndef ETSAI_PHOENIX_GAME_PROJECTILE
#define ETSAI_PHOENIX_GAME_PROJECTILE

#include "Phoenix/Engine/Actor.h"

namespace etsai {
namespace phoenix {

/**
 * Base class all projectiles derive from
 * @author etsai
 */
class Projectile : public Actor {
public:
    /**
     * Spawn a projectile at the given coordinates (xPos, yPos)
     * @param   xPos    X coordinate to spawn at
     * @param   yPos    Y coordinate to spawn at
     */
    Projectile(float xPos, float yPos);

    virtual void touch(Actor* actor);
    virtual void tick(double delta);

protected:
    float damage;       ///< Amount of damage to deal to a target
};

}   //namespace phoenix
}   //namespace etsai

#endif
