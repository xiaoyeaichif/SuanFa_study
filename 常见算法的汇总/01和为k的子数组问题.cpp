#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//ǰ׺�͵Ĵ���
int subarraySum(vector<int>& nums, int k) {
    //��ϣ��+ǰ׺��
    unordered_map<int, int>u_map;
    //��������
    //ǰ׺��Ϊ0�����Ѿ�����1����
    u_map[0] = 1;
    int Presum = 0;
    int N = nums.size();
    //ͳ�Ƹ���
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        Presum += nums[i];
        //���Ԫ�ش���ֱ�Ӽ�
        //��������ڼ�0
        count += max(0, u_map[Presum - k]);
        //û�ҵ�,�ѵ�ǰ��ǰ׺�ʹ��������
        u_map[Presum]++;
    }
    return count;
}

int main_k_01()
{
    /*
     ������������һ����������������,��һ��������������Ĵ�С,�ڶ������������Ϊk��������
               �ڶ��б�ʾ�������������ֵ

    ��������� �����������ĸ���
    ʾ����
        3 2
        1 1 1
        ��ʾ����������СΪ3,��Ϊk
        �ڶ��б�ʾ�����е�Ԫ��
    ���������2
    */
    int n, m;
    cin >> n >> m;
    //��������ĸ�ʽ
    vector<int>ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> ans[i];
    }
    cout << subarraySum(ans, m) << endl;
    return 0;
}