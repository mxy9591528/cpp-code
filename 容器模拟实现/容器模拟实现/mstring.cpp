#include"mstring.hpp"
#include<string>
using namespace mxystring;
void test01()
{
	mstring s1;//默认构造
	const char*str = "Hellow world!";
	mstring s2(str);
	cout << "s2=" << s2 << endl;
	mstring s3(s2);
	cout << "s3=" << s3 << endl;
}
void test02()
{
	mstring str1;
	str1 = "Hello world";
	cout << "str1=" << str1<< endl;
	mstring str2;
	str2 = str1;
	cout << "str2=" << str2 << endl;
	mstring str3;
	str3 = 'a';
	cout << "str3=" << str3 << endl;
	mstring str4;
	str4.assign("Hello world!");
	cout << "str4=" << str4 << endl;
	mstring str5;
	str5.assign("Hello world!", 5);
	cout << "str5=" << str5 << endl;
	mstring str6;
	str6.assign(str5);
	cout << "str6=" << str6 << endl;
	mstring str7;
	str7.assign(7, 'h');
	cout << "str7=" << str7 << endl;
}
void test03()
{
	mstring str1 = "艾伦";
	str1 += "*耶格尔";
	cout << "str1=" << str1 << endl;
	str1 += ':';
	cout << "str1=" << str1 << endl;
	mstring str2 = "发动地鸣";
	str1 += str2;
	cout << "str1=" << str1 << endl;
	mstring str3 = "I ";
	str3.append("LOVE ");
	cout << "str3=" << str3 << endl;
	str3.append("YOU forever", 3);
	cout << "str3=" << str3 << endl;
	str3.append(str1);
	cout << "str3=" << str3 << endl;
	str3.append(str1, 0, 4);
	cout << "str3=" << str3 << endl;
	str3.append(str1, 4, 4);
	cout << "str3=" << str3 << endl;
}
void test04()
{
	mstring str1 = "abcdefg";
	int pos=str1.find("fg");
	if (pos == -1)
		cout << "未找到字符串" << endl;
	else
		cout << "pos=" << pos << endl;
	string s = "abcdefg";
	s.rfind("fg");
	cout << "pos=" << pos << endl;
}
void test05()
{
	mstring str1 = "abcdefg";
	str1.replace(1, 3, "3333");
	cout << "str1=" << str1 << endl;
	mstring str2 = "nonono";
	str1.replace(0, 1, str2);
	cout << "str1=" << str1 << endl;
}
void test06()
{
	mstring str1 = "Hello", str2 = "Hello";
	if (str1.compare(str2) == 0)
		cout << "str1==str2" << endl;
	if (str1 == str2)
		cout << "str1==str2" << endl;
	str1 += ' ';
	if (str1.compare(str2) > 0)
		cout << "str1>str2" << endl;
	if (str1 > str2)
		cout << "str1>str2" << endl;
	str2 += 'w';
	if (str1.compare(str2) < 0)
		cout << "str1<str2" << endl;
	if (str1 < str2)
		cout << "str1<str2" << endl;
}
void test07()
{
	mstring str = "Hello";
	for (size_t i = 0; i < str.size(); i++)
		cout << str[i] << " ";
	cout << endl;
	for (size_t i = 0; i < str.size(); i++)
		cout << str.at(i) << " ";
	cout << endl;
	str[0] = 'h';
	cout << "str=" << str << endl;
	str.at(0) = 'H';
	cout << "str=" << str << endl;
}
void test08()
{
	mstring str = "Hellow", s = " world!";
	str.insert(6, " world!");
	cout << "str=" << str << endl;
	str.erase(5, 12);
	cout << "str=" << str << endl;
	str.insert(5, s);
	cout << "str=" << str << endl;
}
void test09()
{
	mstring str = "abcdef";
	mstring substr = str.substr(1, 3);
	cout << "substr=" << substr << endl;
	mstring email = "mxy2287352895@outlook.com";
	int pos = email.find('@');
	cout << pos << endl;
	mstring username = email.substr(0, pos);
	cout << "username=" << username << endl;
}
void test10()
{
	mstring s1 = "Hello", s2 = "world";
	cout << "s1=" << s1 << endl << "s2=" << s2 << endl;
	s1.swap(s2);
	cout << "s1=" << s1 << endl;
	for (mxystring::iterator i = s1.begin(); i != s1.end(); i++)
		cout << *i << " ";
	cout << endl;
	s1.push_back('O');
	cout << "s1=" << s1 << endl;
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	//est09();
	test10();
}