#include<iostream>
#include<functional>

using namespace std;


void hello(string str)
{
	cout << str << endl;
}

int sum(int a, int b)
{
	return a + b;
}


class test {
public:
	int sum(int a, int b) { return a + b; }
};

/*
*
*
*
*/
int main_bind_000010()
{
	cout << "------------------bind函数的使用--------------------" << endl;
	// bind器后面的括号不要忘记
	auto bindFunc1 = bind(sum, std::placeholders::_1,std::placeholders::_2);
	cout << bindFunc1(10,20) << endl;
	// 类的成员函数bind
	// 绑定成员对象
	auto bindFunc2 = bind(&test::sum, std::placeholders::_1, std::placeholders::_2);
	cout << bindFunc1(10, 20) << endl;
	auto boundFunc3 = bind(hello, placeholders::_1);
	boundFunc3("yejie nihao!");
	cout << "------------------bind函数的结束--------------------" << endl;
	cout << "----------bind结合function函数的使用-----------------" << endl;
	// 返回值为int，参数为int,int--------->其实就是函数对象定义
	// 表示有这么一种类型返回int，参数为int，int的变量（函数）
	// 那么 Function1 fun 类似于 int a
	using Function1 = function<int(int, int)>;
	Function1 fun1 = sum;
	cout << fun1(10, 20) << endl;
	
	return 0;
}