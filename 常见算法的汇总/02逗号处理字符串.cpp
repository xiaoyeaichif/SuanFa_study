#include <iostream>
#include <sstream>
#include <vector>
#include <string>


int main_input02()
{
	std::string str;
	//��ȡ��׼�������е�һ���ı�,֪���������з�Ϊֹ
	std::cout << "Enter a line of text: ";
	//getline�ĵ����������ǰ��ո����ķָ��ַ�����ֱ�������ָ���Ϊֹ�Ż�ֹͣ
	getline(std::cin, str, ',');

	//Ĭ�ϵ�getline�������з�����ֹ, ���ǵ�������������ָ������ֹͣ
	//getline(std::cin, str);
	std::cout << "You entered: " << str << std::endl;
	std::cout << "size:" << str.size() << std::endl;
	return 0;
}