#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test2
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		
			int m_number = 2, result;
			result = m_number * m_number;
			Assert::AreEqual(4, result);// TODO: 在此输入测试代码
		}

	};
}