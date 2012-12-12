#include "Phoenix/Game/Single.h"
#include "Phoenix/Game/Pawn.h"

namespace etsai {
namespace phoenix {

class A5Single : public Single {
public:
    A5Single(Pawn *owner);

    virtual void doFireEffect();
};

}   //namespace phoenix
}   //namespace etsai