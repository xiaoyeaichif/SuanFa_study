#include<iostream>
#include<string>

using namespace std;


/*
	check��������д
	check�����������뵱ǰ��ÿһ�ο����޸��ַ��ĳ���,��,�ַ���ȫ�����R��Ҫ�޸ĵĴ���
*/
//s��ֻ�����ַ�W��R���ַ���
int check(string& s, int k)
{
	//�߽�����,������޸ĵ��ַ�����Ϊk == 0���򷵻�һ���������Ϊ���,֤���ַ������Ա��޸�
	if (k == 0) return INT_MAX;
	int count = 0;//����ͳ�ƴ���
	int N = s.size();
	for (int i = 0; i < N; i++)
	{
		if (s[i] == 'W')//������Ҫ�޸���,����+1
		{
			count += 1;
			//ָ��Ӧ�ú��� i + k��λ��,�����������ѭ����Ҫ�ƶ�һ��ָ��,��������ֻ��Ҫ�ƶ�i+k-1
			i = i + k - 1;
		}

	}
	return count;
}

int main_erfen05()
{
	/*string str = "WRWWWR";
	int k = 5;
	cout << check(str, k) << endl;*/
	int n, m;
	cin >> n >> m;
	string str;
	cin >> str;
	//�������޸ĵĳ�����С�϶�Ϊ0,���Ϊ����ĳ���
	int l = 0;
	int r = str.size();
	//���ٴ�
	int ans = 0;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (check(str, mid) <= m)
		{
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout<<ans<<endl;
	return 0;

}