


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 1010;
static vector<int>input_s(N, 0);//统计入度
static vector<int>g[N]; //统计对应的元素

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

    //检查队列是否为空
    int cnt = 0; // 统计最小的次数
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
        //每一层结束
        cnt++;
    }
    //如果没环，那么数组ans中就会有n个数字
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
//主函数的实现
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
            //反过来检查。而不是正着检查
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
            //反过来检查。而不是正着检查
            input_s[b]++;
        }
    }
    tpsort();
    return 0;
}