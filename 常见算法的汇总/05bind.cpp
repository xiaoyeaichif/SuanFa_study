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
int main_bind()
{
	// bind器后面的括号不要忘记
	cout << bind(sum, 10, 20)() << endl;
	// 类的成员函数bind
	// 绑定成员对象
	cout << bind(&test::sum, test(),10, 20)() << endl;
	bind(hello, placeholders::_1);
	return 0;
}