

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

static const int N = 30;
static vector<int>Input_(N, 0); // ��ʾ���
static vector<int>g[N];
static int nums[N][N];
static vector<int>value(N, 0);

static int n;

// ���������Ӧ��
static void tpsort()
{
    queue<int>que;
    for (int i = 1; i <= n; i++)
    {
        if (Input_[i] == 0)
        {
            que.push(i);
        }
    }
    vector<int>ans; // ��¼���е�Ԫ��
    int cnt = 0; // ��¼������Ҫ����С�ڴ�
    while (!que.empty())
    {
        int size = que.size();
        int res = 0;
        while (size--)
        {
            int node = que.front();
            que.pop();
            ans.push_back(node);
            res += value[node]; // ����ÿһ���Ӧ��ֵ
            for (int& num : g[node])
            {
                Input_[num]--;
                if (Input_[num] == 0)
                {
                    que.push(num);
                }
            }
        }
        cnt = max(cnt, res);
    }
    int size_ = ans.size();
    if (size_ == n)
    {
        cout << cnt << endl;
    }
    else {
        cout << -1 << endl;
    }
}


// �������߼�
int main_tpsort02()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> value[i];
    }
    // �����ڽӾ���
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) // ѭ������
        {
            cin >> nums[i][j];
            if (nums[i][j] != 0)
            {
                g[j].push_back(i);
                Input_[i]++; // ��ȵ���д
            }
        }
    }
    tpsort();
    return 0;
}

