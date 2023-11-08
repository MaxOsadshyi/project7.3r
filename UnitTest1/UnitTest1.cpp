#include "pch.h"
#include "CppUnitTest.h"
#include "../Project7.3r/FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int** a = {};
			const int rowCount = 6;
			const int colCount = 6;
			int i = 6;
			int j = 6;
			int minSum = 5;
			CalculateMinDiagonalSum( a,  rowCount,  colCount,  i,  j,  minSum);
			Assert::AreEqual(3, 3);
		}
	};
}
