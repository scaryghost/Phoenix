#ifndef ETSAI_PHOENIX_CORE_ACTOR
#define ETSAI_PHOENIX_CORE_ACTOR

#include "Phoenix/Core/Object.h"
#include "Phoenix/Engine/HitBox.h"

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
     * Creates an actor at the specific location
     * @param   xPos    X coordinate of the Actor
     * @param   yPos    Y coordinate of the Actor
     */
    Actor(float xPos, float yPos);
    /**
     * Class destructor
     */
    virtual ~Actor();

    /**
     * Checks if the actor has collided with any spawned actors.  Actors that have collided with 
     * each other will have their touch functions called.
     */
    void checkCollisions();

    /**
     * Move the object and hitbox with the specified horizontal and vertical offsets
     * @param   xOffset     Horizontal offset to move the hitbox and object
     * @param   yOffset     Vertical offset to move the hitbox and object
     */
    virtual void translate(float xOffset, float yOffset);
    /**
     * Rotate the actor as well as the actor's hitbox by a fixed amount
     * @note Input is in radians
     * @param   radians     The amount, in radians, to rotate the hit box and object by
     */
    virtual void rotate(float radians);

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
