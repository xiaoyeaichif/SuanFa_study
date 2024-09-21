

#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

// ������Դ��ʹ��ʱ����Ҫ����
static int num = 1;

// ����һ��ȫ����
mutex mtx;
condition_variable m_cond_variable;
// ��Ǳ�������������ż��
bool odd_turn = true; // ����������ǰӦ��������ȡ����Դ

void printf_odd()
{
	unique_lock<mutex>lock(mtx);
	while (num <= 100)
	{
		// ����ǲ��������߳�ȡ������Դ
		// �����ǰ��Ӧ���������̲߳����������߳���Ҫ���ͷ�����Դ
		/*if (!odd_turn)
		{
			m_cond_variable.wait(lock);
		}*/
		while (!odd_turn)
		{
			m_cond_variable.wait(lock);
		}
		if (num > 100) break;
		cout << "�����̴߳�ӡ������Ϊ: " << num << endl;
		num++;
		odd_turn = false; // ����ż���߳�
		m_cond_variable.notify_one(); // ����ż���߳�
	}
}

// ż���߳�
void printf_even()
{
	unique_lock<mutex>lock(mtx);
	while (num <= 100)
	{
		// ����ǲ���ż���߳�ȡ������Դ
		// �����ǰ��Ӧ����ż���̲߳�����ż���߳���Ҫ���ͷ�����Դ
		// ������ٻ���
		/*if (odd_turn)
		{
			m_cond_variable.wait(lock);
		}*/

		while (odd_turn)
		{
			m_cond_variable.wait(lock);
		}
		if (num > 100) break;
		cout << "ż���̴߳�ӡ������Ϊ: " << num << endl;
		num++;
		odd_turn = true; // ���������߳�
		m_cond_variable.notify_one(); // ���������߳�
	}
}


int main_thread1()
{
	thread t1(printf_odd);
	thread t2(printf_even);
	t1.join();
	t2.join();
	return 0;
}