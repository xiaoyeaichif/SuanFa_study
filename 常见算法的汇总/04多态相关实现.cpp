

#include<iostream>
using namespace std;

class Animal1 {
public:
	void make_sound()
	{
		cout << "�����ڷ�������" << endl;
	}
};

//�̳к���
class Cat1 : public Animal1{
public:
	void make_sound()
	{
		cout << "Cat�ڷ�������" << endl;
	}
};

class Dog1 : public Animal1 {
public:
	void make_sound()
	{
		cout << "Dog�ڷ�������" << endl;
	}
};
//+++++++++++++++++++++++++++++++++++�麯��ʵ��
class Animal2 {
public:
	virtual void make_sound()
	{
		cout << "�����ڷ�������" << endl;
	}
};

//�̳к���
class Cat2 : public Animal2 {
public:
	void make_sound()
	{
		cout << "Cat�ڷ�������" << endl;
	}
};

class Dog2 : public Animal2 {
public:
	void make_sound()
	{
		cout << "Dog�ڷ�������" << endl;
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
	//���ݼ̳е�is-a��ϵ
	Animal1* cat1 = new Cat1();
	Animal1* dog1 = new Dog1();
	cout << "==========���ຯ��û��ʵ��Ϊ�麯��ʱ==========" << endl;
	cat1->make_sound();
	dog1->make_sound();
	delete cat1;  // �ͷ��ڴ�
	delete dog1;  // �ͷ��ڴ�
	cout << "==========���ຯ��ʵ��Ϊ�麯��ʱ==========" << endl;
	Animal2* cat2 = new Cat2();
	Animal2* dog2 = new Dog2();
	cat2->make_sound();
	dog2->make_sound();
	delete cat2;  // �ͷ��ڴ�
	delete dog2;  // �ͷ��ڴ�
	bird* b = new laoying();
	cout << b->eat() << endl;
	cout << b->bird::eat() << endl;//����������
	return 0;
}