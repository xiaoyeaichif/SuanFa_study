#
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    unordered_map<int, int>u_map;
    int size = difficulty.size();
    for (int i = 0; i < size; i++)
    {
        if (u_map.find(difficulty[i]) == u_map.end())
        {
            u_map[difficulty[i]] = profit[i];
        }
        else {
            //如果当前的值已经存在,但是最大利润需要变化
            if (u_map[difficulty[i]] < profit[i])
            {
                //更新同一个值对应的利润最大值
                u_map[difficulty[i]] = profit[i];
            }
        }
        
    }
    //对difficulty排序
    sort(difficulty.begin(), difficulty.end());
    sort(worker.begin(), worker.end());
    int max_profit = 0, j = 0, ans = 0;
    //遍历工人数组
    for (int w : worker)
    {
        while (j < size && difficulty[j] <= w)
        {
            max_profit = max(max_profit, u_map[difficulty[j]]);
            j++;
        }
        ans += max_profit;
    }
    return ans;
}

int main_826()
{
    vector<int>diffculty = { 2,4,6,18,18 };
    vector<int>profit = { 10, 20, 30, 54, 19 };
    vector<int>worker = { 4, 5, 6, 7, 19 };
    cout << maxProfitAssignment(diffculty, profit, worker) << endl;
    return 0;
}