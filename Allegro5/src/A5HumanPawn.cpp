#include "Phoenix/Allegro5/A5HitBox.h"
#include "Phoenix/Allegro5/A5HumanPawn.h"

namespace etsai {
namespace phoenix {

A5HumanPawn::A5HumanPawn(float xPos, float yPos) : HumanPawn(xPos, yPos) {
    image= al_load_bitmap("Textures/Enemy-3.tga");
    imageHalfW= al_get_bitmap_width(image) / 2;
    imageHalfH= al_get_bitmap_height(image) / 2;

    hitbox= new A5HitBox(xPos, yPos);
    hitbox->addBoundaryPoint(-imageHalfW, -imageHalfH);
    hitbox->addBoundaryPoint(-imageHalfW, imageHalfH);
    hitbox->addBoundaryPoint(imageHalfW, imageHalfH);
    hitbox->addBoundaryPoint(imageHalfW, -imageHalfH);
}

A5HumanPawn::~A5HumanPawn() {
    delete hitbox;
    al_destroy_bitmap(image);
}


void A5HumanPawn::draw() {
    al_draw_rotated_bitmap(image, imageHalfW, imageHalfH, xPos, yPos, rotation, 0);
}

}   //namespace phoenix
}   //namespace etsai