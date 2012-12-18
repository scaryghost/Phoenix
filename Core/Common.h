#ifndef ETSAI_PHOENIX_CORE_COMMON
#define ETSAI_PHOENIX_CORE_COMMON

#include "Phoenix/Game/SingleProj.h"
#include "Phoenix/Game/HumanPawn.h"

#include <Windows.h>

namespace etsai {
namespace phoenix {

/** Value of pi out to 33 digits */
const double PI= 3.141592653589793238462643383279502;

/**
 * Common variables and values shared across all modules
 * @author etsai
 */
class Common {
public:
    typedef SingleProj* (__cdecl *CreateSingleProjType)(float xPos, float yPos, float rotation);
    typedef HumanPawn* (__cdecl *CreateHumanPawnType)(float xPos, float yPos);
    /**
     * Initialize the module
     * @param   argc    Number of arguments passed into main
     * @param   argv    List of arguments passed into main
     */
    static void init(int argc, char **argv);

    /** Height of the display, in pixels */
    static int displayHeight;
    /** Width of the display, in pixels */
    static int displayWidth;

    static CreateSingleProjType createSingleProj;
    static CreateHumanPawnType createHumanPawn;
    static CreateHumanPawnType createHitBox;
private:
    static HINSTANCE dllHandle;
};

}   //namespace phoenix
}   //namespace etsai

#endif