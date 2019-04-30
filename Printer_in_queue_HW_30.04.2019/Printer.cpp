#include"Printer.h"

Printer::Printer()
{
	name = "";
	wait = 0;
	serve = 0;
}

Printer::Printer(string name, int wait, int serve)
{
	this->name = name;
	this->wait = wait;
	this->serve = serve;
}

void Printer::operator()(string name, int wait, int serve)
{
	this->name = name;
	this->wait = wait;
	this->serve = serve;
}

Printer Printer::operator+=(int value)
{
	wait += value;
	return *this;
}

int Printer::getServe()
{
	return serve;
}

ostream & operator<<(ostream & os, Printer p)
{
	os << p.name << "	waiting time: "<< setw(3) << p.wait << "	serving time: " << p.serve << endl;
	return os;
}
