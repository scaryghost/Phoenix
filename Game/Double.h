#ifndef ETSAI_PHOENIX_GAME_DOUBLE
#define ETSAI_PHOENIX_GAME_DOUBLE

#include "Phoenix/Game/Single.h"

namespace etsai {
namespace phoenix {

/**
 * Upgrade of the default Single weapon, providing twice the firepower
 * @author etsai
 */
class Double : public Single {
public:
    /**
     * Attach the weapon at two positions (xPos, yPos) and (xPos2, yPos2)
     * @param   xPos    X coordinate to attach the first part to
     * @param   yPos    Y coordinate to attach the first part to
     * @param   xPos2   X coordinate to attach the second part to
     * @param   yPos2   Y coordinate to attach the second part to
     * @param   owner   Owner of the weapon
     */
    Double(float xPos, float yPos, float xPos2, float yPos2, Pawn* owner);

protected:
    float xPos2;        ///< X position of the second part
    float yPos2;        ///< Y position of the second part
};

}
}

#endif
