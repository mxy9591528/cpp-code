#pragma once
#include<iostream>
using namespace std;
namespace mxyvector
{
	template<typename T>
	class mvector
	{
		T*_start;
		T*_end;//用指针记录数据元素个数，减去_start即为元素个数
		T*_endofstorage;//记录容量
	public:
		typedef T* iterator;//因使用模板，必须定义在类中
		typedef const T* const_iterator;
		mvector();	//采用模板实现类实现，默认构造函数
		mvector(T*begin, T*end);	//将v[begin(),ens()]区间的元素拷贝给本身
		mvector(size_t n, T elmn);	//构造函数将n个elem拷贝给本身
		mvector(const mvector&mvec);	//拷贝构造函数
		mvector&operator=(const mvector&mvec); //重载=号
		void assign(T* begin, T* end);	//将[begin,end]区间中的数据拷贝复制给本身
		void assign(size_t n, T elmn);	//将n个elem拷贝给本身
		bool empty();	//判断容器是否为空
		size_t capacity()const;	//容器容量
		size_t size()const;	//容器中元素的个数
		void resize(size_t num);	//重新指定容器的长度为num,变长用默认值填充新位置，变短删除超出元素
		void resize(size_t num, T elmn);	//重新指定容器的长度为num,变长用elmn填充新位置，变短删除超出元素
		void push_back(T elmn);	//尾插一个元素
		void pop_back();	//尾删一个元素
		void insert(const_iterator pos, T elmn);	//迭代器指向位置pos插入元素elmn
		void insert(iterator pos, size_t count, T elmn);	//迭代器指向位置pos插入count个元素elmn
		void erase(iterator pos);	//删除迭代器指向的元素
		void erase(iterator begin, iterator end);	//删除迭代器葱begin到end之间的元素
		void clear();	//删除容器中所有元素
		T&at(size_t index);	//返回索引index所指的数据
		T&operator[](size_t index);	//返回索引index所指的数据
		T&front();	//返回容器中的第一个元素
		T&back();	//返回容器中的最后一个数据元素
		void swap(mvector&mvec);	//将mvec与本身的元素互换
		void reserve(size_t len);	//容器预留len个元素长度,预留位置不初始化,元素不可访问
		iterator&begin()
		{
			return this->_start;
		}
		iterator&end()
		{
			return this->_end;
		}
		const_iterator&begin()const
		{
			return this->_start;
		}
		const_iterator&end()const
		{
			this->_end;
		}
		~mvector();	//析构函数
	}; 
	template<typename T>
	mvector<T>::mvector()
	{
		this->_start = this->_end = this->_endofstorage = NULL;
	}
	template<typename T>
	mvector<T>::mvector(T*begin, T*end)
	{
		size_t len = end - begin;//拷贝所需的空间长度
		this->reserve(len);
		for (size_t i = 0; i < len; i++)
		{
			this->_start[i] = begin[i];
			this->_end++;
		}
	}
	template<typename T>
	mvector<T>::mvector(size_t n, T elmn)
	{
		this->reserve(n);
		for (size_t i = 0; i < n; i++)
		{
			this->_start[i] = elmn;
			this->_end++;
		}
	}
	template<typename T>
	mvector<T>::mvector(const mvector & mvec)
	{
		this->reserve(mvec.capacity());
		for (size_t i = 0; i < mvec.size(); i++)
		{
			this->_start[i] = mvec._start[i];
			this->_end++;
		}
	}
	template<typename T>
	mvector<T>&mvector<T>::operator=(const mvector & mvec)
	{
		this->reserve(mvec.capacity());
		for (size_t i = 0; i < mvec.size(); i++)
		{
			this->_start[i] = mvec._start[i];
			this->_end++;
		}
		return *this;
	}
	template<typename T>
	void mvector<T>::assign(T*begin, T* end)
	{
		this->clear();//先清除原有数据
		size_t len = end - begin;
		this->reserve(len);
		for (size_t i = 0; i < len; i++)
		{
			this->_start[i] = begin[i];
			this->_end++;
		}
	}
	template<typename T>
	void mvector<T>::assign(size_t n, T elmn)
	{
		this->clear();
		this->reserve(n);
		for (size_t i = 0; i < n; i++)
		{
			this->_start[i] = elmn;
			this->_end++;
		}
	}
	template<typename T>
	bool mvector<T>::empty()
	{
		return this->_start == this->_end;//如果头尾指针相同，则未存任何元素，为空
	}
	template<typename T>
	size_t mvector<T>::capacity()const
	{
		return this->_endofstorage - this->_start;//地址相减
	}
	template<typename T>
	size_t mvector<T>::size()const
	{
		return this->_end - this->_start;
	}
	template<typename T>
	void mvector<T>::resize(size_t num)
	{
		if (num <= this->size())//指定任意大小空间
		{
			this->_end = this->_start + num;//重新指定尾指针
			this->_endofstorage = this->_start + num;
			return;
		}
		if (num > this->capacity())//扩大开辟空间
			this->reserve(num);
	}
	template<typename T>
	void mvector<T>::resize(size_t num, T elmn)//则个加个初始化赋值
	{
		if (num <= this->size())
		{
			this->_end = this->_start + num;
			this->_endofstorage = this->_start + num;
			return;
		}
		if (num > this->capacity())
		{
			size_t len = this->size();
			this->reserve(num);
			for (size_t i = len; i < num; i++)
			{
				this->_start[i] = elmn;
				this->_end++;
			}
		}
	}
	template<typename T>
	void mvector<T>::push_back(T elmn)
	{
		this->reserve(this->size()+1);
		this->_start[this->size()] = elmn;
		this->_end++;
	}
	template<typename T>
	void mvector<T>::pop_back()
	{
		this->_end -= 1;//尾指针后退一位就行
	}
	template<typename T>
	void mvector<T>::insert(const_iterator pos, T elmn)
	{
		this->reserve(this->size()+ 1);//检查空间是否足够大
		T* end = this->_end- 1;//指向最后一个元素
		while (end >= pos)
		{
			*(end + 1) = *end;//移位覆盖
			end--;
		}
		*(end+1) = elmn;//插入元素
		this->_end++;
	}
	template<typename T>
	void mvector<T>::insert(iterator pos, size_t count, T elmn)
	{
		size_t len1 = pos - this->_start, len2 = this->size();
		this->reserve(this->size() + count);
		pos = this->_start+len1;//pos地址可能会由于扩容改变，需要重新赋值
		for(size_t i=0;i<count;i++)
		{
			for (size_t j = 0; j < len2; j++)
				this->_end[i-j] = this->_end[i-j-1];//循环移位
			pos[i] = elmn;//给挪出来的空间赋值
		}
		this->_end += count;
	}
	template<typename T>
	void mvector<T>::erase(iterator pos)
	{
		for (iterator i = pos; i < this->_end - 1; i++)//移位覆盖清除
			*i = *(i + 1);
		this->_end -= 1;
	}
	template<typename T>
	void mvector<T>::erase(iterator begin, iterator end)
	{
		size_t len = end - begin;
		for (iterator i = begin; i < end; i++)
			*i = *(i + len);
		this->_end -= len;
	}
	template<typename T>
	void mvector<T>::clear()
	{
		this->erase(this->begin(), this->_end);
	}
	template<typename T>
	T&mvector<T>::at(size_t index)
	{
		return *(this->_start + index);
	}
	template<typename T>
	T&mvector<T>::operator[](size_t index)
	{
		return *(this->_start + index);
	}
	template<typename T>
	T&mvector<T>::front()
	{
		return *this->_start;
	}
	template<typename T>
	T&mvector<T>::back()
	{
		return *(this->_end-1);//返回最后一个元素
	}
	template<typename T>
	void mvector<T>::swap(mvector & mvec)
	{
		std::swap(this->_start, mvec._start);//运用库函数交换
		std::swap(this->_end, mvec._end);
		std::swap(this->_endofstorage, mvec._endofstorage);
	}
	template<typename T>
	void mvector<T>::reserve(size_t len)
	{
		if (len >this->capacity())
		{
			size_t sz = this->size();
			T* tmp = new T[len];
			if (this->_start) 
			{
				for (size_t i = 0; i < sz; i++)
					tmp[i] = this->_start[i];
				delete[] _start;
			}
			this->_start = tmp;
			this->_end = tmp + sz;
			this->_endofstorage = _start + len;
		}
	}
	template<typename T>
	mvector<T>::~mvector()
	{
		if(this->_start)
			delete[]this->_start;
		this->_start = this->_end = this->_endofstorage = NULL;
	}
}