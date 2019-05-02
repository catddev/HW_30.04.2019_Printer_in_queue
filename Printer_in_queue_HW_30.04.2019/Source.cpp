#include"Printer.h"
#include<ctime>

int main() {

	srand(time(NULL));
	Printer tmp;
	Queue<Printer> q;
	double sum = 0;
	double total = 0;
	int n = 6;

	for (int i = 0; i < n; i++) {
		tmp(to_string(i + 1), 0, 0);
		q.push(tmp);
	}

	cout << "Before printing in queue:" << endl;
	q.print();
	cout << endl;
	int size = q.size();//saving the initial size

	cout << "AFTER PRINTING:" << endl;
	//now printing process
	while (!q.empty()) {

		int t = rand() % 20 + 10;
		q.front()(t);//counting serving time for this printer
		
		sum += q.front().getWait();//counting waiting time for this printer
		q.front() += sum; //changing waiting time

		cout << q.front() << endl;//printing
		sum += q.front().getServe();//add time of the last printing process
		total += q.front().getWait();//counter for waiting times of all printer in queue
		q.pop();//delete from queue
	}
	cout << "Average waiting time in the queue is: " << total << "/" << size << "=" << total / size << " seconds" << endl << endl;

	system("pause");
	return 0;
}