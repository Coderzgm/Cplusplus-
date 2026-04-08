template<typename T>
class Stack
{
private:
    T* _a;       // T 类型数组
    int _top;
public:
    // 构造
    Stack()
    {
        _a = new T[10];
        _top = 0;
    }

    // 入栈
    void push(const T& x)
    {
        _a[_top++] = x;
    }

    // 获取栈顶
    T top()
    {
        return _a[_top - 1];
    }
};

int main()
{
    Stack<int> st1;     // int栈
    st1.push(10);

    Stack<double> st2;  // double栈
    st2.push(3.14);

    return 0;
}

//交换函数示例
#include <iostream>
using namespace std;

// 函数模板
template <typename T>
void Swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    // int
    int a = 10, b = 20;
    Swap(a, b);

    // double
    double c = 1.1, d = 2.2;
    Swap(c, d);

    // char
    char e = 'a', f = 'b';
    Swap(e, f);

    return 0;
}