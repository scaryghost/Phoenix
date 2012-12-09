#ifndef ETSAI_PHOENIX_ALLEGRO_A5HUMANPAWN
#define ETSAI_PHOENIX_ALLEGRO_A5HUMANPAWN

#include "allegro5/allegro.h"
#include "Phoenix/Game/HumanPawn.h"

namespace etsai {
namespace phoenix {

class A5HumanPawn : public HumanPawn {
public:
    A5HumanPawn(float xPos, float yPos);
    virtual ~A5HumanPawn();

    virtual void draw();

private:
    ALLEGRO_BITMAP *image;
    int imageHalfW, imageHalfH;

};

}   //namespace phoenix
}   //namespace etsai

#endif