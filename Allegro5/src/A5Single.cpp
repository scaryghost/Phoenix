#include "Phoenix/Allegro5/A5Single.h"
#include "Phoenix/Allegro5/A5SingleProj.h"

#include "Phoenix/Core/Common.h"

namespace etsai {
namespace phoenix {

A5Single::A5Single() : Single() {
}

void A5Single::doFireEffect() {
    new A5SingleProj(640, 360, PI/6);
}

}
}