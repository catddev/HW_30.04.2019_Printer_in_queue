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

Printer Printer::operator+=(Printer obj)
{
	wait = obj.wait + obj.serve;
	return *this;
}

int Printer::getWait()
{
	return wait;
}

ostream & operator<<(ostream & os, Printer p)
{
	os << p.name << "	waiting time: " << p.wait << "	serving time: " << p.serve << endl;
	return os;
}
