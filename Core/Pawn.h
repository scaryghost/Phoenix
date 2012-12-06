#ifndef ETSAI_PHOENIX_CORE_PAWN
#define ETSAI_PHOENIX_CORE_PAWN

#include <cmath>
#include "Phoenix/Core/Actor.h"

namespace etsai {
namespace phoenix {

/**
 * Base class for all pawns(players) in the game
 * @author etsai
 */
class Pawn : public Actor {
public:
    /**
     * Constructs a pawn, with health defaulted to 100
     * @param   xPos    Initial x position
     * @param   yPos    Initial y position
     */
    Pawn(float xPos, float yPos) : Actor(xPos, yPos), 
        health(100.0), healthMax(100.0) { }
    virtual ~Pawn() { }

    void giveHealth(float amount) { health= std::max<float>(healthMax, health + std::fabs(amount)); }
    /**
     * Applies damage to the given pawn
     * @param   damage  Amount the pawn takes as a positive number
     */
    virtual void takeDamage(float damage) { health -= std::fabs(damage); }
    virtual void tick(double delta) {
        Actor::tick(delta);
        destroy= (health <= 0);
    }
protected:
    float health;
    float healthMax;
};

}   //namespace phoenix
}   //namespace etsai

#endif