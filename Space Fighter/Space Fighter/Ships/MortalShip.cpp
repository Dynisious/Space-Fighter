#include "MortalShip.h"

Space_Fighter::Ships::MortalShip::MortalShip(const Ship & ship, const MortalObject & mortality) : Ship(ship), MortalObject(mortality) {}

Space_Fighter::Ships::MortalShip::MortalShip(const SubComponents::MountObject & mountings, const CollidableObject & collisions, const PositionObject & pos, const SubSystems::ThrustSubSystem & thrusters, const MortalObject & mortality)
	: Ship(mountings, collisions, pos, thrusters), MortalObject(mortality) {}

Space_Fighter::Ships::MortalShip::MortalShip(const SubComponents::MountObject & mountings, const Entity & entity, const SubSystems::ThrustSubSystem & thrusters, const MortalObject & mortality)
	: Ship(mountings, entity, thrusters), MortalObject(mortality) {}

Space_Fighter::Ships::MortalShip::MortalShip(const MortalShip & orig) : Ship(orig), MortalObject(orig) {}

Space_Fighter::Ships::MortalShip::~MortalShip() {}
