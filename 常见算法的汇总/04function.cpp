#include<iostream>
#include<functional>

using namespace std;


int add(int a, int b)
{
	return a + b;
}

int main_function()
{
	// function<int(int, int)>的别名是func1
	// 返回值为int,参数列表为int，int
	using func1 = function<int(int, int)>;
	func1 fun = add;
	cout << fun(10, 20) << endl;
	// 方式2
	function<int(int, int)> func2;
	cout << func2(10, 20) << endl;
	return 0;
}