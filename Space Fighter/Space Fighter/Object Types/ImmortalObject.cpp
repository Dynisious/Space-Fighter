#include "ImmortalObject.h"

bool Space_Fighter::ObjectTypes::ImmortalObject::isAlive() {
	return true;
}

Space_Fighter::ObjectTypes::LO_Type Space_Fighter::ObjectTypes::ImmortalObject::LO_TypeCode() {
	return LO_Type::ImmortalObject_Type;
}
