#ifndef POKERANGER2_PCH_DATA_HPP
#define POKERANGER2_PCH_DATA_HPP

// Constants the original defined in its precompiled header. mwcc keeps such initialized objects as pending data in
// the .mch and emits them at the very end of each TU that uses them (after the TU-end vtable/typeinfo passes), so
// they are the last-created objects in the TU's data size sort: defining them in a .cpp gives a different layout.

// CAC kinds of the water gun's nozzle and head sprites (CFieldEffectWaterGun).
static const int sWaterGunCacKinds[2] = { 0, 2 };

#endif // POKERANGER2_PCH_DATA_HPP
