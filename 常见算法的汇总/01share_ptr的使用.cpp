

#include<iostream>
#include<memory>

using namespace std;

//ֻ��ָ�����ü�����ʹ��
void use_sharedptr()
{
    //���Ƕ���һ��ָ������5��ָ��
    auto psint2 = make_shared<int>(5);
    auto psstr2 = make_shared<string>("hello zack");
    //��psint2��ֵ��psint3,���ǵײ������ָ����ͬ
    // psint3��psint2���ü�����ͬ�����ü���+1����Ϊ2
    shared_ptr<int> psint3 = psint2;
    //��ӡ���ü���
    cout << "psint2 usecount is " << psint2.use_count() << endl;
    cout << "psint3 usecount is " << psint3.use_count() << endl;
    // psint3���ü���Ϊ1
    psint3 = make_shared<int>(1024);
    // psint2���ü���-1����Ϊ1
    //��ӡ���ü���
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