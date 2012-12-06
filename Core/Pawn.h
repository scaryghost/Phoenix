#ifndef ETSAI_PHOENIX_CORE_PAWN
#define ETSAI_PHOENIX_CORE_PAWN

#include "Phoenix/Core/Actor.h"

namespace etsai {
namespace phoenix {

class Pawn : public Actor {
public:
    Pawn(int xPos, int yPos);
    virtual ~Pawn();

    virtual void takeDamage(float damage) { health -= damage; }
    virtual void tick(double delta) {
        Actor::tick(delta);
        destroy= (health <= 0);
    }
protected:
    float health;
};

}   //namespace phoenix
}   //namespace etsai

#endif