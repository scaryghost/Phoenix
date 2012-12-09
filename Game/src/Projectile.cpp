#include "Phoenix/Game/Projectile.h"

#include "Phoenix/Game/Pawn.h"

namespace etsai {
namespace phoenix {

Projectile::Projectile(float xPos, float yPos) : Actor(xPos, yPos) {
}

void Projectile::touch(Actor* actor) {
    Pawn* pawn= dynamic_cast<Pawn*>(actor);
    if (pawn != NULL) {
        pawn->takeDamage(damage);
        destroy= true;
    }
}

void Projectile::tick(double delta) {
    Object::tick(delta);
    checkCollisions();
}

}
}