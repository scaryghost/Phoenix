#include "Phoenix/Game/Single.h"

namespace etsai {
namespace phoenix {

Single::Single(Pawn* owner) : Weapon(owner) {
    ammo= 100;
    maxAmmo= 100;
    fireRate= 1;
    cooldown= 0.0;
    index= 0;
}

void Single::consumeAmmo() {
    ammo--;
}
void Single::draw() {
}

}
}