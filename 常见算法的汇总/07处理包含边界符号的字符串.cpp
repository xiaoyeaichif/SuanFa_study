#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string input;
    cin >> input;  // ��ȡ��������

    // ȥ��������
    // ���ȼ�ȥ2
    input = input.substr(1, input.size() - 2);

    // ʹ�� stringstream ����
    istringstream iss(input);
    vector<int> numbers;
    string number;
    while (getline(iss, number, ',')) {
        numbers.push_back(stoi(number));  // ���ַ���ת��Ϊ�������洢�� vector ��
    }

    // ��������֤
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
