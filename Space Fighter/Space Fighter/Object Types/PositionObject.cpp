#include "PositionObject.h"

Space_Fighter::ObjectTypes::PositionObject::PositionObject() : location(0), orientation(0.0) {}

Space_Fighter::ObjectTypes::PositionObject::PositionObject(const position& loc, const rotation& ori) : location(loc), orientation(ori) {}

Space_Fighter::ObjectTypes::PositionObject::~PositionObject() {}

Space_Fighter::ObjectTypes::PositionObject& Space_Fighter::ObjectTypes::PositionObject::translate(const position& trans) {
	location += trans;
	return *this;
}

Space_Fighter::ObjectTypes::PositionObject& Space_Fighter::ObjectTypes::PositionObject::setLocation(const position& loc) {
	location = loc;
	return *this;
}

Space_Fighter::ObjectTypes::PositionObject::position Space_Fighter::ObjectTypes::PositionObject::getLocation() {
	return location;
}

Space_Fighter::ObjectTypes::PositionObject& Space_Fighter::ObjectTypes::PositionObject::rotate(const rotation& rot) {
	orientation += rot;
	return *this;
}

Space_Fighter::ObjectTypes::PositionObject& Space_Fighter::ObjectTypes::PositionObject::setOrientation(const rotation& ori) {
	orientation = ori;
	return *this;
}

Space_Fighter::ObjectTypes::PositionObject::rotation Space_Fighter::ObjectTypes::PositionObject::getOrientation() {
	return orientation;
}
