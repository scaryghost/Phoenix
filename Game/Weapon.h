#ifndef ETSAI_PHOENIX_GAME_WEAPON
#define ETSAI_PHOENIX_GAME_WEAPON

#include "Phoenix/Core/Object.h"

namespace etsai {
namespace phoenix {

/**
 * Base class for the weapons in the game
 * @author etsai
 */
class Weapon : public Object {
public:
    /**
     * Constructs a weapon.
     */
    Weapon();

    /**
     * Fire the weapon.  If the weapon cannot fire, the function will immediately return
     */
    void fire();
    /**
     * Refill ammo on the weapon
     * @param   amount  Amount of ammo to restore
     */
    void refillAmmo(int amount);
    /**
     * Set the weapon index
     * @param   index   Index of the weapon
     */
    void setWeaponIndex(int index);

    /**
     * Checks if the weapon is able to fire at the given moment.  The check is based on the ammo 
     * count and the fire rate cooldown timer
     * @return True if the weapon can fire
     */
    bool canFire() const;
    /**
     * Retrieve the ammo status of the weapon
     * @return True if the weapon has ammo
     */
    bool hasAmmo() const;
    /**
     * Get the current ammo count
     * @return Amount of ammo in the weapon
     */
    int getAmmoCount() const;
    /**
     * Get the maximum amount of ammo the weapon can hold
     * @return Maximum amount of ammo
     */
    int getMaxAmmo() const;
    /**
     * Get the index of the weapon
     * @return weapon index
     */
    int getWeaponIndex() const;

    virtual void tick(double delta);
    /**
     * Perform the effects of firing the weapon
     */
    virtual void doFireEffect()= 0;
    /**
     * Reduce ammo count of the current weapon.  This function is only called after a successful weapon fire
     */
    virtual void consumeAmmo()= 0;

protected:
    int index;          ///< Index the weapon belongs to
    int ammo;           ///< Current ammo count of the weapon
    int maxAmmo;        ///< Maximum ammo the weapon can store
    float fireRate;     ///< How often the weapon can fire (sec per shot)
    float cooldown;     ///< Cooldown timer to enforce the fire rate
};

}   //namespace phoenix
}   //namespace etsai

#endif