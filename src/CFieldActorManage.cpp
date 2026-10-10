#include "field/CFieldActorManage.hpp"

#include <typeinfo>

// FieldActorManage.cpp is still asm, but CFieldActorManage's typeinfo has to come from C++ (see CFieldActor.cpp):
// this unreferenced function (stripped by mwld) makes this TU emit it at its place in main's .data.
const std::type_info &CFieldActorManage_typeinfo()
{
    return typeid(CFieldActorManage);
}
