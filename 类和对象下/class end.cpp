#include<iostream>
using namespace std;

class Data
{
    public:
    //列表定义，成员初始化列表
    Data(int& xx, int year,int month,int day)
        :_year(year)
        ,_month(month)
        ,_day(day)
		
    {
        
    }
    void Print()const
    {
        cout << _year << "-" << _month << "-" << _day << endl;
	}
    private:
    //C++11
    //声明，缺省值->初始化列表用的
    int _year=1;
    int _month=1;
	int _day=1;
};

class A
{
private:
    int _a2 = 1;
    int _a1 = 2;
public:
    // 构造函数explicit就不再⽀持隐式类型转换
    // explicit A(int a1)
    A(int a1)
        :_a1(a1)
    {
    }
    //explicit A(int a1, int a2)
    A(int a1, int a2)
        :_a1(a1)
        , _a2(a2)
    {
    }
    void Print()
    {
        cout << _a1 << " " << _a2 << endl;
    }
    int Get() const
    {
        return _a1 + _a2;
    }
};

//class B
//{
//public:
//    B(const A& a)
//        :_b(a.Get())
//    {
//    }
//private:
//    int _b = 0;
//};

//int main()
//{
//    // 1构造⼀个A的临时对象，再⽤这个临时对象拷⻉构造aa3
//    // 编译器遇到连续构造+拷⻉构造->优化为直接构造
//    A aa1(1);
//    aa1.Print();
//
//    //隐式类型转换
//    A aa2 = 2;
//    aa2.Print();
//
//    A& raa1 = aa2;
//    //这里2传给引用，中间产生临时变量->具有常性权限放大，所以要用const限制
//    const A& raa2 = 2;
//
//    // C++11之后才⽀持多参数转化
//    A aa3 = { 2,2 };
//    // aa3隐式类型转换为b对象
//    // 原理跟上⾯类似
//    B b = aa3;
//    const B& rb = aa3;
//
//    return 0;
//}


struct NoDefault {
    explicit NoDefault(int v) : value(v) {}
    int value;
};

class Example {
public:
    // 这里的 Example(...) 是构造函数，紧随其后的 :ref(r), cst(c), nd(v) 是初始化列表
    Example(int& r, int c, int v)
        : ref(r), cst(c), nd(v)
    {
        // 不能在这里做绑定或赋值来代替初始化：
        // ref = r;    // 这是给引用所指对象赋值，不是绑定引用
        // cst = c;    // 错误：不能给 const 赋值
        // nd = NoDefault(v); // 如果 NoDefault 没有默认构造，会编译失败
    }

    void Print() const { std::cout << ref << " " << cst << " " << nd.value << std::endl; }

private:
    int& ref;         // 引用成员，必须在初始化列表中绑定
    const int cst;    // const 成员，必须在初始化列表中初始化
    NoDefault nd;     // 无默认构造的类类型成员，必须在初始化列表中初始化
};

int main() {
    int x = 5;
    Example e(x, 10, 20);
    e.Print(); // 输出: 5 10 20
    return 0;
}

// 前置声明，都则A的友元函数声明编译器不认识B
class B;
class A
{
    // 友元函数声明，编译器不认识B，所以要前置声明
	friend void func(const A& aa, const B& bb);
private:
    int _a1 = 1;
    int _a2 = 2;
};
class B
{
    // 友元声明
    friend void func(const A& aa, const B& bb);
private:
    int _b1 = 3;
    int _b2 = 4;
};
void func(const A& aa, const B& bb)
{
    cout << aa._a1 << endl;
    cout << bb._b1 << endl;
}
int main()
{
    A aa;
    B bb;
    func(aa, bb);
    return 0;
}