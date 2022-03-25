#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int C;
	cin >> C;

	for (int i = 0; i < C; i++) {
		int N, sum = 0, avg, good = 0;
		cin >> N;
		int* score = new int[N];
		for (int j = 0; j < N; j++) {
			cin >> score[j];
			sum += score[j];
		}
		avg = sum / N;
		
		for (int j = 0; j < N; j++) {
			if (avg < score[j])
				good++;
		}

		double per = ((double)good / (double)N) * 100;
		cout << fixed << setprecision(3);
		cout << per << "%" << endl;

		delete[] score;
	}

	return 0;
}