#pragma once
#include<iostream>
using namespace std;
namespace mxylist
{
	template<typename T>
	struct ListNode
	{
		ListNode<T>*_prev;
		ListNode<T>*_next;
		T _data;
	};
	template<typename T, typename Ref, typename Ptr>
	class ListIterator
	{
	public:
		ListNode<T>*_node;
		typedef ListNode<T> Node;
		typedef ListIterator<T, Ref, Ptr> self;
		ListIterator(Node*node)
		{
			this->_node = node;
		}
		Ref operator*()
		{
			return this->_node->_data;
		}
		Ptr &operator->()
		{
			return &(this->_node->_data);
		}
		self&operator++()
		{
			this->_node = this->_node->_next;
			return *this;
		}
		self&operator++(int)
		{
			self temp(*this);
			this->_node = this->_node->_next;
			return temp;
		}
		self&operator--()
		{
			this->_node = this->_node->_prev;
			return *this;
		}
		self&operator--(int)
		{
			self temp(*this);
			this->_node = this->_node->_prev;
			return temp;
		}
		bool operator!=(const self&it)
		{
			return this->_node != it._node;
		}
		bool operator==(const self&it)
		{
			return this->_node == it._node;
		}
	};
	template<typename T>
	class mlist
	{
	public:
		typedef ListNode<T> Node;
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;
	private:
		Node*_head;
		void CreatHead()
		{
			this->_head = new Node;
			this->_head->_prev = this->_head->_next = this->_head;
		}
	public:
		mlist();								//默认构造
		mlist(iterator begin, iterator end);	//构造函数将[begin，end]区间中的元素拷贝给本身
		mlist(size_t n, const T&elmn);			//构造函数将n个elmn拷贝给本身
		mlist(mlist<T>&list);				//拷贝构造函数
		void assign(iterator begin, iterator end);//将[begin，end]区间中的元素拷贝给本身
		void assign(size_t n, const T&elmn);	//将n个elmn拷贝给本身
		mlist&operator=(mlist<T>&list);		//重载=
		void swap(mlist<T>&list);						//将list的元素与本身的元素进行互换
		size_t size();								//返回容器元素个数
		bool empty();								//判断容器是否为空
		void resize(size_t n, const T&elmn = 0);		//重新指定容器长度，变成以默认指或传入值填充，变短，删除多余元素
		void push_back(const T&elmn);				//在容器尾部插入一个元素
		void pop_back();							//删除容器中最后一个元素
		void push_front(const T&elmn);				//在头部插入一个元素
		void pop_front();							//删除容器开头的一个元素
		iterator insert(iterator pos, const T&elmn);	//在pos处插入elmn元素，返回新数据的位置
		void insert(iterator pos, size_t n, const T&elmn);//在pos处插入n个elmn元素，无返回值
		void insert(iterator pos, iterator begin, iterator end);//在pos位置插入[begin，end]区间的数据，无返回值
		void clear();							//清除容器数据
		iterator erase(iterator begin, iterator end);//删除[begin，end]区间的数据，返回下一个数据的位置
		iterator erase(iterator pos);					//删除pos位置的数据，返回下一个数据的位置
		void remove(const T&elmn);					//删除容器中所有与elmn匹配的元素
		T&front();
		T&back();
		const T&front()const;						//返回第一个元素
		const T&back()const;						//返回最后一个元素
		void reverse();								//反转链表
		void sort();								//链表排序
		iterator begin();							//迭代器
		iterator end();
		const_iterator begin()const;
		const_iterator end()const;
		~mlist();									//析构函数
	};
	template<typename T>
	mlist<T>::mlist()
	{
		this->CreatHead();
	}
	template<typename T>
	mlist<T>::mlist(iterator begin, iterator end)
	{
		this->CreatHead();
		while (begin != end)
		{
			this->push_back(*begin);
			++begin;
		}
	}
	template<typename T>
	mlist<T>::mlist(size_t n, const T & elmn)
	{
		this->CreatHead();
		for (size_t i = 0; i < n; i++)
			this->push_back(elmn);
	}
	template<typename T>
	mlist<T>::mlist(mlist<T> & list)
	{
		this->CreatHead();
		this->assign(list.begin(), list.end());
	}
	template<typename T>
	void mlist<T>::assign(iterator begin, iterator end)
	{
		this->CreatHead();
		this->insert(this->begin(), begin, end);
	}
	template<typename T>
	void mlist<T>::assign(size_t n, const T & elmn)
	{
		this->CreatHead();
		for (size_t i = 0; i < n; i++)
			this->push_back(elmn);
	}
	template<typename T>
	mlist<T> & mlist<T>::operator=(mlist<T> & list)
	{
		this->CreatHead();
		this->assign(list.begin(),list.end());
		return*this;
	}
	template<typename T>
	void mlist<T>::swap(mlist<T> & list)
	{
		std::swap(this->_head, list._head);
	}
	template<typename T>
	size_t mlist<T>::size()
	{
		size_t count = 0;
		for (mlist<T>::iterator it = this->begin(); it != this->end(); it++)
			count++;
		return count;
	}
	template<typename T>
	bool mlist<T>::empty()
	{
		return this->begin() == this->end();
	}
	template<typename T>
	void mlist<T>::resize(size_t n, const T & elmn)
	{
		size_t len = this->size();
		if (n <= len)
		{
			for (size_t i = n; i < len; i++)
				this->pop_back();
		}
		else
			this->insert(this->end(), n - len, elmn);
	}
	template<typename T>
	void mlist<T>::push_back(const T & elmn)
	{
		insert(this->end(), elmn);
	}
	template<typename T>
	void mlist<T>::pop_back()
	{
		this->erase(--this->end());
	}
	template<typename T>
	void mlist<T>::push_front(const T & elmn)
	{
		this->insert(this->begin(), elmn);
	}
	template<typename T>
	void mlist<T>::pop_front()
	{
		this->erase(this->begin());
	}

	template<typename T>
	typename mlist<T>::iterator mlist<T>::insert(iterator pos, const T & elmn)
	{
		Node*node = new Node, *Pos = pos._node;
		node->_data = elmn;
		node->_next = Pos;
		node->_prev = Pos->_prev;
		Pos->_prev->_next = node;
		Pos->_prev = node;
		return iterator(node);
	}

	template<typename T>
	void mlist<T>::insert(iterator pos, size_t n, const T & elmn)
	{
		while (n--)
		{
			this->insert(pos, elmn);
		}
	}

	template<typename T>
	void mlist<T>::insert(iterator pos, iterator begin, iterator end)
	{
		while (begin != end)
		{
			this->insert(pos, begin._node->_data);
			begin++;
		}
	}

	template<typename T>
	void mlist<T>::clear()
	{
		this->erase(this->begin(), this->end());
	}

	template<typename T>
	typename mlist<T>::iterator mlist<T>::erase(iterator begin, iterator end)
	{
		iterator it = begin;
		while (it != end)
		{
			it = this->erase(it);
		}
		return it;
	}

	template<typename T>
	typename mlist<T>::iterator mlist<T>::erase(iterator pos)
	{
		Node*Pos = pos._node;
		if (pos == this->end())
			return this->end();
		Node*node = Pos->_next;
		Pos->_prev->_next = node;
		node->_prev = Pos->_prev;
		delete Pos;
		Pos = NULL;
		return iterator(node);
	}

	template<typename T>
	void mlist<T>::remove(const T & elmn)
	{
		for (mlist<T>::iterator i = this->begin(); i != this->end(); i++)
		{
			if (i._node->_data == elmn)
				i=this->erase(i);
		}
	}

	template<typename T>
	T & mlist<T>::front()
	{
		return this->begin()._node->_data;
	}

	template<typename T>
	T & mlist<T>::back()
	{
		return (--this->end())._node->_data;
	}

	template<typename T>
	const T & mlist<T>::front() const
	{
		return this->begin()._node->_data;
	}

	template<typename T>
	const T & mlist<T>::back() const
	{
		return this->end()._node->_data;
	}

	template<typename T>
	void mlist<T>::reverse()
	{
		iterator begin = this->begin();
		iterator end = --this->end();
		while (begin!=end)
		{
			std::swap(begin._node->_data, end._node->_data);
			++begin;
			if (begin == end)
				return;
			--end;
			if (begin == end)
				return;
		}
	}

	template<typename T>
	void mlist<T>::sort()
	{
		for (iterator i = this->begin(); i != this->end(); i++)
		{
			iterator min = i, ret = i;
			for (iterator j =ret++; j != this->end(); j++)
				if (min._node->_data > j._node->_data)
					min = j;
			if (min != i)
				std::swap(min._node->_data, i._node->_data);
		}
	}
	template<typename T>
	typename mlist<T>::iterator mlist<T>::begin()
	{
		return iterator(this->_head->_next);
	}
	template<typename T>
	typename mlist<T>::iterator mlist<T>::end()
	{
		return iterator(this->_head);
	}
	template<typename T>
	typename mlist<T>::const_iterator mlist<T>::begin() const
	{
		return const_iterator(this->_head->_next);
	}
	template<typename T>
	typename mlist<T>::const_iterator mlist<T>::end() const
	{
		return const_iterator(this->_head);
	}
	template<typename T>
	mlist<T>::~mlist()
	{
		this->clear();
		delete this->_head;
		this->_head = NULL;
	}
}