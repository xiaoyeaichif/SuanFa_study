

#include<iostream>
using namespace std;

class Animal1 {
public:
	void make_sound()
	{
		cout << "动物在发出声音" << endl;
	}
};

//继承函数
class Cat1 : public Animal1{
public:
	void make_sound()
	{
		cout << "Cat在发出声音" << endl;
	}
};

class Dog1 : public Animal1 {
public:
	void make_sound()
	{
		cout << "Dog在发出声音" << endl;
	}
};
//+++++++++++++++++++++++++++++++++++虚函数实现
class Animal2 {
public:
	virtual void make_sound()
	{
		cout << "动物在发出声音" << endl;
	}
};

//继承函数
class Cat2 : public Animal2 {
public:
	void make_sound()
	{
		cout << "Cat在发出声音" << endl;
	}
};

class Dog2 : public Animal2 {
public:
	void make_sound()
	{
		cout << "Dog在发出声音" << endl;
	}
};

class bird {
public:
	virtual int eat() = 0;
};
int bird::eat()
{
	return 2;
}
class laoying :public bird {
	virtual int eat(){
		return 1;
	}
};

int main_yanzheng04()
{
	//根据继承的is-a关系
	Animal1* cat1 = new Cat1();
	Animal1* dog1 = new Dog1();
	cout << "==========基类函数没有实现为虚函数时==========" << endl;
	cat1->make_sound();
	dog1->make_sound();
	delete cat1;  // 释放内存
	delete dog1;  // 释放内存
	cout << "==========基类函数实现为虚函数时==========" << endl;
	Animal2* cat2 = new Cat2();
	Animal2* dog2 = new Dog2();
	cat2->make_sound();
	dog2->make_sound();
	delete cat2;  // 释放内存
	delete dog2;  // 释放内存
	bird* b = new laoying();
	cout << b->eat() << endl;
	cout << b->bird::eat() << endl;//输出纯虚基类
	return 0;
}