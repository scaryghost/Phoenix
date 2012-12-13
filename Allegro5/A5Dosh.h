#ifndef ETSAI_PHOENIX_ALLEGRO_A5DOSH
#define ETSAI_PHOENIX_ALLEGRO_A5DOSH

#include "Phoenix/Game/Dosh.h"

namespace etsai {
namespace phoenix {

class A5Dosh: public Dosh {
    A5Dosh(float xPos, float yPos, unsigned int value);

    virtual void draw();
};

}   //namespace phoenix
}   //namespace etsai

#endif