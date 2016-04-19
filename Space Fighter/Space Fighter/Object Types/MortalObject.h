#pragma once

#include "LivingObject.h"

namespace Space_Fighter {

	namespace ObjectTypes {

		/*
		A LivingObject which is able to be killed at which point it will
		regester as not alive.

		A MortalObject dies whenever it is currently alive and it's life
		points reach "0". Attempts to exceed the limits of "lifepoints_max"
		and "0" will result in the life points rounding to the closest limit.
		Whenever a MortalObject dies it's "died" function is called.

		By default "died" does nothing and should be overriden as necessary.*/
		class MortalObject : public LivingObject {
		public:
			MortalObject(const unsigned __int32 lfpnts, const unsigned __int32 lfpnts_max);
			/*
			Changes the life points of the MortalObject by lfpnts.*/
			LivingObject & changeLifePoints(const __int32 lfpnts);
			/*
			Sets the life points of the MortalObject.*/
			LivingObject & setLifePoints(const unsigned __int32 lfpnts);
			/*
			Returns the life points value of the MortalObject.*/
			unsigned __int32 getLifePoints();
			/*
			Changes the maximum life points of the MortalObject by lfpnts_max.*/
			LivingObject & changeMaxLifePoints(const __int32 lfpnts_max);
			/*
			Sets the maximum life points of the MortalObject.*/
			LivingObject & setMaxLifePoints(const unsigned __int32 lfpnts_max);
			/*
			Returns the maximum life points value of the MortalObject.*/
			unsigned __int32 getMaxLifePoints();
			/*
			Returns true if life points are greater than 0.*/
			virtual bool isAlive();
			/*
			Returns MortalObject_Type.*/
			virtual LO_Type LO_TypeCode();

		private:
			unsigned __int32 /*
							 The life points of the MortalObject.*/lifePoints, /*
							 The maximum value of life points for the MortalObject.*/lifePoints_max;

		protected:
			/*
			Called whenever life points is set to 0.*/
			virtual void died();

		};

	}

}
