#pragma once
#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Queue {
private:
	T* ptr;
	int cur_size;
	int buf_size;
public:
	Queue();
	Queue(const Queue<T>& obj);
	~Queue();

	void push(T el);
	void pop();
	int size();
	T& back();
	T& front();
	bool empty();
	void print();
	Queue<T> operator=(const Queue<T>& obj);
};

template<typename T>
inline Queue<T>::Queue()
{
	ptr = 0;
	cur_size = 0;
	buf_size = 0;
}

template<typename T>
inline Queue<T>::Queue(const Queue<T>& obj)
{
	cur_size = obj.cur_size;
	buf_size = obj.buf_size;
	ptr = new T[buf_size];
	for (int i = 0; i < cur_size; i++)
		ptr[i] = obj.ptr[i];
}

template<typename T>
inline Queue<T>::~Queue()
{
	delete[] ptr;
}

template<typename T>
inline void Queue<T>::push(T el)
{
	if (buf_size == 0) {
		buf_size = 4;
		ptr = new T[buf_size];
	}
	else if (cur_size == buf_size) {
		buf_size *= 2;
		T*tmp = new T[buf_size];
		for (int i = 0; i < cur_size; i++)
			tmp[i] = ptr[i];
		delete[] ptr;
		ptr = tmp;
	}
	ptr[cur_size++] = el;
}

template<typename T>
inline void Queue<T>::pop()
{
	for (int i = 1; i < cur_size; i++)
		ptr[i - 1] = ptr[i];
	cur_size--;
}

template<typename T>
inline int Queue<T>::size()
{
	return cur_size;
}

template<typename T>
inline T & Queue<T>::back()
{
	return ptr[cur_size - 1];
}

template<typename T>
inline T & Queue<T>::front()
{
	return ptr[0];
}

template<typename T>
inline bool Queue<T>::empty()
{
	return (cur_size == 0);
}

template<typename T>
inline void Queue<T>::print()
{
	for (int i = 0; i < cur_size; i++)
		cout << ptr[i] << endl;
	cout << endl;
}

template<typename T>
inline Queue<T> Queue<T>::operator=(const Queue<T>& obj)
{
	cur_size = obj.cur_size;
	buf_size = obj.buf_size;
	ptr = new T[buf_size];
	for (int i = 0; i < cur_size; i++)
		ptr[i] = obj.ptr[i];

	return *this;
}

