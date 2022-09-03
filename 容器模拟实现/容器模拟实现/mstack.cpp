#include"mstack.hpp"
using namespace mxystack;
int main()
{
	mstack<int>s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	mstack<int>s2(s1);
	cout << s2.top() << endl << s2.size()<<endl;
	while (!s2.empty())
	{
		cout << s2.top() << " ";
		s2.pop();
	}
	cout << endl;
	return 0;
}