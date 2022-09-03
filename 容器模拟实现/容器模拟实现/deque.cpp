#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
#include<string>
#include<time.h>
#include<iomanip>
using namespace std;
void printDeque(deque<int>&d)//可用const_iterator限定只读
{
	/*for (deque<int>::const_iterator i = d.begin(); i != d.end(); i++)
		cout << *i << " ";
	cout << endl;*/
	for (auto i : d)
		cout << i << " ";
	cout << endl;
}
void test01()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
		d1.push_back(i);
	printDeque(d1);
	deque<int>d2(d1.begin(), d1.end());
	printDeque(d1);
	deque<int>d3(7, 3);
	printDeque(d1);
	deque<int>d4(d3);
	printDeque(d1);
}
void test02()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
		d1.push_back(i);
	printDeque(d1);
	deque<int>d2;
d2 = d1;
printDeque(d2);
deque<int>d3;
d3.assign(d1.begin(), d1.end());
printDeque(d3);
deque<int>d4;
d4.assign(7, 3);
printDeque(d4);
}
void test03()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
		d1.push_front(i);
	printDeque(d1);
	if (d1.empty())
		cout << "d1为空" << endl;
	else
		cout << "d1不为空，大小为" << d1.size() << endl;
	d1.resize(5);
	printDeque(d1);
	d1.resize(15, 7);
	printDeque(d1);
}
void test04()
{
	deque<int>d1, d2;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(10);
	d1.push_front(20);
	d2 = d1;
	printDeque(d1);
	d1.pop_back();
	d1.pop_front();
	printDeque(d1);
	d2.insert(d2.begin(), 2333);
	printDeque(d2);
	d2.insert(d2.begin(), 3, 7);
	printDeque(d2);
	deque<int>d3;
	d3.push_back(1);
	d3.push_back(2);
	d3.push_back(3);
	d2.insert(d2.begin(), d3.begin(), d3.end());
	printDeque(d2);

	d2.erase(d2.begin() + 1);
	printDeque(d2);
	d2.erase(d2.begin(), d2.end() - 1);
	printDeque(d2);
	d2.clear();
	printDeque(d2);
}
void test05()
{
	deque<int>d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_front(1);
	d.push_front(2);
	d.push_front(3);
	for (size_t i = 0; i < d.size(); i++)
		cout << d[i] << " ";
	cout << endl;
	for (size_t i = 0; i < d.size(); i++)
		cout << d.at(i) << " ";
	cout << endl;
	d.pop_back();
	cout << d.front() << endl;
	cout << d.back() << endl;
}
void test06()
{
	deque<int>d;
	d.push_back(1);
	d.push_back(10);
	d.push_back(100);
	d.push_front(1000);
	d.push_front(500);
	d.push_front(250);
	printDeque(d);
	//对支持随机访问的迭代器都可用sort函数进行排序
	sort(d.begin(), d.end());
	printDeque(d);

}
class Participant
{
	string m_name;
	double m_grade;
public:
	Participant(string name, double grade=0)
	{
		this->m_grade = grade;
		this->m_name = name;
	}
	void setScore(double grade)
	{
		this->m_grade = grade;
	}
	double getSore()
	{
		return this->m_grade;
	}
	string getName()
	{
		return this->m_name;
	}
};
void setParticipant(vector <Participant>&v)
{
	string t_name = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += t_name[i];
		Participant p(name);
		v.push_back(p);
	}
}
void printList(vector<Participant>&v)
{
	for (auto i : v)
		cout << "姓名:" << i.getName() << "\t成绩:" << fixed << setprecision(2) << i.getSore()<<endl;
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	srand((unsigned int)time(NULL));
	vector<Participant>v;
	setParticipant(v);
	for (vector<Participant>::iterator i=v.begin();i!=v.end();i++)
	{
		deque<double>d;
		double sum = 0;
		for (size_t i = 0; i <10; i++)
			d.push_back(rand() % 41 + 60);
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();
		for (size_t i = 0; i < d.size(); i++)
			sum += d[i];
		i->setScore(sum /d.size());
	}
	printList(v);
	return 0;
}