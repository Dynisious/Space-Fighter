#include "CollidableObject.h"

using namespace Space_Fighter::ObjectTypes;

CollidableObject::CollidableObject(const unsigned __int32 mass, const vector & acc, const vector & vel) : KineticObject(acc, vel), mass(mass) {}

CollidableObject::~CollidableObject() {}

CollidableObject & CollidableObject::setMass(const unsigned __int32 m) {
	mass = m;
	return *this;
}

unsigned __int32 CollidableObject::getMass() {
	return mass;
}

void CollidableObject::collide(CollidableObject& obj) {
	vector objVelChg((getVelocity() - obj.getVelocity()) * mass / obj.mass), thisVelChg((obj.getVelocity() - getVelocity()) * obj.mass / mass);
	changeVelocity(thisVelChg);
	obj.changeVelocity(objVelChg);
}
