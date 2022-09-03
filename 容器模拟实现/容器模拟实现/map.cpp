#include<iostream>
#include<map>
using namespace std;
void printMap(map<int, int>&m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		cout << "key=" << it->first << ",value=" << it->second << endl;
	cout << endl;
}
void test01()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(3, 20));
	m1.insert(pair<int, int>(2, 30));
	m1.insert(pair<int, int>(4, 40));
	printMap(m1);
	map<int, int>m2(m1);
	printMap(m2);
	map<int, int>m3;
	m3 = m2;
	printMap(m3);
}
void test02()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	if (m1.empty())
		cout << "m为空" << endl;
	else
	{
		cout << "m不为空" << endl;
		cout << "m的大小为:" << m1.size() << endl;
	}
	map<int, int>m2;
	m2.insert(pair<int, int>(4, 37));
	m2.insert(pair<int, int>(5, 73));
	m2.insert(pair<int, int>(6, 373));
	cout <<"交换前:" << endl;
	printMap(m1);
	printMap(m2);
	m1.swap(m2);
	cout << "交换后:" << endl;
	printMap(m1);
	printMap(m2);
}
void test03()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;
	cout << m[5] << endl;
	printMap(m);
	m.erase(m.begin());
	printMap(m);
	m.erase(3);
	printMap(m);
	m.clear();
}
void test04()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(3, 40));
	if (m1.find(3) != m1.end())
		cout << "找到了 key=" << m1.find(3)->first << ",value=" << m1.find(3)->second << endl;
	else
		cout << "没找到" << endl;
	int num = m1.count(3);
	cout << "num=" << num << endl;
}
class cmp
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test05()
{
	map<int, int,cmp>m;
	m.insert (make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));
	for(map<int,int,cmp>::iterator it=m.begin();it!=m.end();it++)
		cout << "key=" << it->first << ",value=" << it->second << endl;
}
#include<vector>
#include<string>
#include<time.h>
#define 策划 0
#define 美术 1
#define 研发 2
class worker
{
public:
	string m_name;
	int m_salary;
};
void creatWorker(vector<worker>&v)
{
	string nameeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		worker p;
		p.m_name = "员工";
		p.m_name += nameeed[i];
		p.m_salary = rand() % 10000 + 10000;
		v.push_back(p);
	}
}
void setgroup(vector<worker>&v, multimap<int, worker>&m)
{
	for (vector<worker>::iterator i = v.begin(); i != v.end(); i++)
	{
		int rid = rand() % 3;
		m.insert(make_pair(rid, *i));
	}
}
void showworker(multimap<int, worker>&m)
{
	cout << "策划部门:" << endl;
	multimap<int,worker>::iterator pos=m.find(策划);
	int count = m.count(策划);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
		cout << "姓名:" << pos->second.m_name << " 工资:" << pos->second.m_salary << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "美术部门:" << endl;
	pos =m.find(美术);
	count = m.count(美术);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
		cout << "姓名:" << pos->second.m_name << " 工资:" << pos->second.m_salary << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "研发部门:" << endl;
	pos = m.find(研发);
	count = m.count(研发);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
		cout << "姓名:" << pos->second.m_name << " 工资:" << pos->second.m_salary << endl;
}
void test06()
{
	srand((unsigned int)time(NULL));
	vector<worker>vp;
	creatWorker(vp);
	multimap<int, worker>mp;
	setgroup(vp,mp);
	showworker(mp);
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
}