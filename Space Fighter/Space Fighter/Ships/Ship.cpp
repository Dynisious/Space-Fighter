#include "Ship.h"

Space_Fighter::Ships::Ship::~Ship() {}

Space_Fighter::Ships::Ship & Space_Fighter::Ships::Ship::throttle(const SubSystems::Axies axis, const vector::value_t throt) {
	thrusters.throttle(axis, throt);
	setAcceleration(thrusters.getAdjustedAcceleration());
	return *this;
}

Space_Fighter::Ships::Ship & Space_Fighter::Ships::Ship::throttle(const SubSystems::Directions direction, const vector::value_t throt) {
	thrusters.throttle(direction, throt);
	setAcceleration(thrusters.getAdjustedAcceleration());
	return *this;
}

Space_Fighter::Ships::Ship & Space_Fighter::Ships::Ship::throttle(const vector throt) {
	thrusters.setThrottle(throt);
	setAcceleration(thrusters.getAdjustedAcceleration());
	return *this;
}

Space_Fighter::Ships::Ship & Space_Fighter::Ships::Ship::setThrottle(const SubSystems::Axies axis, const vector::value_t throt) {
	thrusters.setThrottle(axis, throt);
	setAcceleration(thrusters.getAdjustedAcceleration());
	return *this;
}

Space_Fighter::Ships::Ship & Space_Fighter::Ships::Ship::setThrottle(const SubSystems::Directions direction, const vector::value_t throt) {
	thrusters.setThrottle(direction, throt);
	setAcceleration(thrusters.getAdjustedAcceleration());
	return *this;
}

Space_Fighter::Ships::Ship & Space_Fighter::Ships::Ship::setThrottle(const vector throt) {
	thrusters.setThrottle(throt);
	setAcceleration(thrusters.getAdjustedAcceleration());
	return *this;
}

Space_Fighter::Ships::SubSystems::ThrustSubSystem::vector::value_t Space_Fighter::Ships::Ship::getThrottle(const SubSystems::Axies axis) {
	return thrusters.getThrottle(axis);
}

Space_Fighter::Ships::SubSystems::ThrustSubSystem::vector::value_t Space_Fighter::Ships::Ship::getThrottle(const SubSystems::Directions direction) {
	return 	thrusters.getThrottle(direction);
}

Space_Fighter::Ships::SubSystems::ThrustSubSystem::vector Space_Fighter::Ships::Ship::getThrottle() {
	return  thrusters.getThrottle();
}

std::make_unsigned<Space_Fighter::Ships::SubSystems::ThrustSubSystem::vector::value_t>::type Space_Fighter::Ships::Ship::getDirectionalThrottle(const SubSystems::Directions direction) {
	return thrusters.getDirectionalThrottle(direction);
}

std::make_unsigned<Space_Fighter::Ships::SubSystems::ThrustSubSystem::vector::value_t>::type Space_Fighter::Ships::Ship::getThrust(const SubSystems::Directions direction) {
	return thrusters.getThrust(direction);
}

std::make_unsigned<Space_Fighter::Ships::SubSystems::ThrustSubSystem::vector::value_t>::type Space_Fighter::Ships::Ship::getThrustMax(const SubSystems::Directions direction) {
	return thrusters.getThrustMax(direction);
}

std::make_unsigned<Space_Fighter::Ships::SubSystems::ThrustSubSystem::vector::value_t>::type Space_Fighter::Ships::Ship::getAcceleration(const SubSystems::Axies axis) {
	return getAcceleration()[axis];
}

std::make_unsigned<Space_Fighter::Ships::SubSystems::ThrustSubSystem::vector::value_t>::type Space_Fighter::Ships::Ship::getAcceleration(const SubSystems::Directions direction) {
	return getAcceleration(SubSystems::DirectionToAxies(direction));
}

std::make_unsigned<Space_Fighter::Ships::SubSystems::ThrustSubSystem::vector::value_t>::type Space_Fighter::Ships::Ship::getAccelerationMax(const SubSystems::Directions direction) {
	return thrusters.getAdjustedAccelerationMax(direction);
}

Space_Fighter::Ships::Ship::Ship(const MountObject & mountings, const Entity & entity, const SubSystems::ThrustSubSystem & thrusters)
	: MountObject(mountings), Entity(entity), thrusters(thrusters, getMass()) {}

Space_Fighter::Ships::Ship::Ship(const MountObject & mountings, const CollidableObject & collisions, const PositionObject & pos, const SubSystems::ThrustSubSystem & thrusters) : MountObject(mountings), Entity(collisions, pos), thrusters(thrusters, getMass()) {}

Space_Fighter::Ships::Ship::Ship(const Ship & orig) : MountObject(orig), Entity(orig), thrusters(orig.thrusters) {}

Space_Fighter::Ships::Ship & Space_Fighter::Ships::Ship::changeMass(const unsigned __int32 mass) {
	setMass(mass);
	thrusters.massChanged(mass);
	setAcceleration(thrusters.getAdjustedAcceleration());
	return *this;
}

Space_Fighter::Ships::Ship & Space_Fighter::Ships::Ship::setThrusters(const SubSystems::ThrustSubSystem & thrusters, SubSystems::ThrustSubSystem * const value) {
	if (value)
		*value = thrusters;
	this->thrusters = SubSystems::ThrustSubSystem(thrusters, getMass());
	return *this;
}
