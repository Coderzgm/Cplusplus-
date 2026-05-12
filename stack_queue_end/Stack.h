#pragma once
//template<class T>
//class stack
//{
//private:
//	T* a;
//	size_t _top;
//	size_t _capacity;
//};


namespace bit
{
	//Container适配转换出stack
	template<class T, class Container=vector<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		const T& top()
		{
			return _con.back();
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty()const
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}
