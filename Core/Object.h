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
 * Base class that all game objects derive from
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

    /**
     * Creates a blank object
     */
    Object();
    /**
     * Create an object at the given point (xPos, yPos).  Objects by default will have 
     * their tick function will be called
     * @param   xPos    X coordinate of the object
     * @param   yPos    Y coordinate of the object
     */
    Object(float xPos, float yPos);
    /**
     * Class destructor
     */
    virtual ~Object();
    
    /**
     * Get the X coordinate of the object position
     * @return X coordinate
     */
    float getXPos() const;
    /**
     * Get the Y coordinate of the object position
     * @return Y coordinate
     */
    float getYPos() const;
    /**
     * Get the rotation angle of the object
     * @return Rotation angle
     */
    float getRotation() const;
    /**
     * Move the object with the specified horizontal and vertical offsets
     * @param   xOffset     Horizontal offset to move the object
     * @param   yOffset     Vertical offset to move the object
     */
    virtual void translate(float xOffset, float yOffset);
    /**
     * Rotate the object by a fixed amount
     * @note Input is in radians
     * @param   radians     The amount, in radians, to rotate the hit box by
     */
    virtual void rotate(float radians);

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
     * @note The tick function's parameter is in seconds
     * @param   delta   How much time, in seconds, has elapsed since the previous call
     */
    virtual void tick(double delta);

    /**
     * Draw this object on screen
     */
    virtual void draw()= 0;
protected:
    bool destroy;       ///< True if the object should be destroyed
    float xPos;         ///< X coordinate of the object
    float yPos;         ///< Y coordinate of the object
    float rotation;     ///< Rotation angle of the object

private:
    typedef std::tuple<double, double, TimerFunc> TimerInfo;    ///< Timer function information, storing period, accumulated timer, and lambda callback
    std::unordered_map<std::string, TimerInfo> timers;          ///< Maps timer names to their info tuple

    static std::unordered_set<Object*> tickableObjects;         ///< Objects that will have their tick function called before the next frame
    static std::unordered_set<Object*> objects;                 ///< All spawned objects
};

}
}

#endif
