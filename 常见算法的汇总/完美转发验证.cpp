#include<iostream>
#include<vector>

using namespace std;




// һ��ʵ�ʵĴ�����
void process(int& x) {
    std::cout << "Lvalue reference: " << x << std::endl;
}

void process(int&& x) {
    std::cout << "Rvalue reference: " << x << std::endl;
}

template<typename T>
void wrapper(T&& arg) {
    // ֱ�Ӵ��� arg��û��ʹ�� std::forward
    process(arg);
}


int main10009()
{
    int a = 10;
    process(a);           // ������ֵ
    process(20);          // ������ֵ
    // ��ʹ������ת��
    wrapper(a);
    wrapper(20);
    return 0;
}