#include<iostream>
#include<string>
#include<vector>
using namespace std;


static const int N = 1E5 + 10;
static vector<int>g[N];  //��ӱ��vectorд�� �������ڵ�Ȩ��ͼ
static int f[N][3];    //f[i][0/1/2]��ʾ��iΪ���ڵ��������R��G��B������ɫ�Ľڵ�����
static int n;
static int total[3];  //��������R��G��B��������ɫ������
static string s;
static int res = 0;  //������
static vector<int> dfs(int u, int fa) //������uΪ���ڵ�������˻�������R,G,B�ĸ���
{
    //��鵱ǰ��u��Ϊ�����Ķ�Ӧ��R,G,B����
    //Ҫע�����u�Ǵ�1��ʼ��,���ַ������±��Ǵ�0��ʼ��,��Ҫ��1
    if (s[u - 1] == 'R') f[u][0] += 1;
    else if (s[u - 1] == 'G') f[u][1] += 1;
    else {
        f[u][2] += 1;
    }
    for (auto& x : g[u])
    {
        if (x == fa) continue;//���������ڵ�,ֱ������
        //�����ݹ�
        vector<int>son = dfs(x, u);
        for (int i = 0; i < 3; i++)
        {
            //��������ɫ���ӽڵ����ɫ��Ӧ���
            /*
                f[u][0]--->��Ӧson[0]�ĺ�ɫ
                f[u][1]--->��Ӧson[1]����ɫ
                f[u][2]--->��Ӧson[2]����ɫ
            */
            f[u][i] += son[i];
        }
    }
    /*
         �жϵ�ǰ�Ľ��u��ɵ������ܷ���������,
         Ҳ���Ƿָ��������,���Ҷ��Ƕ�ʵ�.
         Ҳ��������ɫ������ȥ��ǰ������������ά��Ϊһ���µ�
         �����
    */
    if (f[u][0] >= 1 && f[u][1] >= 1 && f[u][2] >= 1
        && total[0] - f[u][0] > 0
        && total[1] - f[u][1] > 0
        && total[2] - f[u][2] > 0)
        res += 1;
    //���ؽ��uΪ���ڵ��ʱ��������ɫ
    return { f[u][0],f[u][1],f[u][2] };
}

int main_dfs06() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int a;//��������±�i��Ӧ
        cin >> a;
        g[a].push_back(i);
        g[i].push_back(a);
    }
    cin >> s;//�����ַ�����ɫ
    //ͳ���ַ�����������ɫ�ĸ���
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R')total[0]++;
        else if (s[i] == 'B')total[1]++;
        else total[2]++;
    }
    dfs(1, 0);
    cout << res << endl;
    return 0;
}