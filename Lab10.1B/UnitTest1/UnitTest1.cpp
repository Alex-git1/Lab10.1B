#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab10.1B/Lab10.1B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Student students[5] = {
                { "Ivanov", 1, 0, 5, 5, { 10 } },
                { "Petrov", 2, 1, 4, 4, { 15 } },
                { "Sidorov", 3, 2, 3, 3, { 20 } },
                { "Koval", 4, 3, 5, 3, { 25 } },
                { "Shevchenko", 5, 4, 4, 5, { 30 } }
            };

            int count5, count4, count3;
            CountMathGrades(students, 5, count5, count4, count3);
            Assert::AreEqual(count5, 2); 
            Assert::AreEqual(count4, 1); 
            Assert::AreEqual(count3, 2);
		}
	};
}
