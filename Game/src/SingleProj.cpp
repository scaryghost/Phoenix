#include "Phoenix/Game/SingleProj.h"
#include "Phoenix/Core/Common.h"

#include <cmath>

#define PI 3.141592653589793238462643383279502

namespace etsai {
namespace phoenix {

using std::cos;
using std::sin;

SingleProj::SingleProj(float xPos, float yPos, float rotation) : Projectile(xPos, yPos), velocity(100.0), rotation(rotation) {
    xVel= velocity * cos(PI/2.0 - rotation);
    yVel= -velocity * sin(PI/2.0 - rotation);
}

void SingleProj::tick(double delta) {
    Projectile::tick(delta);
    translate(xVel * delta, yVel * delta);
    destroy= (xPos < 0 || yPos < 0 || xPos > Common::displayWidth || yPos > Common::displayHeight);
}

}
}
