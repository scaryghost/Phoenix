#include "Phoenix/Game/HumanPawn.h"

#include "Phoenix/Engine/HitBox.h"
#include "Phoenix/Game/Single.h"

#include <cmath>

namespace etsai {
namespace phoenix {

using std::max;

HumanPawn::HumanPawn(float xPos, float yPos) : Pawn(xPos, yPos), 
    meter(0), maxMeter(100), meterGainScale(1.0), meterUsageRate(10), cash(0), abilityActive(false),dir(Direction::NEUTRAL) {
    image= al_load_bitmap("Textures/P1-Ship.tga");
    imageHalfW= al_get_bitmap_width(image) / 2;
    imageHalfH= al_get_bitmap_height(image) / 2;

    hitbox= new HitBox(xPos, yPos);
    hitbox->addBoundaryPoint(-imageHalfW, -imageHalfH);
    hitbox->addBoundaryPoint(-imageHalfW, imageHalfH);
    hitbox->addBoundaryPoint(imageHalfW, imageHalfH);
    hitbox->addBoundaryPoint(imageHalfW, -imageHalfH);

    Weapon* defaultWeapon= new Single(xPos, yPos - imageHalfH, this);
    weapons[defaultWeapon->getWeaponIndex()]= defaultWeapon;
    currentWeapon= weapons.begin();
}

HumanPawn::~HumanPawn() {
   delete hitbox;
   al_destroy_bitmap(image); 
}

void HumanPawn::startFiring() {
    isFiring= true;
}

void HumanPawn::stopFiring() {
    isFiring= false;
}


void HumanPawn::switchToWeapon(int weaponIndex) {
    currentWeapon= weapons.find(weaponIndex);
}

void HumanPawn::nextWeapon() {
    currentWeapon++;
    if (currentWeapon == weapons.end()) {
        currentWeapon= weapons.begin();
    }
}

void HumanPawn::prevWeapon() {
    currentWeapon--;
    if (currentWeapon == weapons.begin()) {
        currentWeapon= weapons.end();
    }
}

void HumanPawn::gainMeter(float amount) {
    meter+= max<float>(amount * meterGainScale, maxMeter);
}

void HumanPawn::addCash(unsigned int amount) {
    cash+= amount;
}

void HumanPawn::activateAbility() {
    if (meter >= maxMeter) {
        abilityActive= true;
    }
}

void HumanPawn::setDirection(Direction dir) {
    this->dir= dir;
}

void HumanPawn::translate(float xOffset, float yOffset) {
    Pawn::translate(xOffset, yOffset);
    for(auto it= weapons.begin(); it != weapons.end(); it++) {
        it->second->translate(xOffset, yOffset);
    }
}

void HumanPawn::tick(double delta) {
    float xDelta(0), yDelta(0);
    Pawn::tick(delta);
    if (isFiring) {
        currentWeapon->second->fire();
    }
    if (abilityActive) {
        meter-= max<float>(meterUsageRate * delta, 0.0);
        abilityActive= meter > 0.0;
    }
    if (dir == UP_LEFT || dir == UP || dir == UP_RIGHT) {
        yDelta-= 1;
    }
    if (dir == DOWN_LEFT || dir == DOWN || dir == DOWN_RIGHT) {
        yDelta+= 1;
    }
    if (dir == UP_LEFT || dir == LEFT || dir == DOWN_LEFT) {
        xDelta-= 1;
    }
    if (dir == UP_RIGHT || dir == RIGHT || dir == DOWN_RIGHT) {
        xDelta+= 1;
    }
    translate(xDelta, yDelta);
}

void HumanPawn::draw() {
    al_draw_rotated_bitmap(image, imageHalfW, imageHalfH, xPos, yPos, rotation, 0);
}

}
}
