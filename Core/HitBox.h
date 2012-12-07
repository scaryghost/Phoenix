#ifndef ETSAI_PHOENIX_CORE_HITBOX
#define ETSAI_PHOENIX_CORE_HITBOX

#include "Phoenix/Core/Object.h"

#include <tuple>
#include <vector>

namespace etsai {
namespace phoenix {

class HitBox : public Object {
public:
    HitBox(float xPos, float yPos) : Object(xPos, yPos) { }

    bool collide(HitBox const *box) const;
    bool inside(float x, float y) const;

    void rotate(float radians);
    void addBoundaryPoint(float xOffset, float yOffset);
    void removeLastPoint();

protected:
    std::vector<std::tuple<float, float> > boundaryOffsets;
};

}
}

#endif