#ifndef ETSAI_PHOENIX_CORE_CONTROLLER
#define ETSAI_PHOENIX_CORE_CONTROLLER

#include "Phoenix/Core/Object.h"
#include "Phoenix/Core/Pawn.h"

namespace etsai {
namespace phoenix {

class Controller : public Object {
public:
    Controller();
    virtual ~Controller();

    void attachToPawn(Pawn *pawn) { this->pawn= pawn; }
    void detachFromPawn() { this->pawn= NULL; }

private:
    Pawn *pawn;
};

}
}

#endif