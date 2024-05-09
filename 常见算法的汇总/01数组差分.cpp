#include<iostream>
#include<vector>

using namespace  std;

void chafen_add(vector<int>& nums, int left, int right, int k)
{
	nums[left] += k;
	nums[right + 1] += -k;
}



int main_chafen()
{
	vector<int>ans = { 1,3,2,5,6,4 };
	/*
	   想要实现在 2 -> 4 整体都加上2, 然后3->5 整体上都加上-3
	*/
	//首先生成一个数组, 数组的大小比原先给定的数组大1
	int N = ans.size();
	//由于我们进行差分时,要处理R+1处的元素, 所以多开辟一个空间,防止数组越界
	vector<int>res(N + 1, 0);
	res[0] = ans[0];
	//构建差分数组
	cout << "构建差分数组: ";
	cout << res[0] << ' ';
	for (int i = 1; i < N; i++)
	{
		res[i] = ans[i] - ans[i - 1];
		cout << res[i] << ' ';
	}
	cout << res[N] << ' ';
	cout << endl;

	int L = 2, R = 5, k = 2;
	//差分数组的调用
	chafen_add(res, L, R, k);
	//差分数组未调用前缀和时候的值
	cout << "差分数组未调用前缀和时候的值: ";
	for (int i = 0; i < N + 1; i++)
	{
		cout << res[i] << ' ';
	}
	cout << endl;
	//差分数组调用前缀和的值
	//由于只需要0->N-1下标的值,所以N这个下标的值我们可以不管
	cout << "差分数组调用前缀和时候的值: ";
	for (int i = 0; i < N; i++)
	{
		if (i == 0) {
			cout << res[i] << ' ';
			continue;
		}
		else {
			res[i] += res[i - 1];
			cout << res[i] << ' ';
		}
	}
	cout << endl;
	return 0;
}