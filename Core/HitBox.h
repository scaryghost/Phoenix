#ifndef ETSAI_PHOENIX_CORE_HITBOX
#define ETSAI_PHOENIX_CORE_HITBOX

#include "Phoenix/Core/Object.h"

#include <tuple>
#include <vector>

namespace etsai {
namespace phoenix {

/**
 * A polygon boundary representing a hit box for an Actor
 * @author etsai
 */
class HitBox : public Object {
public:
    /**
     * Create a hit box around the reference point (xPos, yPos)
     * @param   xPos    X coordinate of the hit box
     * @param   yPos    Y coordinate of the hit box
     */
    HitBox(float xPos, float yPos) : Object(xPos, yPos) { }

    /**
     * Determines if the two hit boxes have collided.
     * @todo Fix bug for case when hit boxes overlap but no corner points lay inside the bounded areas
     * @return True if the hit boxes have collided
     */
    bool collide(HitBox const *box) const;
    /**
     * Determines if the given point lays on or inside the hit box
     * @param   x   X coordinate of the point
     * @param   y   Y coordinate of the point
     * @return True if the point is on or inside the hit box
     */
    bool inside(float x, float y) const;

    /**
     * Rotate the hit box by a fixed amount
     * @note Input is in radians
     * @param   radians     The amount, in radians, to rotate the hit box by
     */
    virtual void rotate(float radians);
    /**
     * Added another point to the boundary
     * @param   xOffset     Horizontal offset from the hit boxes reference point
     * @param   yOffset     Vertical offset from the hit boxes reference point
     */
    void addBoundaryPoint(float xOffset, float yOffset);
    /**
     * Remove the last added boundary point
     */
    void removeLastPoint();

    virtual void draw();
protected:
    std::vector<std::tuple<float, float> > boundaryOffsets; ///< List of the boundary points offsets, stored as (xOffset, yOffset)
};

}   //namespace phoenix
}   //namespace etsai

#endif
