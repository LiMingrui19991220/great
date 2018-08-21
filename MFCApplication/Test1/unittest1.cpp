#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
			int m_number1=3,m_number2=5,result;
			result = m_number1 * m_number2;
			Assert::AreEqual(15,result);
			// TODO: 在此输入测试代码
		}

	};
}