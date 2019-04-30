#include"Printer.h"

int main() {

	Printer p[6];
	Queue<Printer> q;

	for (int i = 0; i < 6; i++)
		p[i](to_string(i), 0, 10);






	system("pause");
	return 0;
}