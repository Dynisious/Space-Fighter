#pragma once

#include "LivingObject.h"

namespace Space_Fighter {

	namespace ObjectTypes {

		/*
		A LivingObject which is immortal and will always regester as alive.*/
		class ImmortalObject : public LivingObject {
		public:
			/*
			Returns true.*/
			virtual bool isAlive();
			/*
			Returns ImmortalObject_Type.*/
			virtual LO_Type LO_TypeCode();

		};

	}

}
