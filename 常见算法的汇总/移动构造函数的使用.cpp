#include <iostream>

class MyClass {
public:
    MyClass(int val) : value(val) {
        std::cout << "MyClass." << std::endl;
    }

    // �ƶ����캯��
    MyClass(MyClass&& other) noexcept : value(other.value) {
        std::cout << "MyClass&&" << std::endl;
        other.value = 0; // ������Դ
    }

    // �ƶ���ֵ������
    MyClass& operator=(MyClass&& other) noexcept {
        std::cout << "operator= MyClass &&" << std::endl;
        if (this != &other) {
            value = other.value;
            other.value = 0; // ������Դ
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
    MyClass obj2(std::move(obj1)); // ʹ���ƶ����캯��
    MyClass obj3(20);
    obj3 = std::move(obj2);        // ʹ���ƶ���ֵ������
    return 0;
}