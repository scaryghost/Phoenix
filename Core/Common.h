#ifndef ETSAI_PHOENIX_CORE_COMMON
#define ETSAI_PHOENIX_CORE_COMMON

#include "Phoenix/Game/SingleProj.h"
#include "Phoenix/Game/HumanPawn.h"

#include <string>
#include <unordered_set>
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
    /**
     * Initialize the module
     * @param   argc    Number of arguments passed into main
     * @param   argv    List of arguments passed into main
     */
    static void init(int argc, char **argv);

    /** Height of the display, in pixels */
    static float displayHeight;
    /** Width of the display, in pixels */
    static float displayWidth;

    static Object* spawn(std::string className, ...);
    static void drawObjects();
private:
    static HINSTANCE dllHandle;
    static std::unordered_set<Object*> objects;

    typedef SingleProj* (__cdecl *CreateSingleProjType)(float xPos, float yPos, float rotation);
    typedef HumanPawn* (__cdecl *CreateHumanPawnType)(float xPos, float yPos);

    static CreateSingleProjType createSingleProj;
    static CreateHumanPawnType createHumanPawn;
    static CreateHumanPawnType createHitBox;

};

}   //namespace phoenix
}   //namespace etsai

#endif