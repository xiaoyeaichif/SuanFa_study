#include <iostream>
#include <vector>
#include <string>
#include<mutex>


class MyClass {
public:
    MyClass(int a, std::string b) : a_(a), b_(b) {
        std::cout << "Constructor called\n";
    }
    MyClass(const MyClass& other) : a_(other.a_), b_(other.b_) {
        std::cout << "Copy Constructor called\n";
    }
    MyClass(MyClass&& other) noexcept : a_(other.a_), b_(std::move(other.b_)) {
        std::cout << "Move Constructor called\n";
    }
private:
    int a_;
    std::string b_;
};

int main0109() {
    std::vector<MyClass> v;
    v.reserve(16);
    // std::lock_guard<std::mutex
   //  std::unique_lock<std::mutex>;

    std::cout << "Using push_back:\n";
    MyClass obj1(1, "example1");
    v.push_back(obj1);  // 会调用拷贝构造
    v.push_back(std::move(obj1)); // 会调用移动构造

    std::cout << "\nUsing emplace_back:\n";
    v.emplace_back(2, "example2"); // 直接在 vector 内存空间中构造，无需拷贝或移动
    std::cout << "\nover \n";

    int a = 10;
    int b = std::move(a);
    std::cout << a << std::endl;
    std::cout << b<< std::endl;
    return 0;
}
/*
输出：
Using push_back :
Constructor called
Copy Constructor called
Move Constructor called

Using emplace_back :
Constructor called

over
*/