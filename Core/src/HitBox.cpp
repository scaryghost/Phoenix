#include "Phoenix/Core/Hitbox.h"

#include <cmath>
#include <stdexcept>

namespace etsai {
namespace phoenix {

using std::cos;
using std::sin;
using std::get;
using std::make_tuple;
using std::vector;

bool HitBox::collide(HitBox const *box) const {
    throw std::runtime_error("Not yet implemented!");
}

void HitBox::rotate(float radians) {
    for(auto it= boundaryOffsets.begin(); it != boundaryOffsets.end(); it++) {
        float xNew, yNew;
        xNew= get<0>(*it) * cos(radians) - get<1>(*it) * sin(radians);
        yNew= get<0>(*it) * sin(radians) + get<1>(*it) * cos(radians);
        *it= make_tuple(xNew, yNew);
    }
}

void HitBox::translate(float xOffset, float yOffset) {
    moveXAxis(xOffset);
    moveYAxis(yOffset);
}

void HitBox::addBoundaryPoint(float xOffset, float yOffset) {
    boundaryOffsets.push_back(make_tuple(xOffset, yOffset));
}

void HitBox::removeLastPoint() {
    boundaryOffsets.pop_back();
}

}
}