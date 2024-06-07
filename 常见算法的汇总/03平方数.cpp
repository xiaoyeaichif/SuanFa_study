

/*
	题目描述
薯条哥拿到一个整数x，并希望通过如下两个操作将x变为完全平方数。
	1：如x是素数，则将其减1
	2：否则，将其除以自己最小的素因子。
薯条哥需要操作多少次
*/

/*
	1：素因子(质因子)指的是合数的质因子,每个合数都能写成质数的乘积
	比如24 = 2 ✖ 2 ✖ 2 ✖ 3,最小的质因子就是2
	2: 使用埃氏筛会有空间复杂度的约束,不能超过10^6次方，所以要结合普通的质数筛选来做

*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

static const int N = 1E5 + 10;
static set<int>prime;//记录所有质数，包括自己
static vector<bool>used(N);//用来记录当前的数字是不是质数,true:表示不是质数,false表示是质数
static int n;
static void get_prime(int n)
{
	if (n <= 1) return;
	for (int i = 2; i <= n; i++)
	{
		if (used[i]) continue;
		prime.insert(i);//将质数填进数组中
		//将质数对应的倍数删除，因为他们不可能为质数
		//如质数2,它的整数倍为4，6，8....等等,都不可能为质数
		for (int j = i + i; j <= n; j += i)
		{
			used[j] = true;//表示当前的数不是质数
		}
	}
}

static bool isPrime(int num)
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

//判断一个数是不是等于自己的平方数
bool is_check(int x)
{
	int nums = sqrt(x);//开根号
	return nums * nums == x ;//检查开根号的平方是不是等于原数字
}



int main_math03()
{
	cin >> n;
	get_prime(N);//先记录质数的个数，以及质数的集合,这里的范围要注意,只有1e5
	int count = 0;//记录需要操作的次数
	//如果一个数不能完整的拆成自己的平方数，也就是不是4，9，16这种数字
	while (is_check(n) == false)
	{
		//当前的n是质数,
		// 并且范围在1e5次方内使用埃式筛
		//在这个范围外使用简单的求质数的方法
		if (n <= 1e5 && prime.count(n) || isPrime(n))
		{
			n--;//质数的大小减1
			count++;//操作加1
		}
		//当前的n不是质数,是合数
		else {
			//prime中存的全是质数
			for (auto& x : prime)
			{
				if (n % x == 0)//能不能除尽
				{
					n /= x;
					count++;
					break;
				}
			}
		}
	}
	cout << count << endl;
	return 0;
}