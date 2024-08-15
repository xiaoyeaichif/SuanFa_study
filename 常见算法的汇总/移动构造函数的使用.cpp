#include <iostream>

class MyClass {
public:
    MyClass(int val) : value(val) {
        std::cout << "MyClass." << std::endl;
    }

    // 移动构造函数
    MyClass(MyClass&& other) noexcept : value(other.value) {
        std::cout << "MyClass&&" << std::endl;
        other.value = 0; // 清理资源
    }

    // 移动赋值操作符
    MyClass& operator=(MyClass&& other) noexcept {
        std::cout << "operator= MyClass &&" << std::endl;
        if (this != &other) {
            value = other.value;
            other.value = 0; // 清理资源
        }
        return *this;
    }

    ~MyClass() {
        std::cout << "MyClass destructor called." << std::endl;
    }

private:
    int value;
};

int main_gouz02() {
    MyClass obj1(10);
    MyClass obj2(std::move(obj1)); // 使用移动构造函数
    MyClass obj3(20);
    obj3 = std::move(obj2);        // 使用移动赋值操作符
    return 0;
}