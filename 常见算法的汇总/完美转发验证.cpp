#include<iostream>
#include<vector>

using namespace std;




// 一个实际的处理函数
void process(int& x) {
    std::cout << "Lvalue reference: " << x << std::endl;
}

void process(int&& x) {
    std::cout << "Rvalue reference: " << x << std::endl;
}

template<typename T>
void wrapper(T&& arg) {
    // 直接传递 arg，没有使用 std::forward
    process(arg);
}


int main10009()
{
    int a = 10;
    process(a);           // 传递左值
    process(20);          // 传递右值
    // 不使用完美转发
    wrapper(a);
    wrapper(20);
    return 0;
}