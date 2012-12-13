#include "Phoenix/Game/Weapon.h"

#include <cmath>

namespace etsai {
namespace phoenix {

using std::max;

Weapon::Weapon(float xPos, float yPos, Pawn* owner) : Object(xPos, yPos), owner(owner) {
}

void Weapon::fire() {
    if (canFire()) {
        cooldown= fireRate;
        doFireEffect();
        consumeAmmo();
    }
}

void Weapon::setWeaponIndex(int index) {
    this->index= index;
}

void Weapon::refillAmmo(int amount) {
    ammo= max<float>(maxAmmo, ammo + amount);
}

bool Weapon::canFire() const {
    return cooldown <= 0 && hasAmmo();
}

bool Weapon::hasAmmo() const {
    return ammo > 0;
}

int Weapon::getAmmoCount() const {
    return ammo;
}

int Weapon::getMaxAmmo() const {
    return maxAmmo;
}

int Weapon::getWeaponIndex() const {
    return index;
}

void Weapon::tick(double delta) {
    Object::tick(delta);
    cooldown-= delta;
}

}   //namespace phoenix
}   //namespace etsai