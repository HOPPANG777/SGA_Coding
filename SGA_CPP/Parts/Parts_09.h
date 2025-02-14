#pragma once

//STL(Standard Template Library)
/*
컨테이너(Container)
	list, vector, map, deque, multimap, set

반복자(Iterator)
	begin	- 시작위치
	end		- 끝 위치

알고리즘(Algorithm)

함수자(Functor)
*/

template <typename T>
class IteratorWrapper
{
public:
	IteratorWrapper(T* arr, size_t size) : size(size), arr(arr) {}

public:
	T* begin() { return arr; }
	T* end() { return arr + size; }

private:
	size_t size = 0;
	T* arr = nullptr;
};

class Parts_09 
{
public:
	Parts_09();

private:
	void Array();
	void Vector();
	void List();
	void Map();
	void Set();
	void Iterator();
	void Algorithm();

public:
	bool IsUniqueStr(const string& str);
};
