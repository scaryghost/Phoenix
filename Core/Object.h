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

    /**
     * Add custom timer callback
     * @param   period      How often, in seconds, the timer callback should be run
     * @param   key         Unique key name to associate with the timer
     * @param   callback    Lambda to be executed
     */
    void addTimer(double period, std::string key, TimerFunc callback);
    /**
     * Remove the custom timer associated with the key name
     * @param   key     Unique key name of the timer callback to remove
     */
    void removeTimer(std::string key);

    /**
     * Disable the tick function
     */
    void disableTick();
    /**
     * Enable tick function
     */
    void enableTick();
    /**
     * Function that is called before every frame.
     */
    virtual void tick(double delta)= 0;

private:
    typedef std::tuple<double, TimerFunc> TimerInfo;
    std::unordered_map<std::string, TimerInfo> timers;
    double timerPeriod;
    bool enableTick;
};

}
}

#endif
