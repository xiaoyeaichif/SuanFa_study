#include<iostream>
#include<vector>
using namespace std;

/*
/*
�����ʽ��
��һ�а�����������n��m��
�ڶ��а���n����������ʾ�������С�
������m�У�ÿ�а�����������l ��r����ʾһ��ѯ�ʵ����䷶Χ��

�����ʽ
��m�У�ÿ�����һ��ѯ�ʵĽ����
*/
//ʹ��ȫ�ֱ�����д, Ч�ʸ���
//�Ȱ����鿪�ٺ�,Ȼ�󿪱ٵ������һ��

// �����Ƿ�ֹ�����ļ��ķ���
//const int N = 1e+5 + 10;
//vector<int>nums(N, 0);
//vector<int>sum(N, 0);
////�����������
//int n, m;
//int main01()
//{
//	cin >> n >> m;
//	//����������
//	for (int i = 0; i <n; i++)
//	{
//		cin >> nums[i];
//	}
//	//Ҫ�ֶ���ʼ��ǰ׺�͵ĵ�һ��Ԫ��
//	//��ʼ��ǰ׺������
//	sum[0] = nums[0];
//	for (int i = 1; i <n; i++)
//	{
//		sum[i] = sum[i - 1] + nums[i];
//	}
//	//������֤������Ƿ���ϵ�
//	/*for (int num : nums) cout << num << ' ';
//	cout << endl;
//	for (int num : sum) cout << num << ' ';
//	cout << endl;*/
//	//���������������m������
//	while (m--)
//	{
//		//Ҫ��ȡ����[l....r]֮������ֺ�
//		int l, r;
//		cin >> l >> r;
//		cout << sum[r] - sum[l - 1] << endl;
//	}
//	return 0;
//}
