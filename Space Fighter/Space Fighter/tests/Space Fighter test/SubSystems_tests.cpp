#include "stdafx.h"
#include "Ships\Sub Systems\ThrustSubSystem.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace Space_Fighter::Ships::SubSystems;

namespace SpaceFightertest {
	[TestClass]
	public ref class SubSystem_tests {
	public:

		[TestMethod]
		void ThrustSystem_test() {
			ThrustSubSystem obj(new __int32[Directions::Directions_Max]{ 1000,1000,1000,1000,1000,1000 }, ThrustSubSystem::vector(0), 100);

			Assert::IsTrue(obj.getAdjustedAcceleration() == ThrustSubSystem::vector(0), L"initial \"getAdjustedAcceleration\" failed.");

			Assert::IsTrue(obj.getAdjustedAccelerationMax(Directions::North) == 10, L"\"getAdjustedAccelerationMax(NORTH)\" failed.");

			Assert::IsTrue(obj.getAdjustedAccelerationMax(Directions::South) == 10, L"\"getAdjustedAccelerationMax(SOUTH)\" failed.");

			Assert::IsTrue(obj.getAdjustedAccelerationMax(Directions::East) == 10, L"\"getAdjustedAccelerationMax(EAST)\" failed.");

			Assert::IsTrue(obj.getAdjustedAccelerationMax(Directions::West) == 10, L"\"getAdjustedAccelerationMax(WEST)\" failed.");

			Assert::IsTrue(obj.getAdjustedAccelerationMax(Directions::Up) == 10, L"\"getAdjustedAccelerationMax(UP)\" failed.");

			Assert::IsTrue(obj.getAdjustedAccelerationMax(Directions::Down) == 10, L"\"getAdjustedAccelerationMax(DOWN)\" failed.");

			Assert::IsTrue(obj.getThrottle() == ThrustSubSystem::vector(0), L"\"getThrottle\" failed.");

			Assert::IsTrue(obj.setThrottle(ThrustSubSystem::vector(50)).getAdjustedAcceleration()
						   == ThrustSubSystem::vector(5), L"\"getAdjustedAcceleration\" failed.");

		}

	};
}
