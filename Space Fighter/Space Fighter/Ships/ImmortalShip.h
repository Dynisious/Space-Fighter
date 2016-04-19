#pragma once

#include "Ship.h"
#include "..\Object Types\ImmortalObject.h"

namespace Space_Fighter {

	namespace Ships {

		/*
		A Ship object which is incapable of dying.*/
		class ImmortalShip : public Ship, public ObjectTypes::ImmortalObject {
		public:
			ImmortalShip(const Ship & ship, const ImmortalObject & immortality);
			ImmortalShip(const MountObject & mountings, const Entity & entity, const SubSystems::ThrustSubSystem & thrusters, const ImmortalObject & immortality);
			ImmortalShip(const MountObject & mountings, const CollidableObject & collide, const PositionObject & pos, const SubSystems::ThrustSubSystem & thrusters, const ImmortalObject & immortality);
			ImmortalShip(const ImmortalShip & orig);
			virtual ~ImmortalShip();

		};

	}

}
