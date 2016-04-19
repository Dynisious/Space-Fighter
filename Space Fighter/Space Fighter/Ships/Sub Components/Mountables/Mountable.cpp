#include "Mountable.h"

Space_Fighter::Ships::SubComponents::Mountable::Mountable() : orientation(0.0) {}

Space_Fighter::Ships::SubComponents::Mountable::Mountable(const Space_Fighter::ObjectTypes::PositionObject::rotation orientation) 
	: orientation(orientation) {}

Space_Fighter::Ships::SubComponents::Mountable::~Mountable() {}

Space_Fighter::Ships::SubComponents::Mountable & Space_Fighter::Ships::SubComponents::Mountable::rotate(const ObjectTypes::PositionObject::rotation & rot) {
	orientation += rot;
	return (Mountable&) *this;
}

Space_Fighter::Ships::SubComponents::Mountable & Space_Fighter::Ships::SubComponents::Mountable::setOrientation(const ObjectTypes::PositionObject::rotation & ori) {
	orientation = ori;
	return (Mountable&) *this;
}

Space_Fighter::ObjectTypes::PositionObject::rotation Space_Fighter::Ships::SubComponents::Mountable::getOrientation() {
	return orientation;
}

bool Space_Fighter::Ships::SubComponents::Mountable::operator==(Mountable & obj) {
	if (this == &obj)
		return true;
	return orientation == obj.orientation;
}

bool Space_Fighter::Ships::SubComponents::Mountable::operator!=(Mountable & obj) {
	return !operator==(obj);
}
