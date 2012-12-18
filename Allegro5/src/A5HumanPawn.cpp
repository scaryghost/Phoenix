#include "Phoenix/Allegro5/A5HitBox.h"
#include "Phoenix/Allegro5/A5HumanPawn.h"

#include "Phoenix/Game/Single.h"

namespace etsai {
namespace phoenix {

using std::make_pair;

extern "C" __declspec(dllexport) HumanPawn* __cdecl createHumanPawn(float xPos, float yPos) {
    return new A5HumanPawn(xPos, yPos);
}

extern "C" __declspec(dllexport) void __cdecl destroyHumanPawn(HumanPawn *pawn) {
    delete pawn;
}

A5HumanPawn::A5HumanPawn(float xPos, float yPos) : HumanPawn(xPos, yPos) {
    std::cerr << "Attemping to load image" << std::endl;
    image= al_load_bitmap("Textures/P1-Ship.tga");
    std::cerr << "Loaded image" << std::endl;
    imageHalfW= al_get_bitmap_width(image) / 2;
    imageHalfH= al_get_bitmap_height(image) / 2;
/*
    hitbox= new A5HitBox(xPos, yPos);
    hitbox->addBoundaryPoint(-imageHalfW, -imageHalfH);
    hitbox->addBoundaryPoint(-imageHalfW, imageHalfH);
    hitbox->addBoundaryPoint(imageHalfW, imageHalfH);
    hitbox->addBoundaryPoint(imageHalfW, -imageHalfH);
    */
    Weapon* defaultWeapon= new Single(xPos, yPos - imageHalfH, this);
    weapons.insert(make_pair(defaultWeapon->getWeaponIndex(), defaultWeapon));
    currentWeapon= weapons.begin();
    
}

A5HumanPawn::~A5HumanPawn() {
    //delete hitbox;
    al_destroy_bitmap(image);
}


void A5HumanPawn::draw() {
    //al_draw_rotated_bitmap(image, imageHalfW, imageHalfH, xPos, yPos, rotation, 0);
}

}   //namespace phoenix
}   //namespace etsai