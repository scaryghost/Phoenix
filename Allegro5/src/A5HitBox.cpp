#include "allegro5/allegro_primitives.h"
#include "Phoenix/Allegro5/A5HitBox.h"

namespace etsai {
namespace phoenix {

using std::get;

A5HitBox::A5HitBox(float xPos, float yPos) : HitBox(xPos, yPos) {
}

void A5HitBox::draw() {
    auto prev= boundaryOffsets.end() - 1;
    for(auto it= boundaryOffsets.begin(); it != boundaryOffsets.end(); it++) {
        al_draw_line(xPos + get<0>(*prev), yPos + get<1>(*prev), xPos + get<0>(*it), yPos + get<1>(*it), al_map_rgb(0, 255, 0), 2.0);
        prev= it;
    }
}

}   //namespace phoenix
}   //namespace etsai