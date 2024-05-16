#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

static const int N = 1010;
static int Father[N], Count[N];
//���鼯�ĳ�ʼ��
static void build(int n)
{
    for (int i = 1; i <= n; i++)
    {
        Father[i] = i;
    }
}

//Find������ʵ��
static int Find(int x)
{
    if (Father[x] != x)
    {
        Father[x] = Find(Father[x]);//·��ѹ��
    }
    return Father[x];
}
//���Ϻ�����ʵ��
//�ж����������Ƿ���һ������,���������ϲ�
static void Union(int x, int y, int w)
{
    int root_x = Find(x);
    int root_y = Find(y);
    //ʼ���ø��ڵ����
    Count[root_y] += w;
    if (root_x != root_y)
    {
        //�������ƶ�
        //Ҳ���ǽ�x������y��,������Ҫ��x����Ϣ����y
        Count[root_y] += Count[root_x];
        Father[root_x] = root_y;
    }

}

//��������ʵ��
int main_bincha04()
{
    int n;
    //�������鼯
    cin >> n;
    build(n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x > 0)
            {
                Union(i, j, x);
            }
        }
    }
    vector<int>ans;//ͳ���������ƶȵĸ���
    for (int i = 1; i <= n; i++)
    {
        if (Find(i) == i) //�ҵ����ڵ��Ӧ��ֵ
        {
            ans.push_back(Count[i] / 2);
        }
    }
    sort(ans.begin(), ans.end(), greater<int>());
    for (int& x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << Count[i] << ' ';
    }
    return 0;

}
