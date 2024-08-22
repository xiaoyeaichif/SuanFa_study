#include<iostream>
#include<functional>

using namespace std;


int add(int a, int b)
{
	return a + b;
}

int main()
{
	// function<int(int, int)>的别名是func1
	using func1 = function<int(int, int)>;
	func1 fun = add;
	cout << fun(10, 20) << endl;
	return 0;
}