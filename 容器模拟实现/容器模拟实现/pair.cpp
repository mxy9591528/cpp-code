#include<iostream>
#include<string>
using namespace std;
int main()
{
	pair<string, int>p("Tom", 20);
	cout << "姓名:" << p.first << " 年龄" << p.second << endl;
	pair<string, int>q("Jerry", 20);
	cout << "姓名:" << q.first << " 年龄" << q.second << endl;
	return 0;
}