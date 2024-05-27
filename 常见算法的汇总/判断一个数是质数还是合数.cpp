#include<iostream>
#include<vector>

using namespace std;

//质数是只能由1和自己整除的数
bool isPrime(int num)
{
	//1:num <= 1 肯定不是质数
	if (num <= 1)
	{
		return false;
	}
	//2是一个质数
	if (num == 2) return true;
	//除了2以外的偶数都不是质数
	if (num % 2 == 0) return false;
	//对于大于2的数，检查是否存在任何小于其平方根的数可以整除它。
	// 如果存在这样的数，那么它是合数；否则，它是质数
	int sqRoot = static_cast<int>(std::sqrt(num));
	for (int i = 3; i <= sqRoot; i += 2)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

//第二种写法
bool isPrime1(int num)
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




// 判断是否为合数
bool isComposite(int num) {
	return num > 1 && !isPrime(num);
}

int main_zhishu()
{
	int n;
	cin >> n;
	vector<int>nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (isPrime1(nums[i]))
		{
			cout << nums[i]<< "是一个质数"<< endl;
		}
		else {
			cout <<nums[i]<< "是一个合数"<<endl;
		}
	}
	return 0;
}