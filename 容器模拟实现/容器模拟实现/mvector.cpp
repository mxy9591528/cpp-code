#include"mvector.hpp"
using namespace mxyvector;
void printMvector(mvector<int>&v)
{
	for (auto i : v)
		cout << i << " ";
	cout << endl;
}
void test01()
{
	mvector<int>v1;//默认无参构造
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	printMvector(v1);
	//通过区间构造
	mvector<int>v2(v1.begin(), v1.end());
	printMvector(v2);
	//n个elmn构造
	mvector<int>v3(7, 3);
	printMvector(v3);
	//拷贝构造
	mvector<int>v4(v3);
	printMvector(v4);
}
void test02()
{
	mvector<int>v1;
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	printMvector(v1);
	mvector<int>v2;
	v2 = v1;
	printMvector(v2);
	mvector<int>v3;
	v3.assign(v1.begin(), v1.end());
	printMvector(v3);
	mvector<int>v4;
	v4.assign(7, 3);
	printMvector(v4);
}
void test03()
{
	mvector<int>v1;
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	printMvector(v1);
	if (v1.empty())
		cout << "v1为空" << endl;
	else
	{
		cout << "v1不为空" << endl;
		cout << "v1的容量为:" << v1.capacity() << endl;
		cout << "v1的大小为:" << v1.size() << endl;
	}
	v1.resize(15,3);//指定空间大小
	printMvector(v1);
	v1.resize(5);
	printMvector(v1);
}
void test04()
{
	mvector<int>v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printMvector(v1);
	v1.pop_back();
	printMvector(v1);
	v1.insert(v1.begin(), 100);
	printMvector(v1);
	v1.insert(v1.begin(), 3, 373);
	printMvector(v1);
	v1.erase(v1.begin());
	printMvector(v1);
	v1.erase(v1.begin() + 1, v1.end());
	printMvector(v1);
	v1.clear();
	printMvector(v1);
}
void test05()
{
	mvector<int>v1;
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;
	for (int i = 0; i < v1.size(); i++)
		cout << v1.at(i) << " ";
	cout << endl;
	cout << "第一个元素为:" << v1.front() << endl;
	cout << "最后一个元素为:" << v1.back() << endl;
}
void test06()
{
	mvector<int>v1;
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	printMvector(v1);
	mvector<int>v2;
	for (int i = 9; i >=0; i--)
		v2.push_back(i);
	printMvector(v2);
	v1.swap(v2);
	printMvector(v1);
	printMvector(v2);
}
void test07()
{
	mvector<int>v;
	v.reserve(100000);
	int num = 0;
	int*p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << "num=" << num << endl;
}
int main()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
}