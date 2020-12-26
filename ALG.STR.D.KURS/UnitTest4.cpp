#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "../ALG4/Header.h"
#include "\Users\zzzAzzz\source\repos\ALG4\Funct.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest4
{
	TEST_CLASS(UnitTest4)
	{
	public:
		TEST_METHOD(add_exp)
		{
			expression testExp;
			string vvod, test;
			vvod.push_back('3');
			vvod.push_back('7');
			vvod.push_back(' ');
			vvod.push_back('+');
			vvod.push_back(' ');
			vvod.push_back('5');
			vvod.push_back('6');
			vvod.push_back(' ');
			vvod.push_back('*');
			vvod.push_back(' ');
			vvod.push_back('7');

			test.push_back('+');
			test.push_back(' ');
			test.push_back('3');
			test.push_back('7');
			test.push_back('*');
			test.push_back(' ');
			test.push_back('5');
			test.push_back('6');
			test.push_back(' ');
			test.push_back('7');

			testExp.setExp(vvod);
			testExp.add_exp();

			Assert::AreEqual(test, testExp.retExp());
		}

		TEST_METHOD(counting_test)
		{
			expression testExp;
			string vvod, test;
			vvod.push_back('3');
			vvod.push_back('7');
			vvod.push_back(' ');
			vvod.push_back('+');
			vvod.push_back(' ');
			vvod.push_back('5');
			vvod.push_back('6');
			vvod.push_back(' ');
			vvod.push_back('*');
			vvod.push_back(' ');
			vvod.push_back('7');

			test.push_back('+');
			test.push_back(' ');
			test.push_back('3');
			test.push_back('7');
			test.push_back('*');
			test.push_back(' ');
			test.push_back('5');
			test.push_back('6');
			test.push_back(' ');
			test.push_back('7');

			testExp.setExp(vvod);
			testExp.add_exp();
			double t = 429;

			Assert::AreEqual(t, testExp.Counting());
		}

	};
}
