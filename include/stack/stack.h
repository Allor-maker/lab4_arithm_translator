#pragma once

#include <iostream>

template <template<typename, typename... > class T_cont, class T>

class Stack
{
	T_cont<T> data;
public:
	Stack(const T_cont<T>& container)
	{
		data = container;
	}
	void push(const T& elem)
	{
		data.push_back(elem);
	}
	void pop()
	{
		if (empty() == true) throw 0;
		data.pop_back();
	}
	T& top()
	{
		return data.back();
	}
	void clear()
	{
		data.clear();
	}
	size_t size() const
	{
		return data.size();
	}
	bool empty() const
	{
		return data.empty();
	}
};