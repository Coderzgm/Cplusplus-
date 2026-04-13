#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<map>
#include<list>
using namespace std;
void TestPushBack()
{
	// reverse 反转  逆置
	// reserve 保留、预留
	string s;
	// 提前开空间，避免扩容，提高效率
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "capacity changed: " << sz << '\n';

	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}
void test_string5()
{
	string s("hello world");
	s.push_back(' ');
	s.push_back('x');
	s.append("yyyyyy");

	cout << s << endl;

	s += ' ';
	s += "33333333333";
	cout << s << endl;

	s.insert(0, "hello bit ");
	cout << s << endl;

	s.insert(10, "zzzz");
	cout << s << endl;

	s.insert(0, "p");
	cout << s << endl;

	char ch = 't';
	s.insert(0, 1, ch);
	s.insert(s.begin(), ch);

	cout << s << endl;
}

void test_string6()
{
	string s("hello world");
	s.erase(6, 1);
	cout << s << endl;

	// 头删
	s.erase(0, 1);
	cout << s << endl;

	s.erase(s.begin());
	cout << s << endl;

	// 尾删
	s.erase(--s.end());
	cout << s << endl;

	s.erase(s.size() - 1);
	cout << s << endl;

	string ss("hello world");
	ss.erase(6);
	cout << ss << endl;

	string sss("hello world hello bit");
	size_t pos = sss.find(' ');
	while (pos != string::npos)
	{
		sss.replace(pos, 1, "%%");
		pos = sss.find(' ', pos + 2);
	}
	cout << sss << endl;

	// 原写法
	string tmp;
	for (auto& ch : sss) {
		if (ch == ' ') tmp += "%%";
		else tmp += ch;
	}
	cout << tmp << endl;
	//sss = tmp;
	sss.swap(tmp);
	cout << sss << endl;

	// 等价展开（语义相同）
	//string tmp2;
	//for (auto it = sss.begin(); it != sss.end(); ++it) {
	//	char ch = *it;
	//	if (ch == ' ') tmp2 += "%%";
	//	else tmp2 += ch;
	//}

	string str;
	cin >> str;
	FILE* pf = fopen(str.c_str(), "r");
	char ch = fgetc(pf);
	while (ch != EOF)
	{
		cout << ch;
		ch = fgetc(pf);
	}
	fclose(pf);
	//sss.replace(5, 1, "%%");
	//cout << sss << endl;

}

void test_string7()
{
	string s("test.cpp.zip");
	size_t pos = s.rfind('.');
	string suffix = s.substr(pos);
	cout << suffix << endl;
}

//演示 find_first_of / find_first_not_of / find_last_of / find_last_not_of / find / rfind 的典型用法
void TestFindOfVariants()
{
	string s = "  ,hello,, world;this:is;a-test  ";
	cout << "原串: [" << s << "]\n";

	// 1) 找到第一个属于分隔符集合的字符位置
	string delims = " ,;:-";
	size_t pos = s.find_first_of(delims);
	if (pos != string::npos)
		cout << "第一个分隔符位置: " << pos << " ('" << s[pos] << "')\n";
	else
		cout << "未找到任何分隔符\n";

	// 2) 找到第一个不属于分隔符集合的位置（即第一个有效字符）
	size_t firstTokenStart = s.find_first_not_of(delims);
	if (firstTokenStart != string::npos)
		cout << "第一个非分隔符位置: " << firstTokenStart << " ('" << s[firstTokenStart] << "')\n";

	// 3) 找到最后一个属于分隔符集合的位置
	size_t lastDelim = s.find_last_of(delims);
	if (lastDelim != string::npos)
		cout << "最后一个分隔符位置: " << lastDelim << " ('" << s[lastDelim] << "')\n";

	// 4) 找到最后一个非分隔符位置
	size_t lastNotDelim = s.find_last_not_of(delims);
	if (lastNotDelim != string::npos)
		cout << "最后一个非分隔符位置: " << lastNotDelim << " ('" << s[lastNotDelim] << "')\n";

	// 5) 用 find + find_first_of 做简单分词（按多个分隔符分割）
	cout << "\n按多个分隔符分词（忽略空项）:\n";
	size_t start = s.find_first_not_of(delims, 0);
	while (start != string::npos) {
		size_t end = s.find_first_of(delims, start);
		string token = (end == string::npos) ? s.substr(start) : s.substr(start, end - start);
		cout << "[" << token << "]\n";
		start = s.find_first_not_of(delims, (end == string::npos) ? string::npos : end);
	}

	// 6) find / rfind 用法：查找子串或字符
	string sub = "world";
	size_t p = s.find(sub);
	if (p != string::npos) cout << "\n子串 '" << sub << "' 在位置: " << p << '\n';
	else cout << "\n未找到子串 '" << sub << "'\n";

	// rfind 从尾部开始找（仍返回从头开始的索引）
	size_t rp = s.rfind(':'); // 查找最后一个冒号
	if (rp != string::npos) cout << "最后一个 ':' 在位置: " << rp << '\n';

	// 7) find_first_of 的重载：可以传入 C 风格字符串与起始位置
	pos = s.find_first_of("aeiou", 0); // 查找首个元音字母
	if (pos != string::npos) cout << "\n首个元音字母位置: " << pos << " ('" << s[pos] << "')\n";
}

#include"string.h"

namespace bit
{
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
		cout << endl;

		string::iterator it = s2.begin();
		while (it != s2.end())
		{
			//*it += 2;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_string2()
	{
		string s1("hello world");
		s1 += 'x';
		s1 += '#';
		cout << s1.c_str() << endl;

		s1 += "hello bit";
		cout << s1.c_str() << endl;

		s1.insert(5, '$');
		cout << s1.c_str() << endl;

		s1.insert(0, '$');
		cout << s1.c_str() << endl;

		string s2("hello world");
		cout << s2.c_str() << endl;

		s2.insert(5, "$$$");
		cout << s2.c_str() << endl;

		s2.insert(0, "$$$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
		cout << s2.c_str() << endl;
	}

	void test_string3()
	{
		string s1("hello world");
		s1.erase(6, 100);
		cout << s1.c_str() << endl;

		string s2("hello world");
		s2.erase(6);
		cout << s2.c_str() << endl;

		string s3("hello world");
		s3.erase(6, 3);
		cout << s3.c_str() << endl;
	}


}


int main()
{
	bit::test_string3();
	return 0;
}