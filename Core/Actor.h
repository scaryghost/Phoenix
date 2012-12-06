#ifndef ETSAI_PHOENIX_CORE_ACTOR
#define ETSAI_PHOENIX_CORE_ACTOR

#include "Phoenix/Core/Object.h"

#include <unordered_set>

namespace etsai {
namespace phoenix {

/**
 * Base class that all objects that can be displayed on the screen are derived from
 * @author etsai
 */
class Actor : public Object {
public:
    /**
     * Checks if the actor has collided with any active Actors.  Actors that have collided with 
     * each other will have their touch functions called.
     * @param   actor   Actor to check
     */
    static void checkCollitions(Actor* actor);
    /** Draws all spawned actors */
    static void drawActors();

    /**
     * Creates an actor at the specific location
     * @param   xPos    X coordinate of the Actor
     * @param   yPos    Y coordinate of the Actor
     */
    Actor(float xPos, float yPos) : Object(),xPos(xPos),yPos(yPos),active(true) {
        actors.insert(this);
        activeActors.insert(this);
    }
    virtual ~Actor() {
        actors.erase(this);
        activeActors.erase(this);
    }

    void moveXAxis(float offset) { xPos += offset; }
    void moveYAxis(float offset) { yPos += offset; }
    void setActive() { active= true; activeActors.insert(this); }
    void setInactive() { active= false; activeActors.erase(this); }

    /**
     * Draw this actor on screen
     */
    virtual void draw()= 0;
    /**
     * Called when another actor has touched this actor
     * @param   actor   The actor that touched this actor
     */
    virtual void touch(Actor* actor)= 0;

protected:
    float xPos;
    float yPos;

private:
    static std::unordered_set<Actor*> activeActors;
    static std::unordered_set<Actor*> actors;

    bool active;
};

}   //namespace phoenix
}   //namespace etsai

#endif