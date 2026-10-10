#include "field/CFieldActor.hpp"

#include <typeinfo>

// FieldActor.cpp is still asm, but CFieldActor's typeinfo has to come from C++: every derived class's TU emits a
// mergeable copy of it, which mwld won't merge with an asm global. This unreferenced function (stripped by mwld)
// makes this TU emit it at its place in main's .data.
const std::type_info &CFieldActor_typeinfo()
{
    return typeid(CFieldActor);
}
