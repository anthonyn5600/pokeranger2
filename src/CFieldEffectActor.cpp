#include "field/CFieldEffectActor.hpp"

int CFieldEffectActor::ov0_02142264(int step)
{
    return CFieldEffect::ov0_02142264(step);
}

int CFieldEffectActor::IsReady()
{
    if (unk_18 == NULL) {
        return 0;
    }
    return unk_18->IsLoaded();
}
