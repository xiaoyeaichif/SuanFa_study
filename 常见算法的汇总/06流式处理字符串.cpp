#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;




int main() {
    //��ȡ�Զ��ŷָ���ַ���
    /*
    *  ���� str = "yejie,nihao,nizaina"
    *  ����Ҫ�������yejie nihao nizaina
    */
    string str;
    getline(cin, str);

    //��������ʹ���ַ���������ǰ������
    stringstream ss(str);
    vector<string>ans;
    //���ָ���ַ�������������
    string token;
    while (getline(ss, token, ','))
    {
        ans.push_back(token);// ��ÿ�����ŷָ����ֶδ洢�� vector ��
    }

    //����ַ���
    for (string s : ans)
    {
        cout << s << ' ';
    }
    cout << endl;
    
    return 0;
}

