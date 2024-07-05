#include<iostream>
using namespace std;


int main_zhishi03()
{
	int a = 10;
	int b = 11;
	const int* p = &a;//常量指针
	cout << "========验证常量指针的变化==========" << endl;
	cout << "指针p的地址为："<<p<<","<<"指针p的值为: "<<*p << endl;
	//试图修改常量的大小
	//*p = 11;//不可以修改
	//可以修改p的指向改变p的大小
	p = &b;
	cout << "修改后指针p的地址为：" << p << "," << "修改后指针p的值为: " << *p << endl;
	cout << "========验证指针常量的变化==========" << endl;
	//验证指针常量的变化
	int* const q = &a;
	cout << "指针q的地址为：" << q << "," << "指针q的值为: " << *q << endl;
	//指针常量，指针是一个常量不可以修改,但是可以修改指针指向的值
	//q = &b;//这是不允许的
	a = b;
	cout << "修改后指针q的地址为：" << q << "," << "修改后指针p的值为: " << *q << endl;
	return 0;
}