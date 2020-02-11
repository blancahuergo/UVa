#include <iostream>
using namespace std;

int main() {
	int N;
	int lumbs[10];
	bool correct;
	cin >> N;
	cout << "Lumberjacks:" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> lumbs[j];
		}
		correct = true;
		if (lumbs[0] > lumbs[1]) {
			for (int j = 1; j < 10; j++) {
				if (lumbs[j-1] < lumbs[j]) {
					correct = false;
					break;
				}
			}
		} else if (lumbs[0] < lumbs[1]) {
			for (int j = 1; j < 10; j++) {
				if (lumbs[j-1] > lumbs[j]) {
					correct = false;
					break;
				}
			}
		} else {
			int j = 1;
			while (lumbs[j] == lumbs[j-1]) {
				j++;
				if (j == 10) {
					break;
				}
			}
			if (j < 10) {
				if (lumbs[j] < lumbs[j-1]) {
					for (int k = j; k < 10; k++) {
						if (lumbs[k] > lumbs[k-1]) {
							correct = false;
							break;
						}
					}
				} else {
					for (int k = j; k < 10; k++) {
						if (lumbs[k] < lumbs[k-1]) {
							correct = false;
							break;
						}
					}
				}
			}
		}
		if (correct) {
			cout << "Ordered\n";
		} else {
			cout << "Unordered\n";
		}
	}
	return 0;
}
