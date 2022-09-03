#pragma once
#include<iostream>
using namespace std;
namespace mxydeque
{
	template<typename T,class _Allo=alloc,size_t Bufsize>
	class mdeque
	{
	public:
		typedef T data_type;
		typedef date_type* ptr;
		typedef deque_iterator<T, T&, T*, Bufsize> iterator;
	protect:
		typedef ptr* map_ptr;
		map_ptr map;
		size_t map_size;
		iterator start;
		iterator end;
	};
}
