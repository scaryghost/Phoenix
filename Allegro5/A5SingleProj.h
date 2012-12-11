#ifndef ETSAI_PHOENIX_GAME_A5SINGLEPROJ
#define ETSAI_PHOENIX_GAME_A5SINGLEPROJ

#include "Phoenix/Game/SingleProj.h"

namespace etsai {
namespace phoenix {

class A5SingleProj : public SingleProj {
public:
    A5SingleProj(float xPos, float yPos, float rotation);

    virtual void draw();
};

}   //namespace phoenix
}   //namespace etsai

#endif