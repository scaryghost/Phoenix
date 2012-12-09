#ifndef ETSAI_PHOENIX_ALLEGRO_A5HITBOX
#define ETSAI_PHOENIX_ALLEGRO_A5HITBOX

#include "Phoenix/Core/HitBox.h"

namespace etsai {
namespace phoenix {

class A5HitBox : public HitBox {
public:
    A5HitBox(float xPos, float yPos);

    virtual void draw();
};

}   //namespace phoenix
}   //namespace etsai

#endif