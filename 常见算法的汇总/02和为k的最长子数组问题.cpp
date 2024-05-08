#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//前缀和的处理
int subarraySum_mostlength(vector<int>& nums, int k) {
    //哈希表+前缀和
    unordered_map<int, int>u_map;
    //特殊情形
    //前缀和为0的数字,下标我们设置为-1
    u_map[0] = -1;
    int Presum = 0;
    int N = nums.size();
    //统计和为k的子数组的最长长度
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        Presum += nums[i];
        //要找Presum - k 这个累加和最早出现在哪里，也就是最先出现的下标
        if (u_map.find(Presum - k) != u_map.end())
        {
            count = max(count, i - u_map[Presum - k]);
        }
        //如果是新出现的前缀和就放进map中,不是的话就不管
        /*
            key   代表的是前缀和Presum
            value 代表的是最早出现和为Presum的下标
        */
        //一开始没找到这个元素,代表map中不存在这个数对应的下标,这个时候存进去
        //之后的都不管
        if (u_map.find(Presum) == u_map.end())
        {
            u_map[Presum] = i;
        }

    }
    return count;
}

int main_qian()
{
    /*
     输入描述：第一行输入两个个整数,第一个整数代表数组的大小,第二个整数代表和为k的子数组
               第二行表示输入输入数组的值

    输出描述： 输出满足题意的最大长度
    示例：
        3 2
        1 1 1
        表示输入的数组大小为3,和为2
        第二行表示数组中的元素
    输出描述：2(也就是和为k的最长子数组)
    */
    int n, m;
    cin >> n >> m;
    //输入数组的格式
    vector<int>ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> ans[i];
    }
    cout << subarraySum_mostlength(ans, m) << endl;
    return 0;
}