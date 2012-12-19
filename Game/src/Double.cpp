#include "Phoenix/Game/Double.h"

namespace etsai {
namespace phoenix {

Double::Double(float xPos, float yPos, float xPos2, float yPos2, Pawn* owner) :
    Single(xPos, yPos, owner), xPos2(xPos2),yPos2(yPos2) {
}

}
}