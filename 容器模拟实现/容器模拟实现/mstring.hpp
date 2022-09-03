#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
namespace mxystring
{
	static const size_t npos = -1;//size_t只能是正数，取-1即size_t为最大值
	static const size_t addnum = 15;
	typedef char* iterator;
	typedef const char* const_iterator;
	class mstring
	{
	private:
		char*_str;
		size_t _size;
		size_t _capacity;
		void checkcapacity()
		{
			if (this->_capacity < this->_size)
			{
				while (this->_capacity < this->_size)
					this->_capacity += addnum;
				char*ret = new char[this->_capacity + 1];
				if (this->_str)
				{
					strcpy(ret, this->_str);
					delete[]this->_str;
				}
				this->_str = ret;
			}
		}
	public:
		mstring();												//创建一个空字符串
		mstring(const char*s);									//使用字符串s初始化
		mstring(const mstring&str);								//使用一个string对象初始化另一个string对象
		mstring(size_t n, char c);								//使用n个字符c初始化
		mstring&operator=(const char*s);							//char*类型字符串赋值给当前的字符串
		mstring&operator=(const mstring&s);						//把字符串s赋值给当前的字符串
		mstring&operator=(char c);								//字符赋值给当前的字符串
		mstring&assign(const char*s);							//把字符串s赋值给当前的字符串
		mstring&assign(const char*s, size_t n);					//把字符串s的前n个字符赋给当前的字符串
		mstring&assign(const mstring&s);							//把字符串s赋值给当前的字符串
		mstring&assign(size_t n, char c);						//用n个字符c赋给当前字符串
		mstring&operator+=(const char*str);						//重载+=操作符
		mstring&operator+=(const char c);						//重载+=操作符
		mstring&operator+=(const mstring&str);					//重载+=操作符
		mstring&append(const char*s);							//把字符串s连接到当前字符串结尾
		mstring&append(const char*s, size_t n);					//把字符串s的前n个字符连接到当前字符串
		mstring&append(const mstring&s);							//同operator=(const string&s);
		mstring&append(const mstring&s, size_t pos, size_t n);	//字符串s从pos开始的n个字符连接到当前的字符串
		size_t find(const mstring&str, size_t pos = 0)const;		//查找str第一次出现的位置，从pos开始查找
		size_t find(const char*s, size_t pos = 0)const;			//查找s第一次出现的位置，从pos开始查找
		size_t find(const char*s, size_t pos, size_t n)const;	//从pos位置查找s的前n个字符串第一次位置
		size_t find(const char c, size_t pos = 0)const;			//查找字符c第一次出现的位置
		//size_t rfind(const mstring&str, size_t pos = npos)const;	//查找str最后一次位置，从pos开始查找
		//size_t rfind(const char*s, size_t pos = npos)const;		//查找s最后一次位置，从pos开始查找
		//size_t rfind(const char*s, size_t pos, size_t n)const;	//从pos位置查找s的前n个字符串最后一次的位置
		//size_t rfind(const char c, size_t pos = npos)const;		//查找字符最后一次出现的位置
		mstring&replace(size_t pos, size_t n, const mstring&str);	//替换从pos开始n个字符为字符串str
		mstring&replace(size_t pos, size_t n, const char*s);		//替换从pos开始n个字符为字符串s
		int compare(const mstring&s)const;						//与字符串s比较
		int compare(const char*s)const;						//与字符串s比较
		friend bool operator<(const mstring&s1, const mstring&s2);		//重载<
		friend bool operator==(const mstring&s1, const mstring&s2);		//重载==
		friend bool operator>=(const mstring&s1, const mstring&s2);		//重载>=
		friend bool  operator<=(const mstring&s1, const mstring&s2);		//重载<=
		friend bool operator!=(const mstring&s1, const mstring&s2);		//重载!=
		friend bool operator>(const mstring&s1, const mstring&s2);		//重载>
		char&operator[](size_t n);								//通过[]方法取字符
		const char&operator[](size_t pos)const;					//获取字符，只读
		char&at(size_t n);										//通过at方法获取字符
		mstring&insert(size_t pos, const char*s);				//插入字符串
		mstring&insert(size_t pos, const mstring&str);			//插入字符串
		mstring&insert(size_t pos, size_t n, char c);			//在指定位置插入n个字符c
		mstring&erase(size_t pos, size_t n = npos);				//删除从pos开始的n个字符
		mstring substr(size_t pos = 0, size_t n = npos)const;	//返回由pos开始的n个字符组成的字符串
		void swap(mstring&s);									//交换类内容
		iterator begin();										//可读可写迭代器
		iterator end();
		const_iterator begin()const;							//只读迭代器
		const_iterator end()const;
		size_t size();											//获取元素个数
		size_t capacity();										//获取容量大小
		const char*c_str()const;										//返回c形式字符串
		void reserve(size_t n);									//增容
		void resize(size_t n, char c = '\0');					//增容
		void clear();											//置空字符串
		void push_back(char c);									//尾插字符
		friend istream&operator>>(istream&in, mstring&s);				//重载输入流
		friend ostream&operator<<(ostream&out, const mstring&s);		//重载输出流
		~mstring();												//析构函数
	};
	mstring::mstring()
	{
		this->_size = 0;
		this->_capacity = addnum;
		this->_str = new char[this->_capacity + 1];
		memset(this->_str, '\0', this->_capacity + 1);
	}
	mstring::mstring(const char*s)
	{
		this->_size = strlen(s);
		this->checkcapacity();
		strcpy(this->_str, s);
	}
	mstring::mstring(const mstring&str)
	{
		this->_size = str._size;
		this->checkcapacity();
		strcpy(this->_str, str._str);
	}
	mstring::mstring(size_t n, char c)
	{
		this->_capacity = n;
		this->checkcapacity();
		for (size_t i = 0; i < n; i++)
			this->_str[i] = c;
	}
	mstring&mstring::operator=(const char * s)
	{
		this->_size = strlen(s);
		this->checkcapacity();
		strcpy(this->_str, s);
		return *this;
	}
	mstring&mstring::operator=(const mstring&s)
	{
		this->_size = s._size;
		this->checkcapacity();
		strcpy(this->_str, s._str);
		return *this;
	}
	mstring&mstring::operator=(char c)
	{
		this->_size = 1;
		this->checkcapacity();
		this->_str[0] = c;
		this->_str[1] = '\0';
		return *this;
	}
	mstring&mstring::operator+=(const char*str)
	{
		this->_size += strlen(str);
		this->checkcapacity();
		strcat(this->_str, str);
		return *this;
	}
	mstring&mstring::operator+=(const char c)
	{
		this->_size++;
		this->checkcapacity();
		strncat(this->_str, &c, 1);
		return *this;
	}
	mstring&mstring::operator+=(const mstring&str)
	{
		this->_size += str._size;
		this->checkcapacity();
		strcat(this->_str, str._str);
		return *this;
	}
	mstring&mstring::assign(const char*s)
	{
		this->_size = strlen(s);
		this->checkcapacity();
		strcpy(this->_str, s);
		return *this;
	}
	mstring&mstring::assign(const char*s, size_t n)
	{
		this->_size = n;
		this->checkcapacity();
		strncpy(this->_str, s, n);
		return *this;
	}
	mstring&mstring::assign(const mstring&s)
	{
		this->_size = s._size;
		this->checkcapacity();
		strcpy(this->_str, s._str);
		return *this;
	}
	mstring&mstring::assign(size_t n, char c)
	{
		this->_size = n;
		this->checkcapacity();
		size_t i = 0;
		while (i < n)
			this->_str[i++] = c;
		this->_str[i] = 0;
		return *this;
	}
	mstring&mstring::append(const char*s)
	{
		this->_size += strlen(s);
		this->checkcapacity();
		strcat(this->_str, s);
		return *this;
	}
	mstring&mstring::append(const mstring&s)
	{
		this->_size += s._size;
		this->checkcapacity();
		strcat(this->_str, s._str);
		return *this;
	}
	mstring&mstring::append(const char*s, size_t n)
	{
		this->_size += n;
		this->checkcapacity();
		strncat(this->_str, s, n);
		return *this;
	}
	mstring&mstring::append(const mstring&s, size_t pos, size_t n)
	{
		this->_size += n;
		this->checkcapacity();
		strncat(this->_str, s._str + pos, n);
		return *this;
	}
	size_t mstring::find(const mstring&str, size_t pos)const
	{
		const char*p = strstr(this->_str + pos, str._str);
		if (p == NULL)
			return npos;
		else
			return p - this->_str;
	}
	size_t mstring::find(const char*s, size_t pos)const
	{
		const char*p = strstr(this->_str + pos, s);
		if (p == NULL)
			return npos;
		else
			return p - this->_str;
	}
	size_t mstring::find(const char*s, size_t pos, size_t n)const
	{
		const char*p = strstr(this->_str, s);
		if (p == NULL || (size_t)(p - this->_str) > pos)
			return npos;
		else
			return p - this->_str;
	}
	size_t mstring::find(const char c, size_t pos)const
	{
		for (size_t i = 0; i < this->_size; i++)
		{
			if (this->_str[i] == c)
				return i;
		}
		return npos;
	}
	//size_t mstring::rfind(const mstring&str, size_t pos )const
	//{
	//	const char*p = strstr(this->_str + pos, str._str);
	//	size_t n = 0;
	//	while (*p)
	//	{
	//		n = p - this->_str;
	//		p = strstr(this->_str + n, str._str);
	//	}
	//	if (n)
	//		return n;
	//	else
	//		return npos;
	//}
	//size_t mstring::rfind(const char*s, size_t pos )const
	//{
	//	const char*p = strstr(this->_str + pos,s);
	//	size_t n = 0;
	//	while (*p)
	//	{
	//		n = p - this->_str;
	//		p = strstr(this->_str + n, s);
	//	}
	//	if (n)
	//		return n;
	//	else
	//		return npos;
	//}
	//size_t mstring::rfind(const char*s, size_t pos, size_t n)const
	//{
	//	const char*p = strstr(this->_str , s);
	//	size_t len = 0;
	//	while (*p)
	//	{
	//		len = p - this->_str;
	//		if (len > pos)
	//		{
	//			len = 0;
	//			break;
	//		}
	//		p = strstr(this->_str + n, s);
	//	}
	//	if (len)
	//		return n;
	//	else
	//		return npos;
	//}
	//size_t mstring::rfind(const char c, size_t pos)const
	//{
	//	const char*p = strchr(this->_str, c);
	//	if (p == NULL)
	//		return npos;
	//	else
	//		return p - this->_str;
	//}
	mstring&mstring::replace(size_t pos, size_t n, const mstring&str)
	{
		char*temp = new char[this->_size - pos - n + 1];
		strcpy(temp, this->_str + pos + n);
		this->_size += str._size - n + pos;
		this->checkcapacity();
		strncpy(this->_str + pos, str._str, str._size);
		strcpy(this->_str + pos + str._size, temp);
		delete[]temp;
		temp = NULL;
		return *this;
	}
	mstring&mstring::replace(size_t pos, size_t n, const char*s)
	{
		char*temp = new char[this->_size - pos - n + 1];
		strcpy(temp, this->_str + pos + n);
		this->_size += strlen(s) - n + pos;
		this->checkcapacity();
		strncpy(this->_str + pos, s, strlen(s));
		strcpy(this->_str + pos + strlen(s), temp);
		delete[]temp;
		temp = NULL;
		return *this;
	}
	int mstring::compare(const mstring&s)const
	{
		return strcmp(this->_str, s._str);
	}
	int mstring::compare(const char*s)const
	{
		return strcmp(this->_str, s);
	}
	bool operator<(const mstring&s1, const mstring&s2)
	{
		return strcmp(s1._str, s2._str) < 0;
	}
	bool operator==(const mstring&s1, const mstring&s2)
	{
		return strcmp(s1._str, s2._str) == 0;
	}
	bool operator>=(const mstring&s1, const mstring&s2)
	{
		return !(s1 < s2);
	}
	bool operator<=(const mstring&s1, const mstring&s2)
	{
		return s1 < s2 || s1 == s2;
	}
	bool operator!=(const mstring&s1, const mstring&s2)
	{
		return !(s1 == s2);
	}
	bool operator>(const mstring&s1, const mstring&s2)
	{
		return !(s1 <= s2);
	}
	char&mstring::operator[](size_t n)
	{
		return this->_str[n];
	}
	const char&mstring::operator[](size_t pos)const
	{
		return this->_str[pos];
	}
	char&mstring::at(size_t n)
	{
		return this->_str[n];
	}
	mstring&mstring::insert(size_t pos, const char*s)
	{
		int len = strlen(s);
		this->_size += len;
		this->checkcapacity();
		size_t end = this->_size;
		while (end >= pos + len)
		{
			this->_str[end] = this->_str[end - len];
			end--;
		}
		strncpy(this->_str + pos, s, len);
		return *this;
	}
	mstring&mstring::insert(size_t pos, const mstring&str)
	{
		this->_size += str._size;
		this->checkcapacity();
		size_t end = this->_size;
		while (end >= pos + str._size)
		{
			this->_str[end] = this->_str[end - str._size];
			end--;
		}
		strncpy(this->_str + pos, str._str, str._size);
		return *this;
	}
	mstring&mstring::insert(size_t pos, size_t n, char c)
	{
		this->_size += n;
		this->checkcapacity();
		size_t end = this->_size;
		while (end >= pos + n)
		{
			this->_str[end] = this->_str[end - n];
			this->_str[end - n] = c;
			end--;
		}
		return *this;
	}
	mstring&mstring::erase(size_t pos, size_t n)
	{
		if (pos == npos || pos + n >= this->_size)
		{
			this->_str[pos] = '\0';
			this->_size = pos;
		}
		else
		{
			this->_str[pos] = '\0';
			strcat(this->_str + pos, this->_str + pos + n);
		}
		return *this;
	}
	mstring mstring::substr(size_t pos, size_t n)const
	{
		char*ret = new char[n + 1];
		strncpy(ret, this->_str + pos, n);
		ret[n] = '\0';
		return ret;
	}
	void mstring::swap(mstring&s)
	{
		std::swap(this->_str, s._str);
		std::swap(this->_capacity, s._capacity);
		std::swap(this->_size, s._size);
	}
	iterator mstring::begin()
	{
		return this->_str;
	}
	iterator mstring::end()
	{
		return this->_str + this->_size;
	}
	const_iterator mstring::begin()const
	{
		return this->_str;
	}
	const_iterator mstring::end()const
	{
		return this->_str + this->_size;
	}
	size_t mstring::size()
	{
		return this->_size;
	}
	size_t mstring::capacity()
	{
		return this->_capacity;
	}
	const char*mstring::c_str()const
	{
		return this->_str;
	}
	void mstring::reserve(size_t n)
	{
		if (n > this->_capacity)
		{
			char*temp = new char[n + 1];
			strcpy(temp, this->_str);
			delete[]this->_str;
			this->_str = temp;
			this->_capacity = n;
		}
	}
	void mstring::resize(size_t n, char c)
	{
		if (n <= this->_size)
		{
			this->_size = n;
			this->_str[this->_size] = c;
		}
		else
		{
			if (n > this->_capacity)
				this->reserve(n);
			memset(this->_str + this->_size, c, n - this->_size);
			this->_size = n;
			this->_str[this->_size] = '\0';
		}
	}
	void mstring::clear()
	{
		this->_size = 0;
		this->_str[this->_size] = '\0';
	}
	void mstring::push_back(char c)
	{
		this->_size++;
		this->checkcapacity();
		this->_str[this->_size - 1] = c;
		this->_str[this->_size] = '\0';
	}
	istream&operator>>(istream&in, mstring&s)
	{
		s.clear();
		char c = in.get();
		while (c != '\n' || c != ' ')
		{
			s += c;
			c = in.get();
		}
		return in;
	}
	ostream&operator<<(ostream&out, const mstring&s)
	{
		for (auto c : s)
			out << c;
		return out;
	}
	mstring::~mstring()
	{
		delete[]this->_str;
		this->_str = NULL;
		this->_capacity = 0;
		this->_size = 0;
	}
}

