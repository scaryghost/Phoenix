#ifndef ETSAI_PHOENIX_GAME_HUMANPAWN
#define ETSAI_PHOENIX_GAME_HUMANPAWN

#include "Phoenix/Game/Pawn.h"
#include "Phoenix/Game/Weapon.h"

#include <map>

namespace etsai {
namespace phoenix {
    
/**
 * Manages the player controlled pawn
 * @author etsai
 */
class HumanPawn : public Pawn {
public:
    /**
     * Directions the pawn can move in
     */
    enum Direction {
        UP_LEFT= 0,     ///< Move up and left (135 degrees)
        UP,             ///< Move up
        UP_RIGHT,       ///< Move up and right (45 degrees)
        LEFT,           ///< Move left
        NEUTRAL,        ///< No movement
        RIGHT,          ///< Move right
        DOWN_LEFT,      ///< Move down and left (225 degrees)
        DOWN,           ///< Move down
        DOWN_RIGHT      ///< Move down and right (315 degrees)
    };

    /**
     * Construct a player controller pawn at (xPos, yPos)
     * @param   xPos    X coordinate to spawn at
     * @param   yPos    Y coordinate to spawn at
     */
    HumanPawn(float xPos, float yPos);
    virtual ~HumanPawn();

    /**
     * Trigger the current weapon to fire
     */
    void startFiring();
    /**
     * Stop the current weapon from firing
     */
    void stopFiring();
    /**
     * Switch the ship's weapon to the one corresponding to the index
     * @param   weaponIndex     Index of the weapon to switch to
     */
    void switchToWeapon(int weaponIndex);
    /**
     * Switch to the next weapon in the inventory.  The index will loop back to the 
     * first weapon when exhausting the list.
     */
    void nextWeapon();
    /**
     * Switch to the previous weapon in the inventory.  The index will loop to the 
     * last weapon after reaching the first one
     */
    void prevWeapon();
    /**
     * Add amount to the meter
     * @param   amount  Amount to add to the meter
     */
    void gainMeter(float amount);
    /**
     * Give cash to the player
     * @param   amount  Amount of cash to give
     */
    void addCash(unsigned int amount);
    /**
     * Activate the ship's special ability
     */
    void activateAbility();
    /**
     * Set the ships direction of movement
     * @param   dir     Direction to move the ship
     */
    void setDirection(Direction dir);
    /**
     * Move the object, hitbox, and weapons with the specified horizontal and vertical offsets
     * @param   xOffset     Horizontal offset to move the hitbox and object
     * @param   yOffset     Vertical offset to move the hitbox and object
     */
    virtual void translate(float xOffset, float yOffset);
    virtual void tick(double delta);
    virtual void draw();

protected:
    float meter;                                ///< Current meter of the ship
    float maxMeter;                             ///< Maximum amount of meter
    float meterGainScale;                       ///< How much a meter gain should scale by
    float meterUsageRate;                       ///< How fast to consume the meter when the special ability is active
    unsigned int cash;                          ///< Amount of cash the ship has
    bool abilityActive;                         ///< True if the ship's special ability is active
    Direction dir;                              ///< Current movement direction of the ship
    std::map<int, Weapon*> weapons;             ///< Weapons belonging to the ship
    std::map<int, Weapon*>::iterator currentWeapon;     ///< Index of the current weapon the ship is using
    bool isFiring;

    ALLEGRO_BITMAP *image;
    int imageHalfW, imageHalfH;
};

}   //namespace phoenix
}   //namespace etsai

#endif
