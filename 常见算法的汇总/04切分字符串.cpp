#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<sstream>

using namespace std;
/*
	check����������ֵΪ�ַ���,�Լ�Ȩֵ
	����Ҫ���صĵ����ڸ�Ȩֵ����,��������Ӵ��ĸ���
*/
int check(string str, int target)
{
	//ͳ�Ƴ���
	int len = 0;
	unordered_set<char>u_set;
	int size = str.size();
	//ͳ�Ƹ���
	int ans = 0;
	for (int i = 0; i < str.size(); i++)
	{
		//����ϣ�����Ԫ��
		u_set.insert(str[i]);
		len++;
		//�ҵ���һ��Ȩֵ����target���ַ���
		//���¸���,����Ҫע���±�i����Ҫ����
		if (len * u_set.size() > target)
		{
			ans++;
			//������Ҫ���¼���
			len = 0;
			//��չ�ϣ��
			u_set.clear();
			//�±����һ��,��Ϊ��ǰ��i����һ���Ӵ�����ʼλ��
			i -= 1;
		}
	}
	//������չ�ϣ���л�����Ԫ��ʱ,֤����ʱ����һ���Ӵ�δͳ��
	if (!u_set.empty()) ans++;
	return ans;
}

int main_erfen04()
{
	string str;
	cin >> str;
	int k;
	cin >> k;
	//cout << check(str, k) << endl;
	//���ֵĴ���
	int l = 1;
	int	r = 1e9;
	//��¼��
	int ans = 0;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (check(str, mid) <= k)
		{
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ans << endl;
	return 0;
}