#ifndef ETSAI_PHOENIX_CORE_OBJECT
#define ETSAI_PHOENIX_CORE_OBJECT

#include <functional>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

namespace etsai {
namespace phoenix {

/**
 * Base class that all Phoenix related classes derive from
 * @author etsai
 */
class Object {
public:
    /**
     * Call the tick function for all tickable Objects
     * @param   delta   Elapsed time since last tick
     */
    static void tickObjects(double delta);
    /** Draws all spawned objects */
    static void drawObjects();

    /** Lambda type for timer function callbacks */
    typedef std::function<void ()> TimerFunc;

    Object(float xPos, float yPos);
    virtual ~Object();

    
    void translate(float xOffset, float yOffset) {
        xPos+= xOffset;
        yPos+= yOffset;
    }

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
     * Disable the tick function.  This will also disable calling the timer functions.
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
    virtual void tick(double delta);

    /**
     * Draw this object on screen
     */
    virtual void draw()= 0;
protected:
    bool destroy;
    float xPos;
    float yPos;

private:
    typedef std::tuple<double, double, TimerFunc> TimerInfo;
    std::unordered_map<std::string, TimerInfo> timers;

    static std::unordered_set<Object*> tickableObjects;
    static std::unordered_set<Object*> objects;
};

}
}

#endif
