#include "field/CFieldEffectActor.hpp"

int CFieldEffectActor::Update(int step)
{
    return CFieldEffect::Update(step);
}

int CFieldEffectActor::IsReady()
{
    if (unk_18 == NULL) {
        return 0;
    }
    return unk_18->IsLoaded();
}
