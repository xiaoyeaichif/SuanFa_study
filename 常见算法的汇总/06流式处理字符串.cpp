#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;




int main_input06() {
    //��ȡ�Զ��ŷָ���ַ���
    /*
    *  ���� str = "yejie,nihao,nizaina"
    *  ����Ҫ�������yejie nihao nizaina
    */
    string str;
    getline(cin, str);

    //��������ʹ���ַ���������ǰ������
    istringstream ss(str);//����ʹ��    stringstream ss(str)Ҳ�ǿ��Ե�
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

