#include "field/CFieldActor.hpp"

#include <typeinfo>

// FieldActor.cpp is still asm, but the typeinfo of CFieldActor and CFieldActorScript has to come from C++: every
// derived class's TU emits a mergeable copy of it, which mwld won't merge with an asm global. These unreferenced
// functions (stripped by mwld) make this TU emit both at their place in main's .data (in the original order:
// _ZTI17CFieldActorScript, _ZTI11CFieldActor, _ZTS11CFieldActor, _ZTS17CFieldActorScript).
const std::type_info &CFieldActor_typeinfo()
{
    return typeid(CFieldActor);
}

const std::type_info &CFieldActorScript_typeinfo()
{
    return typeid(CFieldActorScript);
}
