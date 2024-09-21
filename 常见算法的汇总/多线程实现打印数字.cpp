

#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

// 共享资源，使用时候需要上锁
static int num = 1;

// 生成一个全局锁
mutex mtx;
condition_variable m_cond_variable;
// 标记本轮是奇数还是偶数
bool odd_turn = true; // 奇数，代表当前应该是奇数取到资源

void printf_odd()
{
	unique_lock<mutex>lock(mtx);
	while (num <= 100)
	{
		// 检查是不是奇数线程取到了资源
		// 如果当前不应该是奇数线程操作，奇数线程需要先释放锁资源
		/*if (!odd_turn)
		{
			m_cond_variable.wait(lock);
		}*/
		while (!odd_turn)
		{
			m_cond_variable.wait(lock);
		}
		if (num > 100) break;
		cout << "奇数线程打印的数字为: " << num << endl;
		num++;
		odd_turn = false; // 交给偶数线程
		m_cond_variable.notify_one(); // 唤醒偶数线程
	}
}

// 偶数线程
void printf_even()
{
	unique_lock<mutex>lock(mtx);
	while (num <= 100)
	{
		// 检查是不是偶数线程取到了资源
		// 如果当前不应该是偶数线程操作，偶数线程需要先释放锁资源
		// 会有虚假唤醒
		/*if (odd_turn)
		{
			m_cond_variable.wait(lock);
		}*/

		while (odd_turn)
		{
			m_cond_variable.wait(lock);
		}
		if (num > 100) break;
		cout << "偶数线程打印的数字为: " << num << endl;
		num++;
		odd_turn = true; // 交给奇数线程
		m_cond_variable.notify_one(); // 唤醒奇数线程
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