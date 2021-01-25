#include <iostream>

#include "pch.h"
#include "CppUnitTest.h"
#include "../DynamicLanguageIntepreter/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestClassInit)
		{
			string expected = "Bill";
			string fileName = "input.txt";
			ostream &os = std::cout;
			Interpreter(fileName, os);
			Assert::AreEqual(name, mc.GetName());
		}
	};
}
