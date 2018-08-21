#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test4
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int m_number1 = 2, m_number2 = 222, result;
			result = m_number1 * m_number2*0.5;
			Assert::AreEqual(222, result);// TODO: 在此输入测试代码
		}

	};
}