#pragma once
#include <iostream>
#include <cstddef> // size_t
using namespace std;

// 1. 定义双向链表节点结构
template <typename T>
struct ListNode {
    T _data;          // 存储的数据
    ListNode* _prev;  // 指向前一个节点的指针
    ListNode* _next;  // 指向后一个节点的指针

    // 节点构造函数：用数据初始化节点，指针初始化为空
    ListNode(const T& data = T())
        : _data(data)
        , _prev(nullptr)
        , _next(nullptr)
    {
    }
};
// 2. 定义迭代器类：封装节点指针，实现双向迭代器
template <typename T, typename Ref, typename Ptr>
struct ListIterator {
    typedef ListNode<T> Node;
    typedef ListIterator<T, Ref, Ptr> Self;

    Node* _node; // 迭代器封装的节点指针

    // 迭代器构造函数：用节点指针初始化
    ListIterator(Node* node = nullptr)
        : _node(node)
    {
    }

    // 重载 *：解引用，获取节点的数据（Ref 是引用类型，如 T&）
    Ref operator*() {
        return _node->_data;
    }

    // 重载 ->：获取节点数据的地址（Ptr 是指针类型，如 T*）
    Ptr operator->() {
        return &_node->_data;
    }

    // 重载前置 ++：指向后一个节点，返回 *this
    Self& operator++() {
        _node = _node->_next;
        return *this;
    }

    // 重载后置 ++：指向后一个节点，返回递增前的迭代器
    Self operator++(int) {
        Self tmp(*this); // 保存当前迭代器
        _node = _node->_next;
        return tmp;
    }

    // 重载前置 --：指向前一个节点，返回 *this
    Self& operator--() {
        _node = _node->_prev;
        return *this;
    }

    // 重载后置 --：指向前一个节点，返回递减前的迭代器
    Self operator--(int) {
        Self tmp(*this);
        _node = _node->_prev;
        return tmp;
    }

    // 重载 ==：判断两个迭代器是否相等（节点指针相同）
    bool operator==(const Self& it) const {
        return _node == it._node;
    }

    // 重载 !=：判断两个迭代器是否不相等
    bool operator!=(const Self& it) const {
        return _node != it._node;
    }
};
// 3. 定义 list 类：双向循环链表 + 哨兵节点
template <typename T>
class list {
public:
    typedef ListNode<T> Node;
    // 普通迭代器
    typedef ListIterator<T, T&, T*> iterator;
    // const 迭代器（只能读，不能写）
    typedef ListIterator<T, const T&, const T*> const_iterator;

private:
    Node* _head;   // 哨兵节点指针
    size_t _size;  // 有效元素个数

public:
    // ------------------------------
    // 1. 构造/析构函数
    // ------------------------------

    // 默认构造函数：初始化哨兵节点
    list() {
        _head = new Node(); // 哨兵节点不存储有效数据
        _head->_prev = _head; // 空链表时，prev 和 next 都指向自己
        _head->_next = _head;
        _size = 0;
    }

    // 析构函数：清空所有节点，释放哨兵节点
    ~list() {
        clear(); // 先清空所有有效节点
        delete _head; // 再释放哨兵节点
        _head = nullptr;
        _size = 0;
    }

    // ------------------------------
    // 2. 迭代器接口
    // ------------------------------

    // begin()：返回首节点的迭代器（哨兵节点的 next）
    iterator begin() {
        return iterator(_head->_next);
    }

    const_iterator begin() const {
        return const_iterator(_head->_next);
    }

    // end()：返回哨兵节点的迭代器（尾节点的 next 是哨兵节点）
    iterator end() {
        return iterator(_head);
    }

    const_iterator end() const {
        return const_iterator(_head);
    }

    // ------------------------------
    // 3. 容量接口
    // ------------------------------

    size_t size() const {
        return _size;
    }

    bool empty() const {
        return _size == 0;
    }

    // ------------------------------
    // 4. 增删接口（核心！）
    // ------------------------------

    // insert：在指定位置 pos 前插入元素 data，返回新元素的迭代器
    iterator insert(iterator pos, const T& data) {
        Node* cur = pos._node; // 当前节点
        Node* prev = cur->_prev; // 当前节点的前一个节点
        Node* new_node = new Node(data); // 新节点

        // 修改指针：把新节点插入到 prev 和 cur 之间
        prev->_next = new_node;
        new_node->_prev = prev;
        new_node->_next = cur;
        cur->_prev = new_node;

        _size++; // 有效元素个数+1
        return iterator(new_node); // 返回新元素的迭代器
    }

    // erase：删除指定位置 pos 的元素，返回下一个元素的迭代器
    iterator erase(iterator pos) {
        Node* cur = pos._node; // 当前要删除的节点
        Node* prev = cur->_prev; // 前一个节点
        Node* next = cur->_next; // 后一个节点

        // 修改指针：把 cur 从链表中移除
        prev->_next = next;
        next->_prev = prev;

        delete cur; // 释放当前节点
        _size--; // 有效元素个数-1
        return iterator(next); // 返回下一个元素的迭代器
    }

    // push_back：尾插（在哨兵节点前插入，即链表末尾）
    void push_back(const T& data) {
        insert(end(), data);
    }

    // push_front：首插（在首节点前插入）
    void push_front(const T& data) {
        insert(begin(), data);
    }

    // pop_back：尾删（删除尾节点）
    void pop_back() {
        erase(--end());
    }

    // pop_front：首删（删除首节点）
    void pop_front() {
        erase(begin());
    }

    // clear：清空所有有效节点（不释放哨兵节点）
    void clear() {
        iterator it = begin();
        while (it != end()) {
            it = erase(it); // 删除当前节点，获取下一个迭代器
        }
    }

    // ------------------------------
    // 5. 拷贝构造/赋值（深拷贝）
    // ------------------------------

    // 拷贝构造函数：深拷贝另一个 list
    list(const list<T>& l) {
        // 1. 先初始化自己的哨兵节点
        _head = new Node();
        _head->_prev = _head;
        _head->_next = _head;
        _size = 0;

        // 2. 把 l 的所有元素尾插到自己的链表中
        for (const auto& x : l) {
            push_back(x);
        }
    }

    // 赋值运算符重载：深拷贝另一个 list
    list<T>& operator=(const list<T>& l) {
        if (this == &l) return *this; // 检查自赋值

        // 1. 先清空自己的所有节点
        clear();

        // 2. 把 l 的所有元素尾插到自己的链表中
        for (const auto& x : l) {
            push_back(x);
        }

        return *this;
    }
};