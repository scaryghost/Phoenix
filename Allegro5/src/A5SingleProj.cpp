#include "Phoenix/Allegro5/A5SingleProj.h"
#include "Phoenix/Allegro5/A5HitBox.h"

namespace etsai {
namespace phoenix {

extern "C" __declspec(dllexport) SingleProj* __cdecl createSingleProj(float xPos, float yPos, float rotation) {
    return new A5SingleProj(xPos, yPos, rotation);
}

extern "C" __declspec(dllexport) void __cdecl destroySingleProj(SingleProj *proj) {
    delete proj;
}

A5SingleProj::A5SingleProj(float xPos, float yPos, float rotation) : SingleProj(xPos, yPos, rotation) {
    hitbox= new A5HitBox(xPos, yPos);
    hitbox->addBoundaryPoint(-4, 20);
    hitbox->addBoundaryPoint(4, 20);
    hitbox->addBoundaryPoint(4, -20);
    hitbox->addBoundaryPoint(-4, -20);
    hitbox->rotate(rotation);
}

void A5SingleProj::draw() {

}

}
}