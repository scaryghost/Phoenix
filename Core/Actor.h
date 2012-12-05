#ifndef ETSAI_PHOENIX_CORE_ACTOR
#define ETSAI_PHOENIX_CORE_ACTOR

#include "Phoenix/Core/Object.h"

namespace etsai {
namespace phoenix {

class Actor : public Object {
public:
    Actor(int xPos, int yPos): Object() { this->xPos= xPos; this->yPos= yPos; }

    /**
     * Draw this actor on screen
     */
    virtual void draw()= 0;
protected:
    int xPos;
    int yPos;
};

}   //namespace phoenix
}   //namespace etsai

#endif