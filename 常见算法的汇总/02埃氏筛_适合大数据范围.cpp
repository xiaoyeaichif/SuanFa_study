#include<iostream>
#include<vector>

using namespace std;

static const int N = 5E6 + 10;
static vector<int>prime(N);//记录所有的质数存放的位置,如果单独统计个数,这个数组可以不要
static vector<bool>used(N);//用来记录当前的数字是不是质数,true:表示不是质数,false表示是质数
static int n;
static int cnt = 0;//记录质数出现的个数
void get_prime(int n)
{
	if (n <= 1) return;
	for (int i = 2; i <= n; i++)
	{
		if (used[i]) continue;
		prime[cnt++] = i;//将质数填进数组中
		//将质数对应的倍数删除，因为他们不可能为质数
		//如质数2,它的整数倍为4，6，8....等等,都不可能为质数
		for (int j = i + i; j <= n; j += i)
		{
			used[j] = true;//表示当前的数不是质数
		}
	}
}

static bool isPrime1(int num)
{
	//1:num <= 1 肯定不是质数
	if (num <= 1)
	{
		return false;
	}
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0) return false;//满足就不是质数
	}
	//则输出为质数
	return true;
}


int main_aishishai02()
{
	cin >> n;
	get_prime(n);
	cout <<"埃氏筛的做法:" << cnt << endl;
	for (int i = 0; i < cnt;i++)
	{
		cout << prime[i] << ' ';
	}
	return 0;
}