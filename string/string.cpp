#include"string.h"

namespace bit
{
	const size_t string::npos = -1;

	// 预留空间，至少能容纳n个字符（不包含\0），如果n小于等于当前容量，则不做任何操作
	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			//cout << "reserve:" << n << endl;

			// 1) 申请新空间
			char* tmp = new char[n + 1];
			// 2) 复制原数据
			strcpy(tmp, _str);
			// 3) 释放原空间
			delete[] _str;
			// 4) 更新指针和容量
			_str = tmp;
			// 5) 更新容量
			_capacity = n;
		}
	}

	void string::push_back(char ch)
	{
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}

		_str[_size] = ch;
		++_size;
		_str[_size] = '\0';
	}

	// 追加字符
	string& string::operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}

	// 追加字符串
	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			// 大于2倍，需要多少开多少，小于2倍按2倍扩
			reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
		}

		//第一个是目标地址\0的位置，所以直接覆盖
		strcpy(_str + _size, str);
		_size += len;
	}

	// 追加字符串重载，调用append函数
	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}

	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);

		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}

		// 挪动数据
		size_t end = _size;
		while (end > pos)
		{
			_str[end+1] = _str[end];
			--end;
		}

		_str[pos] = ch;
		++_size;
	}

	void string::insert(size_t pos, const char* s)
	{
		assert(pos <= _size);

		size_t len = strlen(s);
		if (_size + len > _capacity)
		{
			// 大于2倍，需要多少开多少，小于2倍按2倍扩
			reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
		}

		size_t end = _size + len;
		while (end > pos + len - 1)
		{
			_str[end] = _str[end - len];
			--end;
		}

		for (size_t i = 0; i < len; i++)
		{
			_str[pos + i] = s[i];
		}

		_size += len;
	}

	void erase(size_t pos, size_t len)
	{}

	void test_string1()
	{
		string s1;
		string s2("hello world");
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		for (size_t i = 0; i < s2.size(); i++)
		{
			s2[i] += 2;
		}
		cout << s2.c_str() << endl;

		for (auto e : s2)
		{
			cout << e << " ";
		}
	}
	void test_string2()
	{
		string s1;
		s1 += 'x';
		s1 += 'y';
		cout << s1.c_str() << endl;

		s1+= "hello";
		cout << s1.c_str() << endl;

		s1.insert(5, 'z');
		cout<< s1.c_str() << endl;
	}
}