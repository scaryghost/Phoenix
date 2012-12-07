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
     * Checks if the actor has collided with any spawned actors.  Actors that have collided with 
     * each other will have their touch functions called.
     * @param   actor   Actor to check
     */
    static void checkCollisions(Actor* actor);

    /**
     * Creates an actor at the specific location
     * @param   xPos    X coordinate of the Actor
     * @param   yPos    Y coordinate of the Actor
     */
    Actor(float xPos, float yPos) : Object(xPos, yPos) {
        actors.insert(this);
    }
    /**
     * Class destructor
     */
    virtual ~Actor() {
        actors.erase(this);
    }

    /**
     * Rotate the actor as well as the actor's hitbox by a fixed amount
     * @note Input is in radians
     * @param   radians     The amount, in radians, to rotate the hit box by
     */
    virtual void rotate(float radians) {
        Object::rotate(radians);
        hitbox->rotate(radians);
    }

    /**
     * Called when another actor has touched this actor
     * @param   actor   The actor that touched this actor
     */
    virtual void touch(Actor* actor)= 0;

protected:
    HitBox *hitbox;     ///< Hit box around the actor

private:
    static std::unordered_set<Actor*> actors;   ///< Set of all spawned actors
};

}   //namespace phoenix
}   //namespace etsai

#endif