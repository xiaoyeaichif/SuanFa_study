

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;

static const int N = 1E5 + 10;

static vector<int>Input(N, 0);
vector<int>nums[N]; // �ڽӱ�

static void tpsort()
{
    queue<int>que;
    // ����Ƿ��л������У�Ҳ�����ܲ��������СΪn
    vector<int>ans;
    for (int i = 1; i <= n; i++)
    {
        if (Input[i] == 0)
        {
            que.push(i);
        }
    }
    // �������Ƿ�Ϊ�ռ���
    while (!que.empty())
    {
        int size = que.size();
        while (size--)
        {
            int node = que.front();
            que.pop();
            ans.push_back(node);
            for (int num : nums[node])
            {
                // ��ȼ�1
                Input[num]--;
                // �����Ϊ0�ĵ���������
                if (Input[num] == 0)
                {
                    que.push(num);
                }
            }
        }
    }
    if (ans.size() == n)
    {
        cout << "YES" << endl;
    }
    else {
        cout << ans.size() << endl;
    }
}


int main_tpsort03()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        nums[a].push_back(b);
        // ������ȵĴ�С
        Input[b]++;
    }
    // �������������
    tpsort();
    //
    return 0;
}



