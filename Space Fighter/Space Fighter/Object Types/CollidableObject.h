#pragma once

#include "KineticObject.h"

namespace Space_Fighter {

	namespace ObjectTypes {

		/*
		Extends the functionality of KineticObjects to give them a mass and
		therefore a momentum to collide with other CollidableObjects.*/
		class CollidableObject : public KineticObject {
		public:
			CollidableObject(const unsigned __int32 mass, const vector& acc, const vector& vel);
			virtual ~CollidableObject();
			/*
			Sets the mass of the CollidableObject.*/
			CollidableObject& setMass(const unsigned __int32 m);
			/*
			Returns the value of the mass of the CollidableObject.*/
			unsigned __int32 getMass();
			/*
			Changes the velocity of these two CollidableObjects depending on how they collide.*/
			void collide(CollidableObject& obj);

		private:
			/*
			The mass of this CollidableObject.*/
			unsigned __int32 mass;

		};

	}

}
