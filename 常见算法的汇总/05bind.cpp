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
	// bind����������Ų�Ҫ����
	cout << bind(sum, 10, 20)() << endl;
	// ��ĳ�Ա����bind
	// �󶨳�Ա����
	cout << bind(&test::sum, test(),10, 20)() << endl;
	bind(hello, placeholders::_1);
	return 0;
}