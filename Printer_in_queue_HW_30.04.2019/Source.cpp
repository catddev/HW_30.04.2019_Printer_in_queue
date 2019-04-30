#include"Printer.h"
#include<ctime>

int main() {

	srand(time(NULL));
	Printer p[6];
	Queue<Printer> q;
	double sum = 0;

	for (int i = 0; i < 6; i++) {
		int t = rand() % 20 + 10;
		p[i](to_string(i + 1), 0, t);
	}

	for (int i = 0; i < 6; i++)
		q.push(p[i]);

	q.print();
	cout << endl;
	int n = q.size();

	while (!q.empty()) {
		q.front() += sum; //changing waiting time
		cout << q.front() << endl;
		sum += q.front().getServe();
		q.pop();
	}
	cout << "Average waiting time in a queue is: " << sum / n << " seconds" << endl << endl;

	system("pause");
	return 0;
}