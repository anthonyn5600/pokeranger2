#include "CEffectActorData.hpp"

#include <typeinfo>

// CEffectActorData's code is still asm, but its typeinfo has to come from C++ (derived TUs emit mergeable copies,
// which mwld won't merge with an asm global). This unreferenced function (stripped by mwld) makes this
// TU emit it at its place in the data.
const std::type_info &CEffectActorData_typeinfo()
{
    return typeid(CEffectActorData);
}
