#include <iostream>
#include <sstream>
#include <vector>
#include <string>


int main_input02()
{
	std::string str;
	//读取标准输入流中的一行文本,知道遇到换行符为止
	std::cout << "Enter a line of text: ";
	//getline的第三个参数是按照给定的分割字符串，直到遇到分隔符为止才会停止
	getline(std::cin, str, ',');

	//默认的getline遇到换行符号终止, 但是第三个参数可以指定符号停止
	//getline(std::cin, str);
	std::cout << "You entered: " << str << std::endl;
	std::cout << "size:" << str.size() << std::endl;
	return 0;
}