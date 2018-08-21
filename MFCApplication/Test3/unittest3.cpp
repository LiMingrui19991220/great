#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test3
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int m_number1=7, result;
			result = 3.14159*m_number1*m_number1;
			Assert::AreEqual(15, result);// TODO: 在此输入测试代码
		}

	};
}