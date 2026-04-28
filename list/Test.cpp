#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
using namespace std;

// 测试代码
int main() {
    // 1. 测试构造、push_back、迭代器遍历
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    cout << "push_back 后：";
    for (auto x : l) cout << x << " "; // 输出：1 2 3
    cout << endl;

    // 2. 测试 push_front
    l.push_front(0);
    cout << "push_front 后：";
    for (auto x : l) cout << x << " "; // 输出：0 1 2 3
    cout << endl;

    // 3. 测试 insert
    auto it = l.begin();
    ++it; // 指向 1
    l.insert(it, 100); // 在 1 前插入 100
    cout << "insert 后：";
    for (auto x : l) cout << x << " "; // 输出：0 100 1 2 3
    cout << endl;

    // 4. 测试 erase
    it = l.begin();
    ++it; // 指向 100
    l.erase(it); // 删除 100
    cout << "erase 后：";
    for (auto x : l) cout << x << " "; // 输出：0 1 2 3
    cout << endl;

    // 5. 测试 pop_back、pop_front
    l.pop_back();
    l.pop_front();
    cout << "pop 后：";
    for (auto x : l) cout << x << " "; // 输出：1 2
    cout << endl;

    // 6. 测试 size、empty
    cout << "size：" << l.size() << endl; // 输出：2
    cout << "empty：" << l.empty() << endl; // 输出：0

    // 7. 测试拷贝构造
    list<int> l2 = l;
    cout << "拷贝构造 l2：";
    for (auto x : l2) cout << x << " "; // 输出：1 2
    cout << endl;

    // 8. 测试 clear
    l.clear();
    cout << "clear 后 size：" << l.size() << endl; // 输出：0

    return 0;
}