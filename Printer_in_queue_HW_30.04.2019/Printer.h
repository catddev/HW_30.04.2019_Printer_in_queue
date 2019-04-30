#pragma once
#include"Queue.h"
using namespace std;

//В этом заданий нужно будет использовать ранее реализованный Вами класс очередь и создать класс принтер.
//У каждого принтера есть название, время ожидания и время обслуживания.
//По мере ожидания в очереди у каждого принтера время ожидания увеличивается.
//Нужно найти среднее время ожидания очереди.

class Printer {
private:
	string name;
	int wait;
	int serve;
public:
	Printer();
	Printer(string name, int wait, int serve);
	
	void operator()(string name, int wait, int serve);
	Printer operator++(int v);
	friend ostream& operator<<(ostream& os, Printer p);
};
ostream& operator<<(ostream& os, Printer p);