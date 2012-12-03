#ifndef ETSAI_PHOENIX_CORE_OBJECT
#define ETSAI_PHOENIX_CORE_OBJECT

#include <functional>
#include <string>
#include <tuple>
#include <unordered_map>

namespace etsai {
namespace phoenix {

/**
 * Base class that all PHoenix related classes derive from
 * @author etsai
 */
class Object {
public:
    /** Lambda type for timer function callbacks */
    typedef std::function<void ()> TimerFunc;

    Object();
    ~Object();

    /**
     * Add custom timer callback
     * @param   period      How often, in seconds, the timer callback should be run
     * @param   name        Unique name name to associate with the timer
     * @param   callback    Lambda to be executed
     */
    void addTimer(double period, std::string name, TimerFunc callback);
    /**
     * Remove the custom timer associated with the name name
     * @param   name        Unique name name of the timer callback to remove
     */
    void removeTimer(std::string name);

    /**
     * Disable the tick function
     */
    void disableTick();
    /**
     * Enable tick function
     */
    void enableTick();
    /**
     * Function that is called before every frame.  Accumulated time for timers 
     * are also updated here
     * @param   delta   How much time has elapsed since the previous call
     */
    void tick(double delta);

private:
    typedef std::tuple<double, double, TimerFunc> TimerInfo;
    std::unordered_map<std::string, TimerInfo> timers;
    double timerPeriod;
    bool enableTick;
};

}
}

#endif
