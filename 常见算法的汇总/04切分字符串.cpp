#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<sstream>

using namespace std;
/*
	check函数的输入值为字符串,以及权值
	我们要返回的的是在该权值的下,输出满足子串的个数
*/
int check(string str, int target)
{
	//统计长度
	int len = 0;
	unordered_set<char>u_set;
	int size = str.size();
	//统计个数
	int ans = 0;
	for (int i = 0; i < str.size(); i++)
	{
		//往哈希表添加元素
		u_set.insert(str[i]);
		len++;
		//找到第一个权值大于target的字符串
		//更新个数,这里要注意下标i还需要处理
		if (len * u_set.size() > target)
		{
			ans++;
			//长度需要重新计数
			len = 0;
			//清空哈希表
			u_set.clear();
			//下标回退一个,因为当前的i是下一个子串的起始位置
			i -= 1;
		}
	}
	//如果最终哈希表中还存在元素时,证明此时还有一个子串未统计
	if (!u_set.empty()) ans++;
	return ans;
}

int main_erfen04()
{
	string str;
	cin >> str;
	int k;
	cin >> k;
	//cout << check(str, k) << endl;
	//二分的处理
	int l = 1;
	int	r = 1e9;
	//记录答案
	int ans = 0;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (check(str, mid) <= k)
		{
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ans << endl;
	return 0;
}