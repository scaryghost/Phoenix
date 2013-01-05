#ifndef ETSAI_PHOENIX_GAME_SINGLEPROJ
#define ETSAI_PHOENIX_GAME_SINGLEPROJ

#include "Phoenix/Engine/Pawn.h"
#include "Phoenix/Engine/Projectile.h"

namespace etsai {
namespace phoenix {

/**
 * Class of the default projectile
 * @author etsai
 */
class SingleProj : public Projectile {
public:
    /**
     * Spawn the projectile at the position (xPos, yPos) with the given rotation
     * @param   xPos    X coordinate to spawn at
     * @param   yPos    Y coordinate to spawn at
     * @param   rotation    Rotation of the projectile, in radians
     */
    SingleProj(float xPos, float yPos, float rotation);

    virtual void tick(double delta);
    virtual void draw();

protected:
    float velocity;         ///< Magnitude of the projectile's velocity
    float rotation;         ///< Current rotation of the projectile
    float xVel;             ///< X component of the velocity vector
    float yVel;             ///< Y component of the velocity vector
    Pawn* owner;            ///< Projectile's owner
};

}   //namespace etsai
}   //namespace phoenix

#endif
