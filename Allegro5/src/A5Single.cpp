#include "Phoenix/Allegro5/A5Single.h"
#include "Phoenix/Allegro5/A5SingleProj.h"

#include "Phoenix/Core/Common.h"

namespace etsai {
namespace phoenix {

A5Single::A5Single(float xPos, float yPos, Pawn *owner) : Single(xPos, yPos, owner) {
}

void A5Single::doFireEffect() {
    new A5SingleProj(xPos, yPos, owner->getRotation());
}

}
}