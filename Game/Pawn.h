#ifndef ETSAI_PHOENIX_GAME_PAWN
#define ETSAI_PHOENIX_GAME_PAWN

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
    /**
     * Class destructor
     */
    virtual ~Pawn() { }

    /**
     * Restores health to the pawn, not exceeding the maximum amount
     * @param   amount  Amound of health to given as a positive number
     */
    void giveHealth(float amount) { health= std::max<float>(healthMax, health + std::fabs(amount)); }
    /**
     * Applies damage to the given pawn
     * @param   damage  Amount the pawn takes as a positive number
     */
    virtual void takeDamage(float damage) { health -= std::fabs(damage); }
    virtual void touch(Actor *actor) { }
    virtual void tick(double delta) {
        Actor::tick(delta);
        destroy= (health <= 0);
    }
protected:
    float health;           ///< Current health of the pawn
    float healthMax;        ///< Maximum health of the pawn
};

}   //namespace phoenix
}   //namespace etsai

#endif