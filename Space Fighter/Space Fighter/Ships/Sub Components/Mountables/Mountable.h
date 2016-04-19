#pragma once

#include "..\..\..\Object Types\PositionObject.h"

namespace Space_Fighter {

	namespace Ships {

		namespace SubComponents {

			/*
			A base class for Objects which can be mounted on a MountObject.*/
			class Mountable {
			public:
				Mountable();
				Mountable(const ObjectTypes::PositionObject::rotation orientation);
				virtual ~Mountable();
				/*
				Rotates the Mountable by the value of rot.*/
				Mountable& rotate(const ObjectTypes::PositionObject::rotation& rot);
				/*
				Sets the orientation of the PositionObject in 3D space.*/
				Mountable& setOrientation(const ObjectTypes::PositionObject::rotation& ori);
				/*
				Returns the orientation of the PositionObject.*/
				ObjectTypes::PositionObject::rotation getOrientation();
				bool operator==(Mountable & obj);
				bool operator!=(Mountable & obj);

			private:
				ObjectTypes::PositionObject::rotation orientation;

			};

		}

	}

}
