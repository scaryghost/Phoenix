#ifndef ETSAI_PHOENIX_CORE_ACTOR
#define ETSAI_PHOENIX_CORE_ACTOR

#include "Phoenix/Core/Object.h"

#include <unordered_set>

namespace etsai {
namespace phoenix {

/**
 * Base class that all objects that can be displayed on the screen are 
 * derived from
 * @author etsai
 */
class Actor : public Object {
public:
    /** Draws all spawned actors */
    static void drawActors();

    /**
     * Creates an actor at the specific location
     * @param   xPos    X coordinate of the Actor
     * @param   yPos    Y coordinate of the Actor
     */
    Actor(int xPos, int yPos);
    ~Actor();

    /**
     * Draw this actor on screen
     */
    virtual void draw()= 0;

protected:
    static std::unordered_set<Actor*> actors;

    int xPos;
    int yPos;
};

}   //namespace phoenix
}   //namespace etsai

#endif