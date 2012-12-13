#include "Phoenix/Allegro5/A5Dosh.h"

#include "allegro5/allegro_primitives.h"

namespace etsai {
namespace phoenix {

A5Dosh::A5Dosh(float xPos, float yPos, unsigned int value) : Dosh(xPos, yPos, value) {
}

void A5Dosh::draw() {
    al_draw_circle(xPos, yPos, 10, al_map_rgb(255, 0, 0));
}

}
}