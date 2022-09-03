#include<iostream>
#include<set>
using namespace std;
void printSet(set<int>&s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
		cout << *it << " ";
	cout << endl;
}
void test01()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	printSet(s1);
	set<int>s2(s1);
	printSet(s2);
	set<int>s3;
	s3 = s2;
	printSet(s3);
}
void test02()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	printSet(s1);
	if (s1.empty())
		cout << "s1为空" << endl;
	else
		cout << "s1不为空,元素个数为:" <<s1.size()<< endl;
	set<int>s2;
	s2.insert(1);
	s2.insert(3);
	s2.insert(5);
	s2.insert(7);
	cout << "交换前" << endl;
	printSet(s1);
	printSet(s2);
	cout << "交换后" << endl;
	s1.swap(s2);
	printSet(s1);
	printSet(s2);
}
void test03()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	printSet(s1); 
	s1.erase(s1.begin());
	printSet(s1);
	s1.erase(30);
	printSet(s1);
	s1.clear();
	printSet(s1);
}
void test04()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	//无效
	s1.insert(30);
	s1.insert(30);
	auto pos=s1.find(30);
	if (pos != s1.end())
		cout << "找到了" << *pos << endl;
	else
		cout << "没找到" << endl;
	int num = s1.count(30);
	cout << "num=" << num << endl;
}
void test05()
{
	set<int>s;
	pair<set<int>::iterator, bool>ret = s.insert(10);
	if (ret.second)
		cout << "第一次插入成功" << endl;
	else
		cout << "第一次插入失败" << endl;
	ret = s.insert(10);
	if (ret.second)
		cout << "第二次插入成功" << endl;
	else
		cout << "第二次插入失败" << endl;
	multiset<int>ms;
	ms.insert(10);
	ms.insert(10);
	ms.insert(10);
	for (auto it : ms)
		cout << it << " ";
	cout << endl;
}
class cmp
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test06()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(50);
	s1.insert(40);
	s1.insert(20);
	printSet(s1);
	set<int,cmp>s2;
	s2.insert(10);
	s2.insert(30);
	s2.insert(50);
	s2.insert(40);
	s2.insert(20);
	for (set<int, cmp>::iterator it = s2.begin(); it != s2.end(); it++)
		cout << *it << " ";
	cout << endl;
}
#include<string>
class Person
{
public:
	Person(string name, int age)
	{
		this->m_age = age;
		this->m_name = name;
	}
	string m_name;
	int m_age;
};
class Compare
{
public:
	bool operator()(const Person&p1, const Person&p2)
	{
		return p1.m_age > p2.m_age;
	}
};
void test07()
{
	set<Person,Compare>s;
	Person p[5] = 
	{
	{"关羽",28},
	{"张飞",25},
	{"赵云",24},
	{"马超",23},
	{"黄忠",30}
	};
	for (int i = 0; i <5; i++)
		s.insert(p[i]);
	for (set<Person,Compare>::iterator it=s.begin();it!=s.end();it++)
		cout << "姓名:" << it->m_name << "年龄:" << it->m_age << endl;

}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
}
