#include<iostream>
using namespace std;

int main_1201()
{
	int a = 1, b = 2, c = 3, d = 4, m = 2, n = 2;
	cout << (m = a > b) && (n = c > d) ;
	cout << n << endl;
	return 0;
}