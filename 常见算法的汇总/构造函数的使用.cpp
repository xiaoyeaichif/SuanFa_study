#include <iostream>
#include <utility> // For std::move
using namespace std;

class Myclass {
public:
    Myclass(int a = 10)
    {
        cout << "Myclass Ĭ�Ϲ��캯���ĵ���" << endl;
    }
    // �������캯��
    Myclass(const Myclass& temp)
    {
        cout << "Myclass& �������캯���ĵ���" << endl;
    }
    // �ƶ����캯��
    Myclass(Myclass&& temp)
    {
        cout << "Myclass&& �ƶ����캯���ĵ���" << endl;
    }
    // ��ֵ���캯���ĵ���
    Myclass& operator=(const Myclass& temp)
    {
        cout << "operator= ��ֵ�����ĵ���" << endl;
        return *this;
    }
    // �ƶ���ֵ������
    Myclass& operator=(Myclass&& temp)
    {
        cout << "operator= �ƶ���ֵ�����ĵ���" << endl;
        return *this;
    }
    ~Myclass()
    {
        cout << "���������ĵ���" << endl;
    }
private:
    int num;
};

// 
Myclass func(Myclass &temp)
{
    // ����num����������ͻ���ʧ������ʹ����ֵ���궨�ö���
    Myclass num = std::move(temp); // ʹ�� std::move
    return num;
}


/*

    Myclass Ĭ�Ϲ��캯���ĵ���
    Myclass& �������캯���ĵ���
    operator= ��ֵ�����ĵ��� 
    // ���������Ż�����������
    // �����������������num����ʱ����
            **Myclass&& �ƶ����캯���ĵ���
            **���������ĵ���
    Myclass&& �ƶ����캯���ĵ���
    ���������ĵ���  // temp3
    ���������ĵ���  // temp2
    ���������ĵ���  // temp1
*/

int main_gouz01()
{
    Myclass temp1;
    Myclass temp2 = temp1;
    temp2 = temp1;
    /*
        func��������
            ����ʹ�ÿ������캯���������
            ---��Ȼ��ʹ���ƶ����캯������ʼ��num����
            ---�����ʹ���ƶ����캯���ٴι���num����ʱ����
    */
    Myclass temp3 = func(temp2);
    return 0;
}

