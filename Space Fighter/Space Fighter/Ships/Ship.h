#pragma once

#include "..\Entity Types\Entity.h"
#include "Sub Components\Mountables\MountObject.h"
#include "Sub Systems\ThrustSubSystem.h"

namespace Space_Fighter {

	namespace Ships {

		/*
		The base class of all Ship Objects tying together multiple classes.*/
		class Ship : public SubComponents::MountObject, public EntityTypes::Entity {
		public:
			virtual ~Ship();
			/*
			Increments the throttle and acceleration in a particular axis*/
			Ship & throttle(const SubSystems::Axies axis, const vector::value_t throt);
			/*
			Increments the throttle and acceleration in a particular direction.*/
			Ship & throttle(const SubSystems::Directions direction, const vector::value_t throt);
			/*
			Increments the throttle and acceleration in all axies.*/
			Ship & throttle(const vector throt);
			/*
			Sets the throttle and acceleration in a particular axis.*/
			Ship & setThrottle(const SubSystems::Axies axis, const vector::value_t throt);
			/*
			Sets the throttle and acceleration in a particular direction.*/
			Ship & setThrottle(const SubSystems::Directions direction, const vector::value_t throt);
			/*
			Sets the throttle and acceleration in all axies.*/
			Ship & setThrottle(const vector throt);
			/*
			Gets the throttle in a particular axis*/
			vector::value_t getThrottle(const SubSystems::Axies axis);
			/*
			Gets the throttle in a particular axis*/
			vector::value_t getThrottle(const SubSystems::Directions axis);
			/*
			Gets the throttle in all axies*/
			vector getThrottle();
			/*
			Gets the throttle in a particular direction.*/
			std::make_unsigned<vector::value_t>::type getDirectionalThrottle(const SubSystems::Directions direction);
			/*
			Gets the thrust in a particular direction.*/
			std::make_unsigned<vector::value_t>::type getThrust(const SubSystems::Directions direction);
			/*
			Gets the maximum possible thrust in a particular direction.*/
			std::make_unsigned<vector::value_t>::type getThrustMax(const SubSystems::Directions direction);
			KineticObject::getAcceleration;
			/*
			Gets the acceleration in a particular axis.*/
			std::make_unsigned<vector::value_t>::type getAcceleration(const SubSystems::Axies axis);
			/*
			Gets the acceleration in a particular axis.*/
			std::make_unsigned<vector::value_t>::type getAcceleration(const SubSystems::Directions direction);
			/*
			Gets the maximum acceleration in a particular direction.*/
			std::make_unsigned<vector::value_t>::type getAccelerationMax(const SubSystems::Directions direction);
			/*
			Adjusts the mass of the Ship and the accelerations produced by it's thrusters.*/
			Ship & changeMass(const unsigned __int32 mass);
			/*
			Sets the Thrust sub system of this Ship. the value of "value" is
			set to the current Thrust sub system or it is left untouched if it
			is null.*/
			Ship & setThrusters(const SubSystems::ThrustSubSystem & thrusters, SubSystems::ThrustSubSystem * const value = nullptr);

		private:
			/*
			The Thrust sub system for this Ship responsible for providing an
			adjustable thrust force in the Ship.*/
			SubSystems::ThrustSubSystem thrusters;

		protected:
			Ship(const MountObject & mountings, const Entity & entity, const SubSystems::ThrustSubSystem & thrusters);
			Ship(const MountObject & mountings, const CollidableObject & collide, const PositionObject & pos, const SubSystems::ThrustSubSystem & thrusters);
			Ship(const Ship & orig);

		};

	}

}
