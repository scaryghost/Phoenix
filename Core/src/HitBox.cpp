#include "Phoenix/Core/Hitbox.h"
#include "allegro5/allegro_primitives.h"

#include <cmath>
#include <stdexcept>

namespace etsai {
namespace phoenix {

using std::cos;
using std::sin;
using std::get;
using std::make_tuple;

bool HitBox::collide(HitBox const *box) const {
    bool collided= false;

    for(auto it= box->boundaryOffsets.begin(); !collided && it != box->boundaryOffsets.end(); it++) {
        collided= inside(get<0>(*it) + box->xPos, get<1>(*it) + box->yPos);
    }
    if (!collided) {
        for(auto it= boundaryOffsets.begin(); !collided && it != boundaryOffsets.end(); it++) {
            collided= box->inside(get<0>(*it) + xPos, get<1>(*it) + yPos);
        }
    }
    return collided;
}

bool HitBox::inside(float x, float y) const {
    size_t i, j= boundaryOffsets.size() - 1;
    bool oddNodes= false;

    for(i= 0; i < boundaryOffsets.size(); i++) {
        float xi, xj, yi, yj;

        xi= get<0>(boundaryOffsets[i]) + xPos;
        xj= get<0>(boundaryOffsets[j]) + xPos;
        yi= get<1>(boundaryOffsets[i]) + yPos;
        yj= get<1>(boundaryOffsets[j]) + yPos;
        if ((yi < y && yj >= y || yj < y && yi >= y) && (xi <= x || xj <= x)) {
            oddNodes^= (xi + (y - yi) / (yj - yi) * (xj - xi) < x);
        }
        j= i;
    }
    return oddNodes;
}

void HitBox::rotate(float radians) {
    for(auto it= boundaryOffsets.begin(); it != boundaryOffsets.end(); it++) {
        float xNew, yNew;
        xNew= get<0>(*it) * cos(radians) - get<1>(*it) * sin(radians);
        yNew= get<0>(*it) * sin(radians) + get<1>(*it) * cos(radians);
        *it= make_tuple(xNew, yNew);
    }
}

void HitBox::addBoundaryPoint(float xOffset, float yOffset) {
    boundaryOffsets.push_back(make_tuple(xOffset, yOffset));
}

void HitBox::removeLastPoint() {
    boundaryOffsets.pop_back();
}

void HitBox::draw() {
    auto prev= boundaryOffsets.end() - 1;
    for(auto it= boundaryOffsets.begin(); it != boundaryOffsets.end(); it++) {
        al_draw_line(xPos + get<0>(*prev), yPos + get<1>(*prev), xPos + get<0>(*it), yPos + get<1>(*it), al_map_rgb(0, 255, 0), 2.0);
        prev= it;
    }
}

}
}
