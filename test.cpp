#include<iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// 编译报错：error C2652: “Date”: ⾮法的复制构造函数: 第⼀个参数不应是“Date”
//   //Date(Date d)
//	Date(const Date& d)//const用来保护d
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	Date(Date* d)
//	{
//		_year = d->_year;
//		_month = d->_month;
//		_day = d->_day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void Func1(Date d)
//{
//	cout << &d << endl;
//	d.Print();
//}
//// Date Func2()
//Date& Func2()
//{
//	Date tmp(2024, 7, 5);
//	tmp.Print();
//	return tmp;
//}
//
//int main()
//{
//	Date d1(2024, 7, 5);
//	// C++规定⾃定义类型对象进⾏拷⻉⾏为必须调⽤拷⻉构造，
//	// 所以这⾥传值传参要调⽤拷⻉构造
//	// 所以这⾥的d1传值传参给d要调⽤拷⻉构造完成拷⻉，
//	// 传引⽤传参可以较少这⾥的拷⻉
//	Func1(d1);
//	cout << &d1 << endl;
//	// 这⾥可以完成拷⻉，但是不是拷⻉构造，只是⼀个普通的构造
//	Date d2(&d1);
//	d1.Print();
//	d2.Print();
//	//这样写才是拷⻉构造，通过同类型的对象初始化构造，⽽不是指针
//	Date d3(d1);
//	d2.Print();
//	// 也可以这样写，这⾥也是拷⻉构造
//	Date d4 = d1;
//	d2.Print();
//	// Func2返回了⼀个局部对象tmp的引⽤作为返回值
//	// Func2函数结束，tmp对象就销毁了，相当于了⼀个野引⽤
//	Date ret = Func2();
//	ret.Print();
//	return 0;
//}

//深拷贝浅拷贝以及友元函数重载赋值重载
//class String
//{
//public:
//    String(const char* str = "")
//    {
//        _str = new char[strlen(str) + 1];
//        strcpy(_str, str);
//    }
//
//    // 默认拷贝构造 = 浅拷贝！
//    // 只复制 _str 指针的值（地址）
//    String(const String& s)
//        :_str(s._str)
//    {
//    }
//
//    ~String()
//    {
//        delete[] _str;  // 浅拷贝会让两块对象析构时释放同一块空间！
//    }
//
//private:
//    char* _str;
//};
//
//int main()
//{
//    String s1("hello");
//    String s2 = s1;  // 浅拷贝！s1和s2的_str指向同一块内存
//    // 程序结束，析构s2 → 释放内存
//    // 再析构s1 → 重复释放！崩溃！
//}
//
//class String
//{
//public:
//    String(const char* str = "")
//    {
//        _str = new char[strlen(str) + 1];
//        strcpy(_str, str);
//    }
//
//    // 深拷贝：自己开空间 + 拷贝内容
//    String(const String& s)
//    {
//        // 需要对_a指向资源创建同样⼤的资源再拷⻉值！！
//        _str = new char[strlen(s._str) + 1]; // 1. 开新空间
//        strcpy(_str, s._str);                // 2. 拷贝内容
//    }
//
//    ~String()
//    {
//        delete[] _str;
//    }
//
//private:
//    char* _str;
//};

class Date
{
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month);
	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1);
	// 拷贝构造函数
    // d2(d1)
	Date(const Date& d);
	// 赋值运算符重载
    // d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d);
	// 析构函数
	~Date();
	// 日期+=天数
	Date& operator+=(int day);
	// 日期+天数
	Date operator+(int day);
	// 日期-天数
	Date operator-(int day);
	// 日期-=天数
	Date& operator-=(int day);
	// 前置++
	Date& operator++();
	// 后置++
	Date operator++(int);
	// 后置--
	Date operator--(int);
	// 前置--
	Date& operator--();
	// >运算符重载
	bool operator>(const Date& d);
	// ==运算符重载
	bool operator==(const Date& d);
	// >=运算符重载
	bool operator >= (const Date& d);
	// <运算符重载
	bool operator < (const Date& d);
	// <=运算符重载
	bool operator <= (const Date& d);
	// !=运算符重载
	bool operator != (const Date& d);
	// 日期-日期 返回天数
	int operator-(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};