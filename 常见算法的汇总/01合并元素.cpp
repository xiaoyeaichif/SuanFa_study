#include<iostream>
#include<vector>
using namespace std;

static const int N = 100000 + 5;
//�������Ϊ��������

/*
   0->i-1
   i->i+1
   i+2->n-1
*/
//��׺��Сֵ
vector<int>hou_zui_min(N, INT_MAX);
//��׺���ֵ
vector<int>hou_zui_max(N, 0);
//
vector<int>w(N, 0);
int main_hebing01()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> w[i];
    //�Ͳ��ô���i = 0 ���Ԫ��,ֱ���������ƶ�һ��λ��
    // for(int i = n;i >= 1;i--)
    // {
    //     hou_zui_max[i] = max(w[i],hou_zui_max[i+1]);
    //     hou_zui_min[i] = min(w[i],hou_zui_min[i+1]);
    // }
    hou_zui_max[n] = w[n];
    hou_zui_min[n] = w[n];
    for (int i = n - 1; i >= 1; i--) {
        hou_zui_max[i] = max(w[i], hou_zui_max[i + 1]);
        hou_zui_min[i] = min(w[i], hou_zui_min[i + 1]);
    }

    //ǰ׺�����ֵ����Сֵ
    int pre_max = 0, pre_min = INT_MAX;
    int ans = INT_MAX;

    //������ǰ��Ԫ��
    //�ֱ�ö��i��i+1������������������n-1
    for (int i = 1; i < n; i++)
    {
        int x = w[i] + w[i + 1];
        //��������±����1,���Ը���ǰ׺���ֵ����Сֵ
        if (i > 1)
        {
            pre_max = max(pre_max, w[i - 1]);
            pre_min = min(pre_min, w[i - 1]);
        }
        //������������ֵ����Сֵ
        //����Ԫ��ȥ��ֵҪע��Ӵ�����
        //��������ֵ
        int max_val = max({ pre_max,x,hou_zui_max[i + 2] });
        //�������Сֵ
        int min_val = min({ pre_min,x,hou_zui_min[i + 2] });
        ans = min(ans, max_val - min_val);
    }
    cout << ans << endl;
    return 0;
}

