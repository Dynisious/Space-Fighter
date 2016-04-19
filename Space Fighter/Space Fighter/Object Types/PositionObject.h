#pragma once

#include "Matrix_Arithmatic.h"

namespace Space_Fighter {

	namespace ObjectTypes {

		/*
		An Object which has a position and orientation inside 3D space.*/
		class PositionObject {
		public:
			/*
			A point in 3D space.*/
			typedef Dyn_API::Matrix_Arithmatic::matrix<__int32, 1, 3> position;
			/*
			The rotation of an Object inside 3D space.*/
			typedef Dyn_API::Matrix_Arithmatic::matrix<double, 1, 3> rotation;

			PositionObject();
			PositionObject(const position& loc, const rotation& ori);
			virtual ~PositionObject();
			/*
			Translates the PositionObject in 3D space by the value of trans.*/
			PositionObject& translate(const position& trans);
			/*
			Sets the position of the PositionObject in 3D space.*/
			PositionObject& setLocation(const position& loc);
			/*
			Returns the location of the PositionObject.*/
			position getLocation();
			/*
			Rotates the PositionObject in 3D space by the value of rot.*/
			PositionObject& rotate(const rotation& rot);
			/*
			Sets the orientation of the PositionObject in 3D space.*/
			PositionObject& setOrientation(const rotation& ori);
			/*
			Returns the orientation of the PositionObject.*/
			rotation getOrientation();

		private:
			position location;
			rotation orientation;

		};

	}

}
