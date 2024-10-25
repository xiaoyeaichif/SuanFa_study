//#include <iostream>
//#include <map>
//#include <set>
//#include <vector>
//using namespace std;
//
//// 分割区间的函数
//void split(map<int, int>& intervals, int pos) {
//    auto it = intervals.upper_bound(pos);
//    if (it == intervals.begin())
//        return;
//    --it;
//    if (it->first == pos)
//        return;
//    int color = it->second;
//    intervals[pos] = color;
//}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    vector<int> x(m);
//    for (int i = 0; i < m; ++i)
//        cin >> x[i];
//
//    map<int, int> intervals;
//    intervals[1] = 0; // 初始整个画布为0号颜色
//
//    vector<int> ans;
//
//    for (int i = 0; i < m; ++i) {
//        int xi = x[i];
//        int color = i + 1; // 颜色编号从1开始
//
//        // 分割区间，确保在x_i + 1处有分割
//        if (xi < n)
//            split(intervals, xi + 1);
//
//        // 分割区间，确保在1处有分割
//        split(intervals, 1);
//
//        // 删除被覆盖的区间 [1, x_i]
//        auto it_start = intervals.find(1);
//        auto it_end = (xi < n) ? intervals.find(xi + 1) : intervals.end();
//        intervals.erase(it_start, it_end);
//
//        // 插入新的染色区间
//        intervals[1] = color;
//
//        // 收集当前存在的颜色种类
//        set<int> colors;
//        for (auto& kv : intervals)
//            colors.insert(kv.second);
//
//        ans.push_back(colors.size());
//    }
//
//    // 输出结果
//    for (int i = 0; i < m; ++i) {
//        cout << ans[i];
//        if (i != m - 1)
//            cout << " ";
//    }
//    cout << endl;
//
//    return 0;
//}


#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <sstream>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    // 边界条件
    if (n == 1) return nums[0];
    // 最少有两个元素
    // qian_代表的是以nums[i]为结尾能获得的最大值
    // hou_代表以nums[i]为结尾的能获取的最小值
    vector<int>qian_(n, 0), hou_(n, 0);
    qian_[0] = nums[0], hou_[0] = nums[0];
    // 遍历
    // 当前的最大值就是第一个元素
    int ans = nums[0];
    for (int i = 1; i < n; i++)
    {
        // 如果当前的nums[i]小于0
        // 交换最大值与最小值的位置
        if (nums[i] < 0)
        {
            int temp = qian_[i - 1];
            qian_[i - 1] = hou_[i - 1];
            hou_[i - 1] = temp;
        }
        // 记录当前以nums[i]为结尾的最大值和最小值
        qian_[i] = max(qian_[i - 1] * nums[i], nums[i]);
        hou_[i] = min(hou_[i - 1] * nums[i], nums[i]);
        ans = max(ans, qian_[i]);
    }
    // 输出各个元素的位置
    for (int i = 0; i < n; i++)
    {
        cout << qian_[i] << " ";
    }
    cout << endl;
    // 输出各个元素的位置
    for (int i = 0; i < n; i++)
    {
        cout << hou_[i] << " ";
    }
    cout << endl;
    return ans;
}
// 如果数组当中没有负数，数组本身的乘积就是最大值
// 有负数的存在，在计算最大值和最小值时需要注意
// 一旦碰到负数，当前的最大值 * 负数会变小
// 当前的最小值 * 负数会变大
// 也就是说，一旦碰到负数，最大值和最小值交换位置即可

int jump(vector<int>& nums) {
    int ans = 0;
    // 当前能到达的最大距离
    int cur_right = 0;
    // 下一个最大距离（区间内能到达的最大距离）
    int next_right = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        next_right = max(next_right, i + nums[i]);
        if (cur_right == i)
        {
            ans++;
            // 当前的范围更新为
            cur_right = next_right;
            if (ans >= n - 1)
            {
                break;
            }
        }
    }
    return ans;
}


int main_baidu() {

    vector<int>nums = { 2,3,1,1,4 };
        
    cout << jump(nums) << endl;
    return 0;
}

