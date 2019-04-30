#include"Printer.h"
#include<ctime>

int main() {

	srand(time(NULL));
	Printer p[6];
	Queue<Printer> q;
	double sum = 0;
	double total = 0;

	for (int i = 0; i < 6; i++) {
		p[i](to_string(i + 1), 0, 0);
		q.push(p[i]);
	}

	cout << "Before getting into the queue:" << endl;
	q.print();
	cout << endl;
	int n = q.size();

	cout << "AFTER PRINTING:" << endl;
	//now printing process
	while (!q.empty()) {

		int t = rand() % 20 + 10;
		q.front()(t);//counting serving time for this printer
		
		sum += q.front().getWait();
		q.front() += sum; //changing waiting time

		cout << q.front() << endl;//printing
		sum += q.front().getServe();
		total += q.front().getWait();
		q.pop();
	}
	cout << "Average waiting time in the queue is: " << total / n << " seconds" << endl << endl;

	system("pause");
	return 0;
}