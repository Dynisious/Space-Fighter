#include "ThrustSubSystem.h"

Space_Fighter::Ships::SubSystems::Directions Space_Fighter::Ships::SubSystems::AxiesToDirection(const Axies axis, const int value) {
	switch (axis) {
	case Axies::NorthSouth:
		return value > 0 ? Directions::North : Directions::South;
	case Axies::EastWest:
		return value > 0 ? Directions::East : Directions::West;
	case Axies::UpDown:
		return value > 0 ? Directions::Up : Directions::Down;
	default:
		throw 1;
	}
}

Space_Fighter::Ships::SubSystems::Axies Space_Fighter::Ships::SubSystems::DirectionToAxies(const Directions direction) {
	switch (direction) {
	case Directions::North: case Directions::South:
		return Axies::NorthSouth;
	case Directions::East: case Directions::West:
		return Axies::EastWest;
	case Directions::Up: case Directions::Down:
		return Axies::UpDown;
	default:
		throw 1;
	}
}

Space_Fighter::Ships::SubSystems::ThrustSubSystem::vector::value_t Space_Fighter::Ships::SubSystems::ThrustSubSystem::FullThrottle = 100;

Space_Fighter::Ships::SubSystems::ThrustSubSystem::ThrustSubSystem(const vector::value_t * const thrust_max, const vector & throttleValue, const unsigned __int32 mass) {
	unsigned __int32 i;
	for (i = 0; i < Axies::Axies_Max; i++) {
		this->throttleValue[i] = throttleValue[i];
		this->thrust_max[i] = thrust_max[i];
		adjustedAcceleration_max[i] = thrust_max[i] / mass;
	}

	for (; i < Directions::Directions_Max; i++) {
		this->thrust_max[i] = thrust_max[i];
		adjustedAcceleration_max[i] = thrust_max[i] / mass;
	}
}

Space_Fighter::Ships::SubSystems::ThrustSubSystem::ThrustSubSystem(const ThrustSubSystem & orig, const unsigned __int32 mass) {
	unsigned __int32 i;
	for (i = 0; i < Axies::Axies_Max; i++) {
		throttleValue[i] = orig.throttleValue[i];
	}

	for (; i < Directions::Directions_Max; i++) {
		thrust_max[i] = orig.thrust_max[i];
		adjustedAcceleration_max[i] = orig.thrust_max[i] / mass;
	}
}

Space_Fighter::Ships::SubSystems::ThrustSubSystem::ThrustSubSystem(const ThrustSubSystem & orig) {
	unsigned __int32 i;
	for (i = 0; i < Axies::Axies_Max; i++) {
		throttleValue[i] = orig.throttleValue[i];
	}

	for (; i < Directions::Directions_Max; i++) {
		thrust_max[i] = orig.thrust_max[i];
		adjustedAcceleration_max[i] = orig.adjustedAcceleration_max[i];
	}
}

Space_Fighter::Ships::SubSystems::ThrustSubSystem & Space_Fighter::Ships::SubSystems::ThrustSubSystem::throttle(const Axies axis, const vector::value_t throt) {
	return setThrottle(axis, throttleValue[axis] + throt);
}

Space_Fighter::Ships::SubSystems::ThrustSubSystem & Space_Fighter::Ships::SubSystems::ThrustSubSystem::throttle(const Directions direction, const vector::value_t throt) {
	return throttle(DirectionToAxies(direction), throt);
}

Space_Fighter::Ships::SubSystems::ThrustSubSystem & Space_Fighter::Ships::SubSystems::ThrustSubSystem::throttle(const vector throt) {
	for (unsigned __int32 i = 0; i < Axies::Axies_Max; i++)
		throttle(( Axies ) i, throt[i]);
	return *this;
}

Space_Fighter::Ships::SubSystems::ThrustSubSystem & Space_Fighter::Ships::SubSystems::ThrustSubSystem::setThrottle(const Axies axis, const vector::value_t throt) {
	throttleValue[axis] = (throt < 0) ? ((throt < -FullThrottle) ? -FullThrottle : throt) : ((throt > FullThrottle) ? FullThrottle : throt);
	return *this;
}

bool positiveDirection(const Space_Fighter::Ships::SubSystems::Directions direction) {
	return direction == Space_Fighter::Ships::SubSystems::Directions::North
		|| direction == Space_Fighter::Ships::SubSystems::Directions::East
		|| direction == Space_Fighter::Ships::SubSystems::Directions::Up;
}

Space_Fighter::Ships::SubSystems::ThrustSubSystem & Space_Fighter::Ships::SubSystems::ThrustSubSystem::setThrottle(const Directions direction, const vector::value_t throt) {
	return setThrottle(DirectionToAxies(direction), positiveDirection(direction) ? throt : -throt);
}

Space_Fighter::Ships::SubSystems::ThrustSubSystem & Space_Fighter::Ships::SubSystems::ThrustSubSystem::setThrottle(const vector throt) {
	for (unsigned __int32 i = 0; i < Axies::Axies_Max; i++)
		setThrottle(( Axies ) i, throt[i]);
	return *this;
}

Space_Fighter::Ships::SubSystems::ThrustSubSystem::vector::value_t Space_Fighter::Ships::SubSystems::ThrustSubSystem::getThrottle(const Axies axis) {
	return throttleValue[axis];
}

Space_Fighter::Ships::SubSystems::ThrustSubSystem::vector::value_t Space_Fighter::Ships::SubSystems::ThrustSubSystem::getThrottle(const Directions direction) {
	return getThrottle(DirectionToAxies(direction));
}

Space_Fighter::Ships::SubSystems::ThrustSubSystem::vector Space_Fighter::Ships::SubSystems::ThrustSubSystem::getThrottle() {
	return throttleValue;
}

std::make_unsigned<Space_Fighter::Ships::SubSystems::ThrustSubSystem::vector::value_t>::type Space_Fighter::Ships::SubSystems::ThrustSubSystem::getDirectionalThrottle(const Directions direction) {
	return positiveDirection(direction) ? getThrottle(direction) : -getThrottle(direction);
}

std::make_unsigned<Space_Fighter::Ships::SubSystems::ThrustSubSystem::vector::value_t>::type Space_Fighter::Ships::SubSystems::ThrustSubSystem::getThrust(const Directions direction) {
	return thrust_max[direction] * (positiveDirection(direction) ? throttleValue[DirectionToAxies(direction)] : -throttleValue[DirectionToAxies(direction)]) / FullThrottle;
}

std::make_unsigned<Space_Fighter::Ships::SubSystems::ThrustSubSystem::vector::value_t>::type Space_Fighter::Ships::SubSystems::ThrustSubSystem::getThrustMax(const Directions direction) {
	return thrust_max[direction];
}

Space_Fighter::Ships::SubSystems::ThrustSubSystem::vector Space_Fighter::Ships::SubSystems::ThrustSubSystem::getAdjustedAcceleration() {
	vector::value_t acceleration[vector::Length];
	for (unsigned __int32 i = 0; i < Axies::Axies_Max; i++)
		acceleration[i] = getAdjustedAcceleration(AxiesToDirection(( Axies ) i, throttleValue[i]));
	return vector(acceleration);
}

std::make_unsigned<Space_Fighter::Ships::SubSystems::ThrustSubSystem::vector::value_t>::type Space_Fighter::Ships::SubSystems::ThrustSubSystem::getAdjustedAcceleration(const Axies axis) {
	return getAdjustedAcceleration(AxiesToDirection(axis, throttleValue[axis]));
}

std::make_unsigned<Space_Fighter::Ships::SubSystems::ThrustSubSystem::vector::value_t>::type Space_Fighter::Ships::SubSystems::ThrustSubSystem::getAdjustedAcceleration(const Directions direction) {
	return adjustedAcceleration_max[direction] * getDirectionalThrottle(direction) / FullThrottle;
}

std::make_unsigned<Space_Fighter::Ships::SubSystems::ThrustSubSystem::vector::value_t>::type Space_Fighter::Ships::SubSystems::ThrustSubSystem::getAdjustedAccelerationMax(const Directions direction) {
	return adjustedAcceleration_max[direction];
}

Space_Fighter::Ships::SubSystems::ThrustSubSystem & Space_Fighter::Ships::SubSystems::ThrustSubSystem::massChanged(const unsigned __int32 mass) {
	for (unsigned __int32 i = 0; i < Directions::Directions_Max; i++)
		adjustedAcceleration_max[i] = thrust_max[i] / mass;
	return *this;
}
