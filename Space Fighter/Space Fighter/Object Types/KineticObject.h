#pragma once

#include "Matrix_Arithmatic.h"

namespace Space_Fighter {

	namespace ObjectTypes {

		/*
		A KineticObject has an acceleration value and a velocity value.*/
		class KineticObject {
		public:
			/*
			The type used for velocities and accelerations.*/
			typedef Dyn_API::Matrix_Arithmatic::matrix<__int32, 1, 3> vector;
			
			KineticObject();
			KineticObject(const vector& acc, const vector& vel);
			virtual ~KineticObject();
			/*
			Returns the acceleration value of the KineticObject.*/
			vector getAcceleration();
			/*
			Increments the acceleration of the KineticObject by acc.*/
			KineticObject& accelerate(const vector& acc);
			/*
			Sets the value of acceleration for the KineticObject.*/
			KineticObject& setAcceleration(const vector& acc);
			/*
			Increments the velocity of the KineticObject by it's acceleration.*/
			KineticObject& accelerate();
			/*
			Returns the velocity value of the KineticObject.*/
			vector getVelocity();
			/*
			Increments the velocity of the KineticObject by vel.*/
			KineticObject& changeVelocity(const vector& vel);
			/*
			Sets the velocity of the KineticObject to the value of vel.*/
			KineticObject& setVelocity(const vector& vel);

		private:
			vector /*
				   The acceleration of the KineticObject.*/acceleration, /*
				   The velocity of the KineticObject.*/velocity;

		};

	}

}
