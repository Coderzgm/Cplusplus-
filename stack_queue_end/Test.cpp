#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

//放这里展开
#include"Stack.h"
#include"Queue.h"
#include"PriorityQueue.h"
//int main()
//{
//	//bit::stack<int, vector<int>> st;
//	//bit::stack<int, list<int>> st;
//	bit::stack<int, vector<int>> st;
//
//	// 类模板实例化时，按需实例化，使用哪些成员函数就实例化哪些，不会全实例化
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//
//	cout << st.top() << endl;
//	st.pop();
//
//	//bit::queue<int, list<int>> q;
//	bit::queue<int> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//
//	cout << q.front() << endl;
//	q.pop();
//
//	return 0;
//}

void test_op1()
{
	srand(time(0));
	const int N = 1000000;

	deque<int> dq;
	vector<int> v;

	for (int i = 0; i < N; ++i)
	{
		auto e = rand() + i;
		v.push_back(e);
		dq.push_back(e);
	}

	int begin1 = clock();
	sort(v.begin(), v.end());
	int end1 = clock();

	int begin2 = clock();
	sort(dq.begin(), dq.end());
	int end2 = clock();

	printf("vector:%d\n", end1 - begin1);
	printf("deque:%d\n", end2 - begin2);
}

void test_op2()
{
	srand(time(0));
	const int N = 1000000;

	deque<int> dq1;
	deque<int> dq2;

	for (int i = 0; i < N; ++i)
	{
		auto e = rand() + i;
		dq1.push_back(e);
		dq2.push_back(e);
	}

	int begin1 = clock();
	sort(dq1.begin(), dq1.end());
	int end1 = clock();

	int begin2 = clock();
	// 拷贝到vector
	vector<int> v(dq2.begin(), dq2.end());
	sort(v.begin(), v.end());
	dq2.assign(v.begin(), v.end());
	int end2 = clock();

	printf("deque sort:%d\n", end1 - begin1);
	printf("deque copy vector sort, copy back deque:%d\n", end2 - begin2);
}

//int main()
//{
//	test_op2();
//
//	return 0;
//}

int main()
{
	//priority_queue<int> pq;
	//bit::priority_queue<int, vector<int>, Greater<int>> pq;
	bit::priority_queue<int> pq;
	pq.push(4);
	pq.push(1);
	pq.push(5);
	pq.push(7);
	pq.push(9);
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

	return 0;
}

// 仿函数：本质是一个类，这个类重载operator(),他的对象可以像函数一样使用
//template<class T>
//class Less
//{
//public:
//	bool operator()(const T& x, const T& y)
//	{
//		return x < y;
//	}
//};
//
//template<class T>
//class Greater
//{
//public:
//	bool operator()(const T& x, const T& y)
//	{
//		return x > y;
//	}
//};

// < 升序
// > 降序
//template<class Compare>
//void BubbleSort(int* a, int n, Compare com)
//{
//	for (int j = 0; j < n; j++)
//	{
//		// 单趟
//		int flag = 0;
//		for (int i = 1; i < n - j; i++)
//		{
//			//if (a[i] < a[i - 1])
//			if (com(a[i], a[i - 1]))
//			{
//				swap(a[i - 1], a[i]);
//				flag = 1;
//			}
//		}
//
//		if (flag == 0)
//		{
//			break;
//		}
//	}
//}
//
//int main()
//{
//	Less<int> LessFunc;
//	Greater<int> GreaterFunc;
//	// 函数对象
//	cout << LessFunc(1, 2) << endl;
//	cout << LessFunc.operator()(1, 2) << endl;
//
//	int a[] = { 9,1,2,5,7,4,6,3 };
//	BubbleSort(a, 8, LessFunc);
//	BubbleSort(a, 8, GreaterFunc);
//
//	BubbleSort(a, 8, Less<int>());
//	BubbleSort(a, 8, Greater<int>());
//
//	return 0;
//}