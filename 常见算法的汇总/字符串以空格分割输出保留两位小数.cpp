


// Ҫ���ľ�����ȡÿ�����ʵĳ���

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

int main_str01()
{
    string str;
    getline(cin, str);
    // �����Ӱ��ո�ָ�
    istringstream iss(str);
    string line;
    vector<string>ans;
    // �Կո����ַ���
    while (getline(iss, line, ' '))
    {
        ans.push_back(line);
        // 
        cout << line << ' ';
    }
    int size = ans.size();
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += ans[i].size();
    }
    // printf("%.2f\n", static_cast<double>(sum) / size);
    cout << fixed << setprecision(2) << static_cast<double>(sum) / size << endl;
    return 0;
}