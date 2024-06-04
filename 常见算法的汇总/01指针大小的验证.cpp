#include<iostream>

using namespace std;

int main_yanzheng01()
{
	char * p1 = nullptr;//字符指针
	int * p2 = nullptr;
	//32位系统下,指针大小为4
	cout << "字符指针的大小:" << sizeof(p1) << endl;
	cout << "整形指针的大小:" << sizeof(p2) << endl;
	cout << "------------------------------------" << endl;
	//整型数组和字符数组移动一位代表多少
	//指针移动一个单位代表四个字节,解引用代表该指针指向的值
	int nums[] = {1,2,3,4,5};
	for (int i = 0; i < 5; i++)
	{
		cout << "数组中的元素依次是: " << *(nums+i) <<" 地址："<<nums+i << endl;
	}

	cout << "整型数组整个大小大小:"<<sizeof(nums) << endl;
	//(*nums)或者nums[0]都可以
	cout << "整型数组单个元素占用的大小:" << sizeof(*nums) << endl;
	cout << "数组的长度是: " << sizeof(nums) / sizeof(nums[0]) << endl;
	cout << "------------------------------------" << endl;


	//字符数组的验证,在声明时分配内存,并直接存储字符的内容
	char ans[] = { 1,2,3,'a'};
	//字符数组大小为整个数组的大小
	cout << "字符数组整个大小:" << sizeof(ans) << endl;
	//单个字符大小为1
	cout << "单个字符大小:" << sizeof(*ans) << endl;
	cout << "------------------------------------" << endl;
	// 常量字符指针,字符的值不可以修改,但是可以修改指针指向的方向
	const char* p3 = "Hello";
	cout << "字符指针 p3 指向的字符串: " << p3 << endl;
	//p3[0] = 'h'; // 错误，修改字符串常量会导致未定义行为
	cout << "字符指针的大小: " << sizeof(p3) << endl;

	return 0;
}