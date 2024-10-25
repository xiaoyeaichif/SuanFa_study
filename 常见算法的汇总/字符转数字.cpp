#include<iostream>
#include<vector>
#include<string>
using namespace std;

#include <csignal>
#include <cstdint>

#include<memory>




using u_short = unsigned short;

// ��16��������ת��Ϊ�ֽ���
vector<uint8_t> hexTobyte(const string& str1) {
    vector<uint8_t> bytes;
    for (size_t i = 0; i < str1.size(); i += 2) {
        // ÿ��ȡ�����ַ�
        string temp = str1.substr(i, 2);
        // ���ַ�ת��Ϊ�ֽڣ���ָ������Ϊ16
        uint8_t byte = static_cast<uint8_t>(stoi(temp, nullptr, 16));
        bytes.push_back(byte);
    }
    return bytes;
}

// ���ֽ����ж�ȡ�����ֽڣ���С��ģʽ����Ϊ u_short
u_short readtwo(const vector<uint8_t>& data, size_t offset) {
    // С�˴�������λ�ƶ�����8λ��
    return data[offset] | (data[offset + 1] << 8);
    // ��˴���
    // return (data[offset] << 8) | data[offset + 1];

}

// �����ֽ��������Э������
void getsolve(const vector<uint8_t>& data) {
    size_t i = 0;
    while (i + 4 <= data.size()) {  // ȷ��ʣ������4�ֽ����ڶ�ȡ�����ͳ����ֶ�
        // ��鳣���Ƿ�Ϊ 'SS'
        if (data[i] != 'S' || data[i + 1] != 'S') {
            i++;  // ���������ƥ�䣬�ƶ�����һ���ֽڼ������
            continue;
        }

        // ��ȡ��Ϣ����
        u_short len = readtwo(data, i + 2);

        // �������Э����Ƿ�����
        if (i + 4 + len > data.size()) {
            break;  // ���ݲ��������ȴ��´ζ�ȡ
        }

        // ��ȡЭ���
        u_short proto = readtwo(data, i + 4);

        // ������Ϣ��ĳ��ȣ���ȥЭ��ŵ�2���ֽڣ�
        size_t message_length = len - 2;

        // ��ȡ��Ϣ��
        string message(data.begin() + i + 6, data.begin() + i + 6 + message_length);

        // ���Э��ź���Ϣ��
        cout << proto << ' ' << message << endl;

        // �ƶ�������׼��������һ��Э��
        i += 4 + len;  // 4�ֽڣ������ͳ����ֶΣ�����len��Э��ź���Ϣ�壩
    }
}

int main_shenxinfu() {
    string str1;
    getline(cin, str1);  // �ӱ�׼�����ȡ16�����ַ���
    auto temp = hexTobyte(str1);  // ��16�����ַ���ת��Ϊ�ֽ���
    getsolve(temp);  // ���������Э������
    return 0;
}
