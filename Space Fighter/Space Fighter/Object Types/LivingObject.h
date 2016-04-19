#pragma once

namespace Space_Fighter {

	namespace ObjectTypes {

		/*
		An enum of the different type codes returns by LO_TypeCode() of a
		LivingObject.*/
		enum LO_Type {
			/*
			The default return value, should never be returned from an object.*/
			Bad_Type,
			/*
			The return value of an ImmortalObject.*/
			ImmortalObject_Type,
			/*
			The return value of a MortalObject.*/
			MortalObject_Type
		};

		/*
		The base class of all LivingObjects, defining the two base functions.*/
		class LivingObject {
		public:
			virtual bool isAlive();
			virtual LO_Type LO_TypeCode();

		protected:
			LivingObject();

		};

	}

}
