#ifndef ETSAI_PHOENIX_CORE_COMMON
#define ETSAI_PHOENIX_CORE_COMMON

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
    static int displayHeight;
    /** Width of the display, in pixels */
    static int displayWidth;
};

}   //namespace phoenix
}   //namespace etsai

#endif