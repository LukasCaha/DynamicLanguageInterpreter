#include <vector>

#include "pch.h"
#include "CppUnitTest.h"
#include "../DynamicLanguageIntepreter/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTests
{
	TEST_CLASS(InstructionTests)
	{
	public:
		
		TEST_METHOD(HelloWorld)
		{
			std::string expected = "\"HelloWorld!\"\n";
			vector<string> lines;
			lines.push_back("");		//line 0
			lines.push_back("text hello HelloWorld!");	
			lines.push_back("print hello");
			std::string actual = GetProgramOutput(lines);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(PrintNumber)
		{
			std::string expected = "15\n";
			vector<string> lines;
			lines.push_back("");		//line 0
			lines.push_back("number a 15");
			lines.push_back("print a");
			std::string actual = GetProgramOutput(lines);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(PrintNegativeNumber)
		{
			std::string expected = "-445\n";
			vector<string> lines;
			lines.push_back("");		//line 0
			lines.push_back("number a -445");
			lines.push_back("print a");
			std::string actual = GetProgramOutput(lines);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(PrintZero)
		{
			std::string expected = "0\n";
			vector<string> lines;
			lines.push_back("");		//line 0
			lines.push_back("number a 0");
			lines.push_back("print a");
			std::string actual = GetProgramOutput(lines);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Sum1)
		{
			std::string expected = "8\n";
			vector<string> lines;
			lines.push_back("");		//line 0
			lines.push_back("number a 6");
			lines.push_back("number b 2");
			lines.push_back("sum c a b");
			lines.push_back("print c");
			std::string actual = GetProgramOutput(lines);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Sum2)
		{
			std::string expected = "8\n";
			vector<string> lines;
			lines.push_back("");		//line 0
			lines.push_back("number a 6");
			lines.push_back("number b 2");
			lines.push_back("sum c a b");
			lines.push_back("print c");
			std::string actual = GetProgramOutput(lines);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Sum3)
		{
			std::string expected = "0\n";
			vector<string> lines;
			lines.push_back("");		//line 0
			lines.push_back("number a -6");
			lines.push_back("number b 6");
			lines.push_back("sum c a b");
			lines.push_back("print c");
			std::string actual = GetProgramOutput(lines);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Sum4)
		{
			std::string expected = "-1024\n";
			vector<string> lines;
			lines.push_back("");		//line 0
			lines.push_back("number a -512");
			lines.push_back("sum c a a");
			lines.push_back("print c");
			std::string actual = GetProgramOutput(lines);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Minus1)
		{
			std::string expected = "-5\n";
			vector<string> lines;
			lines.push_back("");		//line 0
			lines.push_back("number a 0");
			lines.push_back("number b 5");
			lines.push_back("minus c a b");
			lines.push_back("print c");
			std::string actual = GetProgramOutput(lines);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Minus2)
		{
			std::string expected = "-10\n";
			vector<string> lines;
			lines.push_back("");		//line 0
			lines.push_back("number a -5");
			lines.push_back("number b 5");
			lines.push_back("minus c a b");
			lines.push_back("print c");
			std::string actual = GetProgramOutput(lines);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Minus3)
		{
			std::string expected = "10\n";
			vector<string> lines;
			lines.push_back("");		//line 0
			lines.push_back("number a -5");
			lines.push_back("number b 5");
			lines.push_back("minus c b a");
			lines.push_back("print c");
			std::string actual = GetProgramOutput(lines);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Minus4)
		{
			std::string expected = "105\n";
			vector<string> lines;
			lines.push_back("");		//line 0
			lines.push_back("number a 0");
			lines.push_back("number b -105");
			lines.push_back("minus c a b");
			lines.push_back("print c");
			std::string actual = GetProgramOutput(lines);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Product1)
		{
			std::string expected = "63\n";
			vector<string> lines;
			lines.push_back("");		//line 0
			lines.push_back("number a 7");
			lines.push_back("number b 9");
			lines.push_back("product c a b");
			lines.push_back("print c");
			std::string actual = GetProgramOutput(lines);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Product2)
		{
			std::string expected = "63\n";
			vector<string> lines;
			lines.push_back("");		//line 0
			lines.push_back("number a -7");
			lines.push_back("number b -9");
			lines.push_back("product c a b");
			lines.push_back("print c");
			std::string actual = GetProgramOutput(lines);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Product3)
		{
			std::string expected = "-727865\n";
			vector<string> lines;
			lines.push_back("");		//line 0
			lines.push_back("number a -745");
			lines.push_back("number b 977");
			lines.push_back("product c a b");
			lines.push_back("print c");
			std::string actual = GetProgramOutput(lines);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(LongConcatOld)
		{
			std::string expected = "\"-5+17=12\"\n";
			vector<string> lines;
			lines.push_back("");		//line 0
			lines.push_back("number a -5");
			lines.push_back("number b 17");
			lines.push_back("text plus +");
			lines.push_back("text equals =");
			lines.push_back("sum sum a b");
			lines.push_back("");
			lines.push_back("concat aplus a plus");
			lines.push_back("concat aplusb aplus b");
			lines.push_back("concat aplusbequals aplusb equals");
			lines.push_back("concat aplusbequalssum aplusbequals sum");
			lines.push_back("print aplusbequalssum");
			std::string actual = GetProgramOutput(lines);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(LongConcatNew)
		{
			std::string expected = "\"-5_+_17_=_12\"\n";
			vector<string> lines;
			lines.push_back("");		//line 0
			lines.push_back("number a -5");
			lines.push_back("number b 17");
			lines.push_back("text plus +");
			lines.push_back("text equals =");
			lines.push_back("text delimiter _");
			lines.push_back("sum sum a b");
			lines.push_back("");
			lines.push_back("longConcat 5 delimiter result a plus b equals sum");
			lines.push_back("print result");
			std::string actual = GetProgramOutput(lines);
			Assert::AreEqual(expected, actual);
		}
	};

	TEST_CLASS(ProgramTests)
	{
	public:

		TEST_METHOD(RecodexTest)
		{
			std::string expected = "\"\"\n40\n2\n-10\n42\n\"402\"\n804\n\"Hello_World!\"\n\"ByeWorld\"\n\"Hello_World!ByeWorld\"\n\"40ByeWorld\"\n\"Hello_World!2\"\n0\n40\n40\n42\n";
			vector<string> lines;
			lines.push_back("");		//line 0
			lines.push_back("print unknown");
			lines.push_back("");
			lines.push_back("number a 40");
			lines.push_back("print a");
			lines.push_back("number b 2");
			lines.push_back("print b");
			lines.push_back("number c -10");
			lines.push_back("print c");
			lines.push_back("");
			lines.push_back("sum aplusb a b");
			lines.push_back("print aplusb");
			lines.push_back("concat acatb a b");
			lines.push_back("print acatb");
			lines.push_back("product acatbmulb acatb b");
			lines.push_back("print acatbmulb");
			lines.push_back("");
			lines.push_back("text s1 Hello_World!");
			lines.push_back("print s1");
			lines.push_back("text s2 ByeWorld");
			lines.push_back("print s2");
			lines.push_back("");
			lines.push_back("concat s1cats2 s1 s2");
			lines.push_back("concat acats2 a s2");
			lines.push_back("concat s1catb s1 b");
			lines.push_back("print s1cats2");
			lines.push_back("print acats2");
			lines.push_back("print s1catb");
			lines.push_back("");
			lines.push_back("sum s1pluss2 s1 s2");
			lines.push_back("sum apluss2 a s2");
			lines.push_back("sum s1plusa s1 a");
			lines.push_back("sum bplusacats2 b acats2");
			lines.push_back("print s1pluss2");
			lines.push_back("print apluss2");
			lines.push_back("print s1plusa");
			lines.push_back("print bplusacats2");
			lines.push_back("");
			lines.push_back("goto 43");
			lines.push_back("text wrong Wrong!");
			lines.push_back("print wrong");
			lines.push_back("goto 49");
			lines.push_back("");
			lines.push_back("lessThen cond a b");
			lines.push_back("jumpIfTrue 39 cond");
			lines.push_back("");
			lines.push_back("greaterThen cond a b");
			lines.push_back("jumpIfFalse 39 cond");
			std::string actual = GetProgramOutput(lines);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Loop)
		{
			std::string expected = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n";
			vector<string> lines;
			lines.push_back("");		//line 0
			lines.push_back("number i 0");
			lines.push_back("number increment 1");
			lines.push_back("number maximum 10");
			lines.push_back("");
			lines.push_back("lessThen break i maximum");
			lines.push_back("jumpIfFalse 11 break");
			lines.push_back("sum i i increment");
			lines.push_back("print i");
			lines.push_back("lessThen break i maximum");
			lines.push_back("goto 5");
			std::string actual = GetProgramOutput(lines);
			Assert::AreEqual(expected, actual);
		}

	};
}