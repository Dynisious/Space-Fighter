#include "ImmortalShip.h"

Space_Fighter::Ships::ImmortalShip::ImmortalShip(const Ship & ship, const ImmortalObject & immortality) : Ship(ship), ImmortalObject(immortality) {}

Space_Fighter::Ships::ImmortalShip::ImmortalShip(const MountObject & mountings, const Entity & entity, const SubSystems::ThrustSubSystem & thrusters, const ImmortalObject & immortality) : Ship(mountings, entity, thrusters), ImmortalObject(immortality) {}

Space_Fighter::Ships::ImmortalShip::ImmortalShip(const MountObject & mountings, const CollidableObject & collide, const PositionObject & pos, const SubSystems::ThrustSubSystem & thrusters, const ImmortalObject & immortality)
	: Ship(mountings, collide, pos, thrusters), ImmortalObject(immortality) {}

Space_Fighter::Ships::ImmortalShip::ImmortalShip(const ImmortalShip & orig) : Ship(orig), ImmortalObject(orig) {}

Space_Fighter::Ships::ImmortalShip::~ImmortalShip() {}
