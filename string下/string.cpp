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

	// 在pos位置插入字符ch
	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);

		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}

		// 挪动数据
		//int end = _size;
		//while (end >= (int)pos)
		//{
		//	if (end == 0)
		//	{
		//		int a = 0;
		//	}
		//	_str[end + 1] = _str[end];
		//	--end;
		//}
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}

		_str[pos] = ch;
		++_size;
	}

	// 在pos位置插入字符串str
	void string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);

		size_t len = strlen(str);
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
			_str[pos + i] = str[i];
		}

		_size += len;
	}

	void string::erase(size_t pos, size_t len)
	{
		if (len >= _size - pos)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			size_t end = pos + len;
			while (end <= _size)
			{
				_str[pos] = _str[end];
				++pos;
				++end;
			}
			_size -= len;
		}
	}
	size_t string::find(char ch, size_t pos = 0)
	{
		for (size_t i = pos;i < _size;i++)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}
		return npos;
	}
	size_t string::find(const char* str, size_t pos = 0)
	{
		assert(pos <= _size);
		const char* ptr = strstr(_str + pos, str);
		if (ptr == nullptr)
		{
			return npos;
		}
		else
		{
			return ptr - _str;
		}
		size_t len = strlen(str);


	}
	string string::substr(size_t pos, size_t len)
	{
		assert(pos < _size);

		//len为npos或超出范围时，截取到末尾,更新len为实际长度
		if (len == npos || pos + len > _size)
		{
			len = _size - pos;
		}
		string sub;
		sub.reserve(len);
		for (size_t i = 0;i < len;i++)
		{
			sub += _str[pos + 1];
		}
		return sub;
	}
	bool operator<(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) < 0;
	}
	bool operator<=(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) <= 0;
	}
	bool operator>(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) > 0;
	}
	bool operator>=(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) >= 0;
	}
	bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}
	bool operator!=(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) != 0;
	}
	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto ch:s)
		{
			out<<ch;
		}
		return out;
	}
	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		const int N = 256;
		char buff[N];
		int i = 0;

		char ch;
		//in >> ch;
		// 读入第一个非空白字符,get()不跳过空白字符，会一个个读取字符
		ch=in.get();
		while (ch!=' '&&ch!='\n')
		{
			buff[i++] = ch;
			if (i == N - 1)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}

			//in >> ch;
			ch=in.get();
		}

		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}
}