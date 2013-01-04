#include "Phoenix/Core/Common.h"
#include "Phoenix/Game/Dosh.h"
#include "Phoenix/Game/HumanPawn.h"

#include "allegro5/allegro_primitives.h"

namespace etsai {
namespace phoenix {

Dosh::Dosh(float xPos, float yPos, unsigned int value) : SingleProj(xPos, yPos, PI/2), value(value) {
}

void Dosh::touch(Actor* actor) {
    HumanPawn* humanP= dynamic_cast<HumanPawn*>(actor);
    if (humanP != NULL) {
        humanP->addCash(value);
        destroy= true;
    }
}

void Dosh::draw() {
    al_draw_filled_circle(xPos, yPos, 10, al_map_rgb(255, 0, 0));
}

}
}
