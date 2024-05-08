#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//前缀和的处理
int subarraySum(vector<int>& nums, int k) {
    //哈希表+前缀和
    unordered_map<int, int>u_map;
    //特殊情形
    //前缀和为0的数已经存在1次了
    u_map[0] = 1;
    int Presum = 0;
    int N = nums.size();
    //统计个数
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        Presum += nums[i];
        //如果元素存在直接加
        //如果不存在加0
        count += max(0, u_map[Presum - k]);
        //没找到,把当前的前缀和存进数组中
        u_map[Presum]++;
    }
    return count;
}

int main_k_01()
{
    /*
     输入描述：第一行输入两个个整数,第一个整数代表数组的大小,第二个整数代表和为k的子数组
               第二行表示输入输入数组的值

    输出描述： 输出满足题意的个数
    示例：
        3 2
        1 1 1
        表示输入的数组大小为3,和为k
        第二行表示数组中的元素
    输出描述：2
    */
    int n, m;
    cin >> n >> m;
    //输入数组的格式
    vector<int>ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> ans[i];
    }
    cout << subarraySum(ans, m) << endl;
    return 0;
}