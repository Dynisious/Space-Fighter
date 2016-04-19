#pragma once

#include "Ship.h"
#include "..\Object Types\MortalObject.h"

namespace Space_Fighter {

	namespace Ships {

		/*
		A ShipEntity type which is mortal and able to die.*/
		class MortalShip : public Ship, public ObjectTypes::MortalObject {
		public:
			MortalShip(const Ship & ship, const MortalObject & mortality);
			MortalShip(const MountObject & mountings, const Entity & entity, const SubSystems::ThrustSubSystem & thrusters, const MortalObject & mortality);
			MortalShip(const MountObject & mountings, const CollidableObject & collide, const PositionObject & pos, const SubSystems::ThrustSubSystem & thrusters, const MortalObject & mortality);
			MortalShip(const MortalShip & orig);
			virtual ~MortalShip();

		};

	}

}
