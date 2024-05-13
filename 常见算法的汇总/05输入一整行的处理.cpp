#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main_input05(){
    string line;
    getline(cin, line);  // ��ȡһ������

    istringstream iss(line);
    vector<int> nums;
    int num;

    // ����������������ȡ���洢�� vector<int> nums ��
    //���Զ������ո�
    while (iss >> num) {
        nums.push_back(num);
    }

    // �� nums �е����ֽ�������
    sort(nums.begin(), nums.end());

    // ��������Ľ��
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i != nums.size() - 1) {
            cout << ' ';  // ������ּ�Ŀո����һ�����ֺ��治�ӿո�
        }
    }
    cout << endl;

    return 0;
}
