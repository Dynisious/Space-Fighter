#include "stdafx.h"
#include "Object Types\PositionObject.h"
#include "Object Types\KineticObject.h"
#include "Object Types\CollidableObject.h"
#include "Object Types\MortalObject.h"
#include "Object Types\LivingObject.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace Space_Fighter::ObjectTypes;

namespace Space_Fighter_test {
	[TestClass]
	public ref class ObjectTypes_tests {
	public:

		[TestMethod]
		void PositionObject_test() {
			PositionObject obj;

			Assert::IsTrue(obj.translate(PositionObject::position(1)).getLocation() == PositionObject::position(1), L"\"translate\" failed.");

			Assert::IsTrue(obj.setLocation(PositionObject::position(0)).getLocation() == PositionObject::position(0), L"\"setLocation\" failed.");

			Assert::IsTrue(obj.rotate(PositionObject::rotation(1.0)).getOrientation() == PositionObject::rotation(1.0), L"\"rotate\" failed.");

			Assert::IsTrue(obj.setOrientation(PositionObject::rotation(0.0)).getOrientation() == PositionObject::rotation(0.0), L"\"setOrientation\" failed.");

		}

		[TestMethod]
		void KineticObject_test() {
			KineticObject obj;

			__int32 init[3] = { -1,-1,-1 };
			Assert::IsTrue(obj.accelerate(KineticObject::vector(init)).getAcceleration() == KineticObject::vector(init), L"\"accelerate( vector )\" failed.");

			Assert::IsTrue(obj.setAcceleration(-KineticObject::vector(init)).getAcceleration() == -KineticObject::vector(init), L"\"setAcceleration\" failed.");

			Assert::IsTrue(obj.accelerate().getVelocity() == -KineticObject::vector(init), L"\"accelerate\" failed.");

			Assert::IsTrue(obj.changeVelocity(KineticObject::vector(init)).getVelocity() == KineticObject::vector(0), L"\"changeVelocity\" failed.");

			Assert::IsTrue(obj.setVelocity(KineticObject::vector(init)).getVelocity() == KineticObject::vector(init), L"\"setVelocity\" failed.");
		}

		[TestMethod]
		void CollidableObject_test() {
			KineticObject::vector u(-100), v(100);
			CollidableObject obj1(1, KineticObject::vector(0), u), obj2(1, KineticObject::vector(0), v);

			obj1.collide(obj2);
			Assert::IsTrue(obj1.getVelocity() == -obj2.getVelocity() && obj1.getVelocity() == v, L"\"collide\" failed.");
		}

		[TestMethod]
		void LivingObject_test() {
			MortalObject obj(100, 100);

			Assert::IsTrue(obj.isAlive(), L"Initial \"isAlive\" failed.");

			obj.setLifePoints(0);
			Assert::IsFalse(obj.isAlive(), L"\"setLifePoints\" to \"0\" failed.");

			obj.setLifePoints(obj.getMaxLifePoints());
			Assert::IsTrue(obj.isAlive(), L"\"setLifePoints\" to \"max life points\" failed.");

			obj.setMaxLifePoints(0);
			Assert::IsFalse(obj.isAlive(), L"\"setMaxLifePoints\" to \"0\" failed.");
		}

	};
}
