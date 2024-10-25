//#include <iostream>
//#include <map>
//#include <set>
//#include <vector>
//using namespace std;
//
//// �ָ�����ĺ���
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
//    intervals[1] = 0; // ��ʼ��������Ϊ0����ɫ
//
//    vector<int> ans;
//
//    for (int i = 0; i < m; ++i) {
//        int xi = x[i];
//        int color = i + 1; // ��ɫ��Ŵ�1��ʼ
//
//        // �ָ����䣬ȷ����x_i + 1���зָ�
//        if (xi < n)
//            split(intervals, xi + 1);
//
//        // �ָ����䣬ȷ����1���зָ�
//        split(intervals, 1);
//
//        // ɾ�������ǵ����� [1, x_i]
//        auto it_start = intervals.find(1);
//        auto it_end = (xi < n) ? intervals.find(xi + 1) : intervals.end();
//        intervals.erase(it_start, it_end);
//
//        // �����µ�Ⱦɫ����
//        intervals[1] = color;
//
//        // �ռ���ǰ���ڵ���ɫ����
//        set<int> colors;
//        for (auto& kv : intervals)
//            colors.insert(kv.second);
//
//        ans.push_back(colors.size());
//    }
//
//    // ������
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
    // �߽�����
    if (n == 1) return nums[0];
    // ����������Ԫ��
    // qian_���������nums[i]Ϊ��β�ܻ�õ����ֵ
    // hou_������nums[i]Ϊ��β���ܻ�ȡ����Сֵ
    vector<int>qian_(n, 0), hou_(n, 0);
    qian_[0] = nums[0], hou_[0] = nums[0];
    // ����
    // ��ǰ�����ֵ���ǵ�һ��Ԫ��
    int ans = nums[0];
    for (int i = 1; i < n; i++)
    {
        // �����ǰ��nums[i]С��0
        // �������ֵ����Сֵ��λ��
        if (nums[i] < 0)
        {
            int temp = qian_[i - 1];
            qian_[i - 1] = hou_[i - 1];
            hou_[i - 1] = temp;
        }
        // ��¼��ǰ��nums[i]Ϊ��β�����ֵ����Сֵ
        qian_[i] = max(qian_[i - 1] * nums[i], nums[i]);
        hou_[i] = min(hou_[i - 1] * nums[i], nums[i]);
        ans = max(ans, qian_[i]);
    }
    // �������Ԫ�ص�λ��
    for (int i = 0; i < n; i++)
    {
        cout << qian_[i] << " ";
    }
    cout << endl;
    // �������Ԫ�ص�λ��
    for (int i = 0; i < n; i++)
    {
        cout << hou_[i] << " ";
    }
    cout << endl;
    return ans;
}
// ������鵱��û�и��������鱾��ĳ˻��������ֵ
// �и����Ĵ��ڣ��ڼ������ֵ����Сֵʱ��Ҫע��
// һ��������������ǰ�����ֵ * �������С
// ��ǰ����Сֵ * ��������
// Ҳ����˵��һ���������������ֵ����Сֵ����λ�ü���

int jump(vector<int>& nums) {
    int ans = 0;
    // ��ǰ�ܵ����������
    int cur_right = 0;
    // ��һ�������루�������ܵ���������룩
    int next_right = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        next_right = max(next_right, i + nums[i]);
        if (cur_right == i)
        {
            ans++;
            // ��ǰ�ķ�Χ����Ϊ
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

