#include<iostream>
#include<vector>

using namespace  std;

void chafen_add(vector<int>& nums, int left, int right, int k)
{
	nums[left] += k;
	nums[right + 1] += -k;
}



int main_chafen()
{
	vector<int>ans = { 1,3,2,5,6,4 };
	/*
	   ��Ҫʵ���� 2 -> 4 ���嶼����2, Ȼ��3->5 �����϶�����-3
	*/
	//��������һ������, ����Ĵ�С��ԭ�ȸ����������1
	int N = ans.size();
	//�������ǽ��в��ʱ,Ҫ����R+1����Ԫ��, ���Զ࿪��һ���ռ�,��ֹ����Խ��
	vector<int>res(N + 1, 0);
	res[0] = ans[0];
	//�����������
	cout << "�����������: ";
	cout << res[0] << ' ';
	for (int i = 1; i < N; i++)
	{
		res[i] = ans[i] - ans[i - 1];
		cout << res[i] << ' ';
	}
	cout << res[N] << ' ';
	cout << endl;

	int L = 2, R = 5, k = 2;
	//�������ĵ���
	chafen_add(res, L, R, k);
	//�������δ����ǰ׺��ʱ���ֵ
	cout << "�������δ����ǰ׺��ʱ���ֵ: ";
	for (int i = 0; i < N + 1; i++)
	{
		cout << res[i] << ' ';
	}
	cout << endl;
	//����������ǰ׺�͵�ֵ
	//����ֻ��Ҫ0->N-1�±��ֵ,����N����±��ֵ���ǿ��Բ���
	cout << "����������ǰ׺��ʱ���ֵ: ";
	for (int i = 0; i < N; i++)
	{
		if (i == 0) {
			cout << res[i] << ' ';
			continue;
		}
		else {
			res[i] += res[i - 1];
			cout << res[i] << ' ';
		}
	}
	cout << endl;
	return 0;
}