#pragma once
#include<iostream>
#include<vector>
using namespace std;
namespace mxystack
{
	template<typename T>
	class mstack
	{
		vector<T>v;
	public:
		mstack() {}
		mstack(const mstack&s)
		{
			this->v = s.v;
		}
		mstack&operator=(const mstack&s)
		{
			this->v = s.v;
		}
		void push(T data)
		{
			this->v.push_back(data);
		}
		void pop()
		{
			this->v.pop_back();
		}
		T top()
		{
			return this->v.back();
		}
		bool empty()
		{
			return this->v.empty();
		}
		size_t size()
		{
			return this->v.size();
		}
	};
}