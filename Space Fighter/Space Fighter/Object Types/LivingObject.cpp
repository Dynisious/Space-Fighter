#include "LivingObject.h"

bool Space_Fighter::ObjectTypes::LivingObject::isAlive() {
	throw 1;
}

Space_Fighter::ObjectTypes::LO_Type Space_Fighter::ObjectTypes::LivingObject::LO_TypeCode() {
	return LO_Type::Bad_Type;
}

Space_Fighter::ObjectTypes::LivingObject::LivingObject() {}
