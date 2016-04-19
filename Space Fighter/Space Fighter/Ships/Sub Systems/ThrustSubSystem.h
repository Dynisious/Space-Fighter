#pragma once

#include "SubSystem.h"
#include "..\..\Object Types\KineticObject.h"

namespace Space_Fighter {

	namespace Ships {

		namespace SubSystems {

			/*
			The six directions of 3D space.*/
			enum Directions {
				North,
				South,
				East,
				West,
				Up,
				Down,
				Directions_Max
			};
			/*
			The 3 axis of 3D space.*/
			enum Axies {
				NorthSouth,
				EastWest,
				UpDown,
				Axies_Max
			};

			/*
			Converts an axis value into a direction based on the sign of value.*/
			Directions AxiesToDirection(const Axies axis, const int value);
			/*
			Converts a Direction value to an Axis value.*/
			Axies DirectionToAxies(const Directions direction);

			/*
			A SubSystem which is a potential thrust force in each direction
			combined with a throttle percentage along each axis which can be
			combined to get the acceleration along each axis or in each
			direction relative to the mass of an object.*/
			class ThrustSubSystem : SubSystem {
			public:
				typedef ObjectTypes::KineticObject::vector vector;

				/*
				The maximum throttle percentage "100"*/
				static vector::value_t FullThrottle;

				ThrustSubSystem(const vector::value_t * const thrust_max, const vector & throttleValue, const unsigned __int32 mass);
				ThrustSubSystem(const ThrustSubSystem & orig, const unsigned __int32 mass);
				ThrustSubSystem(const ThrustSubSystem & orig);
				/*
				Increments the throttle in a particular axis.*/
				ThrustSubSystem & throttle(const Axies axis, const vector::value_t throt);
				/*
				Increments the throttle in a particular direction.*/
				ThrustSubSystem & throttle(const Directions direction, const vector::value_t throt);
				/*
				Increments the throttle in all axies.*/
				ThrustSubSystem & throttle(const vector throt);
				/*
				Sets the throttle in a particular axis.*/
				ThrustSubSystem & setThrottle(const Axies axis, const vector::value_t throt);
				/*
				Sets the throttle in a particular direction.*/
				ThrustSubSystem & setThrottle(const Directions direction, const vector::value_t throt);
				/*
				Sets the throttle in all axies.*/
				ThrustSubSystem & setThrottle(const vector throt);
				/*
				Gets the throttle in a particular axis*/
				vector::value_t getThrottle(const Axies axis);
				/*
				Gets the throttle in a particular axis*/
				vector::value_t getThrottle(const Directions axis);
				/*
				Gets the throttle in all axies*/
				vector getThrottle();
				/*
				Gets the throttle in a particular direction.*/
				std::make_unsigned<vector::value_t>::type getDirectionalThrottle(const Directions direction);
				/*
				Gets the thrust in a particular direction.*/
				std::make_unsigned<vector::value_t>::type getThrust(const Directions direction);
				/*
				Gets the maximum possible thrust in a particular direction.*/
				std::make_unsigned<vector::value_t>::type getThrustMax(const Directions direction);
				/*
				Gets the acceleration in all axies*/
				vector getAdjustedAcceleration();
				/*
				Gets the acceleration in a particular axis.*/
				std::make_unsigned<vector::value_t>::type getAdjustedAcceleration(const Axies axis);
				/*
				Gets the acceleration in a particular axis.*/
				std::make_unsigned<vector::value_t>::type getAdjustedAcceleration(const Directions direction);
				/*
				Gets the maximum acceleration in a particular direction.*/
				std::make_unsigned<vector::value_t>::type getAdjustedAccelerationMax(const Directions direction);
				/*
				Readjusts the returned values for acceleration values to be relative to this mass.*/
				ThrustSubSystem & massChanged(const unsigned __int32 mass);

			private:
				vector::value_t /*
								The maximum thrust that can be produced.
								*/thrust_max[Directions::Directions_Max],
								/*
								The maximum acceleration that can be produced based on the last know mass.
								*/adjustedAcceleration_max[Directions::Directions_Max];
								/*
								The throttle values along each axis.*/
				vector throttleValue;

			};

		}

	}

}
