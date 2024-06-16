#include<iostream>
using namespace std;

//内存对齐
class  A1 {
    short a;
    int b;
    char c;
};
class  A2 {
    int b;
    short a;
    char c;
};

class  A3 {
    short a;
    char c;
    int b;
};

class B {
public:
    virtual void foo() {}  // 虚函数
    virtual void bar() {}  // 另一个虚函数
};

class C : public B {
public:
    void foo() override {}  // 重写虚函数
};

//空类的大小为1
class D {

};

int main_yanzhen02() {
    std::cout << "Size of class A1: " << sizeof(A1) << std::endl;
    std::cout << "Size of class A2: " << sizeof(A2) << std::endl;
    std::cout << "Size of class A3: " << sizeof(A3) << std::endl;
    std::cout << "Size of class B: " << sizeof(B) << std::endl;
    std::cout << "Size of class C: " << sizeof(C) << std::endl;
    std::cout << "Size of class D: " << sizeof(D) << std::endl;
    int a = 3;
    int c = 4;
    int& re_name = a;
    cout << &a << ' ' << &re_name << endl;
    re_name = c;//将c的值赋值给a,re_name的地址还是没有发送变化的
    cout << a << ' '<<re_name << endl;
    cout << &c << ' ' << &re_name << endl;//c的地址和re_name地址是不一样的
    cout << &a << ' ' << &re_name << endl;
    return 0;
}
