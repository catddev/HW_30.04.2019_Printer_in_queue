#include"Printer.h"

int main() {

	Printer p[6];
	Queue<Printer> q;
	double sum = 0;

	for (int i = 0; i < 6; i++) {
		int t = rand() % 20 + 10;
		p[i](to_string(i + 1), 0, t);
	}

	for (int i = 0; i < 6; i++) {
		q.push(p[i]);
		if(i!=5)
			p[i + 1]+=p[i];
	}
	q.print();
	int n = q.size();

	while (!q.empty()) {
		sum += q.front().getWait();
		q.pop();
	}
	sum /= n;
	cout << "Average waiting time in a queue is: " << sum << " seconds" << endl << endl;

	system("pause");
	return 0;
}