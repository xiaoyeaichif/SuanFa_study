#include<iostream>
using namespace std;

//�ڴ����
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
    virtual void foo() {}  // �麯��
    virtual void bar() {}  // ��һ���麯��
};

class C : public B {
public:
    void foo() override {}  // ��д�麯��
};

//����Ĵ�СΪ1
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
    re_name = c;//��c��ֵ��ֵ��a,re_name�ĵ�ַ����û�з��ͱ仯��
    cout << a << ' '<<re_name << endl;
    cout << &c << ' ' << &re_name << endl;//c�ĵ�ַ��re_name��ַ�ǲ�һ����
    cout << &a << ' ' << &re_name << endl;
    return 0;
}
