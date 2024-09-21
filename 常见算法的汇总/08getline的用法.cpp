#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

int main_inout08()
{
	
	/*
	* 
	*   string line;
		vector<long long>nums;
		while (getline(iss, line,','))
		{
			// ªÚ’ﬂstoull
			nums.push_back(stoll(line));
			cout << line<< endl;
		}
	* 
	*/
	string str;
	getline(cin, str);
	stringstream iss(str);
	unsigned long long num;
	while (iss >> num)
	{
		cout << num << endl;
	}
	return 0;
}