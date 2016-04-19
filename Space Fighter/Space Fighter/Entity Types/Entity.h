#pragma once

#include "..\Object Types\CollidableObject.h"
#include "..\Object Types\PositionObject.h"
#include "..\Object Types\LivingObject.h"

namespace Space_Fighter {

	namespace EntityTypes {

		/*
		The base class for all Entity Objects, tying together several key
		Object types into a single class.*/
		class Entity : public ObjectTypes::CollidableObject, public ObjectTypes::PositionObject, public ObjectTypes::LivingObject {
		public:
			virtual ~Entity();

		protected:
			Entity(const CollidableObject & collide, const PositionObject & pos);
			Entity(const Entity & orig);

		};

	}

}
