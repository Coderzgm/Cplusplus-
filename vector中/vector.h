#pragma once
#include<assert.h>
#include<iostream>
namespace bit
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}

		void reserve()
		{

			if (n > capacity())
			{
				size_t old_size = size();
				T* tmp = new T[n];
				//拷贝旧数据上的空间给上新空间
				memcpy(tmp, start, size() * sizeof(T));
				delete[]_start;

				_start = tmp;
				_finish = tmp + old_size();
				_end_of_storage = start + n;
			}
		}

		size_t size()
		{
			return _finish - _start;
		}

		size_t capacity()
		{
			return _end_of_storage - _start;
		}

		void pushi_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;

	};

	void test_vector1()
	{
		vector<int>v;
		v.pushi_back(1);
		v.pushi_back(2);
		v.pushi_back(3);
		v.pushi_back(4);
		v.pushi_back(5);

		for (size_t i = 0;i < v.size();i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << endl;
		}
		cout << endl;
	}

}