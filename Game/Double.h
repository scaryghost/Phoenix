#ifndef ETSAI_PHOENIX_GAME_DOUBLE
#define ETSAI_PHOENIX_GAME_DOUBLE

#include "Phoenix/Game/Single.h"

namespace etsai {
namespace phoenix {

class Double : public Single {
public:
    Double(float xPos, float yPos, float xPos2, float yPos2, Pawn* owner);

protected:
    float xPos2, yPos2;
};

}
}

#endif