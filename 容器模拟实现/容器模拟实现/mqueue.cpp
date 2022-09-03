#include"mqueue.hpp"
#include<string>
using namespace mxyqueue;
class Person
{
	string m_name;
	int m_age;
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string getName()
	{
		return this->m_name;
	}
	int getAge()
	{
		return this->m_age;
	}
};
int main()
{
	Person p[4] = { {"魁拔",999},{"萧炎",888},{"林动",777},{"牧尘",666} };
	mqueue<Person>q;
	for (int i = 0; i < 4; i++)
		q.push(p[i]);
	while (!q.empty())
	{
		cout << "队头元素——姓名:" << q.front().getName() << "  年龄:" << q.front().getAge() << endl;
		cout << "队尾元素——姓名:" << q.back().getName() << "  年龄:" << q.back().getAge() << endl;
		q.pop();
	}
	cout << "队列大小为:" << q.size() << endl;
}