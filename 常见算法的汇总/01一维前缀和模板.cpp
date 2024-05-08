#include<iostream>
#include<vector>
using namespace std;

/*
/*
输入格式：
第一行包含两个整数n和m。
第二行包含n个整数，表示整数数列。
接下来m行，每行包含两个整数l 和r，表示一个询问的区间范围。

输出格式
共m行，每行输出一个询问的结果。
*/
//使用全局变量来写, 效率更高
//先把数组开辟好,然后开辟的数组大一点

// 这里是防止各个文件的访问
//const int N = 1e+5 + 10;
//vector<int>nums(N, 0);
//vector<int>sum(N, 0);
////输入的两个数
//int n, m;
//int main01()
//{
//	cin >> n >> m;
//	//把数组填满
//	for (int i = 0; i <n; i++)
//	{
//		cin >> nums[i];
//	}
//	//要手动初始化前缀和的第一个元素
//	//初始化前缀和数组
//	sum[0] = nums[0];
//	for (int i = 1; i <n; i++)
//	{
//		sum[i] = sum[i - 1] + nums[i];
//	}
//	//用来验证代码的是否符合的
//	/*for (int num : nums) cout << num << ' ';
//	cout << endl;
//	for (int num : sum) cout << num << ' ';
//	cout << endl;*/
//	//接下来处理输入的m行数据
//	while (m--)
//	{
//		//要获取区间[l....r]之间的数字和
//		int l, r;
//		cin >> l >> r;
//		cout << sum[r] - sum[l - 1] << endl;
//	}
//	return 0;
//}
