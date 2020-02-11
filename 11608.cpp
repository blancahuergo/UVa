#include <iostream>
using namespace std;

int main() {
	int probs;
	int cases = 1;
	while (true) {
		cin >> probs;
		if (probs < 0) {
			break;
		}
		int created[12];
		int required[12];
		for (int i = 0; i < 12; i++) {
			cin >> created[i];
		}
		for (int i = 0; i < 12; i++) {
			cin >> required[i];
		}
		cout << "Case " << cases << ":" << endl;
		for (int i = 0; i < 12; i++) {
			if (required[i] <= probs) {
				cout << "No problem! :D" << endl;
				probs -= required[i];
			} else {
				cout << "No problem. :(" << endl;
			}
			probs += created[i];
		}
		cases++;
	}
	return 0;
}
