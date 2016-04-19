#include "KineticObject.h"

Space_Fighter::ObjectTypes::KineticObject::KineticObject() : acceleration(0), velocity(0) {}

Space_Fighter::ObjectTypes::KineticObject::KineticObject(const vector & acc, const vector & vel) : acceleration(acc), velocity(vel) {}

Space_Fighter::ObjectTypes::KineticObject::~KineticObject() {}

Space_Fighter::ObjectTypes::KineticObject::vector Space_Fighter::ObjectTypes::KineticObject::getAcceleration() {
	return acceleration;
}

Space_Fighter::ObjectTypes::KineticObject & Space_Fighter::ObjectTypes::KineticObject::accelerate(const vector & acc) {
	acceleration += acc;
	return *this;
}

Space_Fighter::ObjectTypes::KineticObject & Space_Fighter::ObjectTypes::KineticObject::setAcceleration(const vector & acc) {
	acceleration = acc;
	return *this;
}

Space_Fighter::ObjectTypes::KineticObject & Space_Fighter::ObjectTypes::KineticObject::accelerate() {
	velocity += acceleration;
	return *this;
}

Space_Fighter::ObjectTypes::KineticObject::vector Space_Fighter::ObjectTypes::KineticObject::getVelocity() {
	return velocity;
}

Space_Fighter::ObjectTypes::KineticObject & Space_Fighter::ObjectTypes::KineticObject::changeVelocity(const vector & vel) {
	velocity += vel;
	return *this;
}

Space_Fighter::ObjectTypes::KineticObject & Space_Fighter::ObjectTypes::KineticObject::setVelocity(const vector & vel) {
	velocity = vel;
	return *this;
}
