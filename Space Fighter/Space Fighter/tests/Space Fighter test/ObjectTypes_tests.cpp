#include "stdafx.h"
#include "../../PositionObject.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

template POSITION;
template ROTATION;

namespace Space_Fighter_test {
	[TestClass]
	public ref class ObjectTypes_tests {
	public:

		[TestMethod]
		void PositionObject_test() {
			PositionObject obj;

			Assert::IsTrue(obj.translate(POSITION(1)).getLocation() == POSITION(1), L"\"translate\" failed.");

			Assert::IsTrue(obj.setLocation(POSITION(0)).getLocation() == POSITION(0), L"\"setLocation\" failed.");

			Assert::IsTrue(obj.rotate(ROTATION(1.0)).getOrientation() == ROTATION(1.0), L"\"rotate\" failed.");

			Assert::IsTrue(obj.setOrientation(ROTATION(0.0)).getOrientation() == ROTATION(0.0), L"\"setOrientation\" failed.");

		}

	};
}
