


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 1010;
static vector<int>input_s(N, 0);//ͳ�����
static vector<int>g[N]; //ͳ�ƶ�Ӧ��Ԫ��

static int n;
void tpsort()
{
    queue<int>que;
    vector<int>ans;
    for (int i = 1; i <= n; i++)
    {
        if (input_s[i] == 0)
        {
            que.push(i);
        }
    }

    //�������Ƿ�Ϊ��
    int cnt = 0; // ͳ����С�Ĵ���
    while (!que.empty())
    {
        int size = que.size();
        while (size--)
        {
            int first = que.front();
            que.pop();
            ans.push_back(first);
            for (int& x : g[first])
            {
                input_s[x]--;
                if (input_s[x] == 0)
                {
                    que.push(x);
                }
            }
        }
        //ÿһ�����
        cnt++;
    }
    //���û������ô����ans�оͻ���n������
    int len = ans.size();
    if (len == n)
    {
        cout << cnt << endl;
    }
    else {
        cout << -1 << endl;
    }
}

#if 0
//��������ʵ��
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        while (a--)
        {
            int b;
            cin >> b;
            g[i].push_back(b);
            //��������顣���������ż��
            input_s[b]++;
        }
    }
    tpsort();
    return 0;
}
#endif

int main_tpsort01()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        while (a--)
        {
            int b;
            cin >> b;
            g[i].push_back(b);
            //��������顣���������ż��
            input_s[b]++;
        }
    }
    tpsort();
    return 0;
}