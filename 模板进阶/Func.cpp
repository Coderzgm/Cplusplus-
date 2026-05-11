#include"Func.h"

template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

void func(const int& left, const int& right)
{
	cout<<"void func(const int& left, const int& right)"<<endl;
}

//显示实例化
template
int Add(const int& left, const int& right);

template
double Add(const double& left, const double& right);