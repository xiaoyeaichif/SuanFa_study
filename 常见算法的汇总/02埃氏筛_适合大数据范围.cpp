#include<iostream>
#include<vector>

using namespace std;

static const int N = 5E6 + 10;
static vector<int>prime(N);//��¼���е�������ŵ�λ��,�������ͳ�Ƹ���,���������Բ�Ҫ
static vector<bool>used(N);//������¼��ǰ�������ǲ�������,true:��ʾ��������,false��ʾ������
static int n;
static int cnt = 0;//��¼�������ֵĸ���
void get_prime(int n)
{
	if (n <= 1) return;
	for (int i = 2; i <= n; i++)
	{
		if (used[i]) continue;
		prime[cnt++] = i;//���������������
		//��������Ӧ�ı���ɾ������Ϊ���ǲ�����Ϊ����
		//������2,����������Ϊ4��6��8....�ȵ�,��������Ϊ����
		for (int j = i + i; j <= n; j += i)
		{
			used[j] = true;//��ʾ��ǰ������������
		}
	}
}

static bool isPrime1(int num)
{
	//1:num <= 1 �϶���������
	if (num <= 1)
	{
		return false;
	}
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0) return false;//����Ͳ�������
	}
	//�����Ϊ����
	return true;
}


int main_aishishai02()
{
	cin >> n;
	get_prime(n);
	cout <<"����ɸ������:" << cnt << endl;
	for (int i = 0; i < cnt;i++)
	{
		cout << prime[i] << ' ';
	}
	return 0;
}