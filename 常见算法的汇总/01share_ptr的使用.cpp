

#include<iostream>
#include<memory>

using namespace std;

//只能指针引用计数的使用
void use_sharedptr()
{
    //我们定义一个指向整形5得指针
    auto psint2 = make_shared<int>(5);
    auto psstr2 = make_shared<string>("hello zack");
    //将psint2赋值给psint3,他们底层的内置指针相同
    // psint3和psint2引用计数相同，引用计数+1，都为2
    shared_ptr<int> psint3 = psint2;
    //打印引用计数
    cout << "psint2 usecount is " << psint2.use_count() << endl;
    cout << "psint3 usecount is " << psint3.use_count() << endl;
    // psint3引用计数为1
    psint3 = make_shared<int>(1024);
    // psint2引用计数-1，变为1
    //打印引用计数
    cout << "psint2 usecount is " << psint2.use_count() << endl;
    cout << "psint3 usecount is " << psint3.use_count() << endl;
}


int main_memory01()
{
	shared_ptr<int>p1 = make_shared<int>(5);
	cout << p1 << endl;
    use_sharedptr();
	return 0;
}