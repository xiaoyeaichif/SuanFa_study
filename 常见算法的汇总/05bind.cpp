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
	cout << "------------------bind������ʹ��--------------------" << endl;
	// bind����������Ų�Ҫ����
	auto bindFunc1 = bind(sum, std::placeholders::_1,std::placeholders::_2);
	cout << bindFunc1(10,20) << endl;
	// ��ĳ�Ա����bind
	// �󶨳�Ա����
	auto bindFunc2 = bind(&test::sum, std::placeholders::_1, std::placeholders::_2);
	cout << bindFunc1(10, 20) << endl;
	auto boundFunc3 = bind(hello, placeholders::_1);
	boundFunc3("yejie nihao!");
	cout << "------------------bind�����Ľ���--------------------" << endl;
	cout << "----------bind���function������ʹ��-----------------" << endl;
	// ����ֵΪint������Ϊint,int--------->��ʵ���Ǻ���������
	// ��ʾ����ôһ�����ͷ���int������Ϊint��int�ı�����������
	// ��ô Function1 fun ������ int a
	using Function1 = function<int(int, int)>;
	Function1 fun1 = sum;
	cout << fun1(10, 20) << endl;
	
	return 0;
}