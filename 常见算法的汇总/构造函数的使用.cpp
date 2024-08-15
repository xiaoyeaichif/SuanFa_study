#include <iostream>
#include <utility> // For std::move
using namespace std;

class Myclass {
public:
    Myclass(int a = 10)
    {
        cout << "Myclass 默认构造函数的调用" << endl;
    }
    // 拷贝构造函数
    Myclass(const Myclass& temp)
    {
        cout << "Myclass& 拷贝构造函数的调用" << endl;
    }
    // 移动构造函数
    Myclass(Myclass&& temp)
    {
        cout << "Myclass&& 移动构造函数的调用" << endl;
    }
    // 赋值构造函数的调用
    Myclass& operator=(const Myclass& temp)
    {
        cout << "operator= 赋值函数的调用" << endl;
        return *this;
    }
    // 移动赋值操作符
    Myclass& operator=(Myclass&& temp)
    {
        cout << "operator= 移动赋值函数的调用" << endl;
        return *this;
    }
    ~Myclass()
    {
        cout << "析构函数的调用" << endl;
    }
private:
    int num;
};

// 
Myclass func(Myclass &temp)
{
    // 由于num出来作用域就会消失，所以使用右值来标定该对象
    Myclass num = std::move(temp); // 使用 std::move
    return num;
}


/*

    Myclass 默认构造函数的调用
    Myclass& 拷贝构造函数的调用
    operator= 赋值函数的调用 
    // 编译器会优化这两个步骤
    // 这两个步骤就是生成num的临时对象
            **Myclass&& 移动构造函数的调用
            **析构函数的调用
    Myclass&& 移动构造函数的调用
    析构函数的调用  // temp3
    析构函数的调用  // temp2
    析构函数的调用  // temp1
*/

int main_gouz01()
{
    Myclass temp1;
    Myclass temp2 = temp1;
    temp2 = temp1;
    /*
        func函数调用
            首先使用拷贝构造函数构造参数
            ---》然后使用移动构造函数来初始化num对象
            ---》最后使用移动构造函数再次构造num的临时对象
    */
    Myclass temp3 = func(temp2);
    return 0;
}

