#pragma once
#include<iostream>
#include<list>
using namespace std;
namespace mxyqueue
{
	template<typename T>
	class mqueue
	{
		list<T> l;
	public:
		mqueue() {};
		mqueue(const mqueue&q)
		{
			this->l = q.l;
		}
		mqueue&operator=(const mqueue&q)
		{
			this->l = q.l;
		}
		void push(T data)
		{
			this->l.push_back(data);
		}
		void pop()
		{
			this->l.pop_front();
		}
		T back()
		{
			return this->l.back();
		}
		T front()
		{
			return this->l.front();
		}
		bool empty()
		{
			return this->l.empty();
		}
		size_t size()
		{
			return this->l.size();
		}
	};
}