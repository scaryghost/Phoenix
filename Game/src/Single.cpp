#include "Phoenix/Core/Common.h"
#include "Phoenix/Game/Single.h"
#include "Phoenix/Game/SingleProj.h"

namespace etsai {
namespace phoenix {

Single::Single(float xPos, float yPos, Pawn* owner) : Weapon(xPos, yPos, owner) {
    ammo= 100;
    maxAmmo= 100;
    fireRate= 1;
    cooldown= 0.0;
    index= 0;
}

void Single::consumeAmmo() {
    ammo--;
}
void Single::doFireEffect() {
    Common::spawn("SingleProj", owner->getXPos(), owner->getYPos(), owner->getRotation());
}

}
}