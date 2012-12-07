#ifndef ETSAI_PHOENIX_CORE_ACTOR
#define ETSAI_PHOENIX_CORE_ACTOR

#include "Phoenix/Core/HitBox.h"
#include "Phoenix/Core/Object.h"

#include <unordered_set>

namespace etsai {
namespace phoenix {

/**
 * Base class for all objects that can interact with each other i.e. collide
 * @author etsai
 */
class Actor : public Object {
public:
    /**
     * Checks if the actor has collided with any active Actors.  Actors that have collided with 
     * each other will have their touch functions called.
     * @param   actor   Actor to check
     */
    static void checkCollisions(Actor* actor);

    /**
     * Creates an actor at the specific location
     * @param   xPos    X coordinate of the Actor
     * @param   yPos    Y coordinate of the Actor
     */
    Actor(float xPos, float yPos) : Object(xPos, yPos), angle(0.0) {
        actors.insert(this);
    }
    virtual ~Actor() {
        actors.erase(this);
    }

    void rotate(float radians) {
        hitbox->rotate(radians);
        angle+= radians;
    }

    /**
     * Called when another actor has touched this actor
     * @param   actor   The actor that touched this actor
     */
    virtual void touch(Actor* actor)= 0;

protected:
    HitBox *hitbox;
    float angle;

private:
    static std::unordered_set<Actor*> actors;
};

}   //namespace phoenix
}   //namespace etsai

#endif