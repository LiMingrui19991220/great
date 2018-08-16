// 面积计算器.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int Pictype, z;
	float  a, b, c, d, h,r;
	cout << "请输入序号，选择您想计算的单位。" << endl;
	cout << "1）---英寸" << endl;
	cout << "2）---厘米" << endl;
	cin >> z;
	switch(z)
	{
	case 1:
		cout << "请输入序号，选择您想计算的图形格式。" << endl;
		cout << "1）---圆" << endl;
		cout << "2）---正方形" << endl;
		cout << "3）---长方形" << endl;
		cout << "4）---三角形" << endl;
		cin >> Pictype;
		switch (Pictype)
		{
		case 1:
			cout << "请输入圆的半径" << endl;
			cin >> r;
			cout << "您想计算的圆的半径为" << r << "，面积为" <<setiosflags(ios::fixed)<<setprecision(3)<< 3.14159 * r * r * 2.54 * 2.54 <<"平方厘米" <<endl;
			break;
		case 2:
			cout << "请输入正方形的边长" << endl;
			cin >> a;
			cout << "您想计算的正方形的边长为" << a << "，面积为" << setiosflags(ios::fixed) << setprecision(3) << a * a * 2.54 * 2.54 << "平方厘米" << endl;
			break;
		case 3:
			cout << "请输入长方形的长和宽" << endl;
			cin >> b >> c;
			cout << "您想计算的长方形的长为" << b << "，宽为" << c << "，面积为" << setiosflags(ios::fixed) << setprecision(3) << b * c * 2.54 * 2.54 << "平方厘米" << endl;
			break;
		case 4:
			cout << "请输入三角形的底和高" << endl;
			cin >> d >> h;
			cout << "您想计算的三角形的底为" << d << "，高为" << h << "，面积为" << setiosflags(ios::fixed) << setprecision(3) << 0.5 * d * h * 2.54 * 2.54 << "平方厘米" << endl;
			break;
			
		}
		system("pause");
		return 0;
	case 2:
		cout << "请输入序号，选择您想计算的图形格式。" << endl;
		cout << "1）---圆" << endl;
		cout << "2）---正方形" << endl;
		cout << "3）---长方形" << endl;
		cout << "4）---三角形" << endl;
		cin >> Pictype;
		switch (Pictype)
		{
		case 1:
			cout << "请输入圆的半径" << endl;
			cin >> r;
			cout << "您想计算的圆的半径为" << r << "，面积为"<<setiosflags(ios::fixed) << setprecision(3) << 3.14159*r*r << "平方厘米" << endl;
			break;
		case 2:
			cout << "请输入正方形的边长" << endl;
			cin >> a;
			cout << "您想计算的正方形的边长为" << a << "，面积为" << setiosflags(ios::fixed) << setprecision(3) << a * a << "平方厘米" << endl;
			break;
		case 3:
			cout << "请输入长方形的长和宽" << endl;
			cin >> b >> c;
			cout << "您想计算的长方形的长为" <<  b << "，宽为"<< c << "，面积为" << setiosflags(ios::fixed) << setprecision(3) << b * c << "平方厘米" << endl;
			break;
		case 4:
			cout << "请输入三角形的底和高" << endl;
			cin >> d >> h;
			cout << "您想计算的三角形的底为" << d << "，高为" << h << "，面积为" << setiosflags(ios::fixed) << setprecision(3) << 0.5*d*h << "平方厘米" << endl;
			break;
		}
		system("pause");
		return 0;
	}
	
	
}

