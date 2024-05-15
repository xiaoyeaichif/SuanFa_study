#include<iostream>
#include<string>

using namespace std;


/*
	check函数的书写
	check函数代表输入当前的每一次可以修改字符的长度,将,字符串全部变成R需要修改的次数
*/
//s是只包含字符W和R的字符串
int check(string& s, int k)
{
	//边界条件,如果能修改的字符长度为k == 0，则返回一个无穷大作为标记,证明字符不可以被修改
	if (k == 0) return INT_MAX;
	int count = 0;//用来统计次数
	int N = s.size();
	for (int i = 0; i < N; i++)
	{
		if (s[i] == 'W')//代表需要修改了,次数+1
		{
			count += 1;
			//指针应该后移 i + k个位置,但是由于外层循环还要移动一次指针,所以里面只需要移动i+k-1
			i = i + k - 1;
		}

	}
	return count;
}

int main_erfen05()
{
	/*string str = "WRWWWR";
	int k = 5;
	cout << check(str, k) << endl;*/
	int n, m;
	cin >> n >> m;
	string str;
	cin >> str;
	//首先能修改的长度最小肯定为0,最大为数组的长度
	int l = 0;
	int r = str.size();
	//跟踪答案
	int ans = 0;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (check(str, mid) <= m)
		{
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout<<ans<<endl;
	return 0;

}