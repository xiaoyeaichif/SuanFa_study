#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//ǰ׺�͵Ĵ���
int subarraySum_mostlength(vector<int>& nums, int k) {
    //��ϣ��+ǰ׺��
    unordered_map<int, int>u_map;
    //��������
    //ǰ׺��Ϊ0������,�±���������Ϊ-1
    u_map[0] = -1;
    int Presum = 0;
    int N = nums.size();
    //ͳ�ƺ�Ϊk��������������
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        Presum += nums[i];
        //Ҫ��Presum - k ����ۼӺ�������������Ҳ�������ȳ��ֵ��±�
        if (u_map.find(Presum - k) != u_map.end())
        {
            count = max(count, i - u_map[Presum - k]);
        }
        //������³��ֵ�ǰ׺�;ͷŽ�map��,���ǵĻ��Ͳ���
        /*
            key   �������ǰ׺��Presum
            value �������������ֺ�ΪPresum���±�
        */
        //һ��ʼû�ҵ����Ԫ��,����map�в������������Ӧ���±�,���ʱ����ȥ
        //֮��Ķ�����
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
     ������������һ����������������,��һ��������������Ĵ�С,�ڶ������������Ϊk��������
               �ڶ��б�ʾ�������������ֵ

    ��������� ��������������󳤶�
    ʾ����
        3 2
        1 1 1
        ��ʾ����������СΪ3,��Ϊ2
        �ڶ��б�ʾ�����е�Ԫ��
    ���������2(Ҳ���Ǻ�Ϊk���������)
    */
    int n, m;
    cin >> n >> m;
    //��������ĸ�ʽ
    vector<int>ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> ans[i];
    }
    cout << subarraySum_mostlength(ans, m) << endl;
    return 0;
}