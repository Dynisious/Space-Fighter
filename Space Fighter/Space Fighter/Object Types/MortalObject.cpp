#include "MortalObject.h"

Space_Fighter::ObjectTypes::MortalObject::MortalObject(const unsigned __int32 lfpnts, const unsigned __int32 lfpnts_max)
	: lifePoints(lfpnts > lfpnts_max ? lfpnts_max : lfpnts), lifePoints_max(lfpnts_max) {}

Space_Fighter::ObjectTypes::LivingObject & Space_Fighter::ObjectTypes::MortalObject::changeLifePoints(const __int32 lfpnts) {
	if (-lfpnts > lifePoints)
		return setLifePoints(0);
	else
		return setLifePoints(lifePoints + lfpnts);
}

Space_Fighter::ObjectTypes::LivingObject & Space_Fighter::ObjectTypes::MortalObject::setLifePoints(const unsigned __int32 lfpnts) {
	if (lfpnts > lifePoints_max)
		lifePoints = lifePoints_max;
	else {
		if (lfpnts == 0)
			if (isAlive())
				died();
		lifePoints = lfpnts;
	}
	return (LivingObject&) *this;
}

unsigned __int32 Space_Fighter::ObjectTypes::MortalObject::getLifePoints() {
	return lifePoints;
}

Space_Fighter::ObjectTypes::LivingObject & Space_Fighter::ObjectTypes::MortalObject::changeMaxLifePoints(const __int32 lfpnts_max) {
	if (-lfpnts_max > lifePoints_max)
		return setMaxLifePoints(0);
	else
		return setMaxLifePoints(lfpnts_max + lifePoints_max);
}

Space_Fighter::ObjectTypes::LivingObject & Space_Fighter::ObjectTypes::MortalObject::setMaxLifePoints(const unsigned __int32 lfpnts_max) {
	if (lfpnts_max > 0) {
		lifePoints_max = lfpnts_max;
		if (lfpnts_max < lifePoints)
			lifePoints = lfpnts_max;
	} else {
		if (isAlive())
			died();
		lifePoints = lifePoints_max = lfpnts_max;
	}
	return (LivingObject&) *this;
}

unsigned __int32 Space_Fighter::ObjectTypes::MortalObject::getMaxLifePoints() {
	return lifePoints_max;
}

bool Space_Fighter::ObjectTypes::MortalObject::isAlive() {
	return lifePoints;
}

void Space_Fighter::ObjectTypes::MortalObject::died() {}

Space_Fighter::ObjectTypes::LO_Type Space_Fighter::ObjectTypes::MortalObject::LO_TypeCode() {
	return LO_Type::MortalObject_Type;
}
