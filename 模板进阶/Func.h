#pragma once
#include<iostream>
using namespace std;
//模板的声明和定义不能分离
//解决方案：
//1.cpp显示实例化模板 不推荐
//2.直接在.h定义模板，用的地方直接定义，直接实例化 推荐
template<class T>
T Add(const T& left, const T& right);

void func(const int& left, const int& right);