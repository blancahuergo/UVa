#include <iostream>
using namespace std;

int main() {
	int cases, W, y1, y2, diff;
	bool correct;
	cin >> cases;
	for (int y = 0; y < cases; y++) {
		cin >> W;
		cin >> y1 >> y2;
		diff = y2 - y1;
		correct = true;
		for (int h = 1; h < W; h++) {
			cin >> y1 >> y2;
			if (y2 - y1 != diff) {
				correct = false;
			}
		}
		if (correct) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
		if (y < cases-1) {
			cout << "\n";
		}
	}
	return 0;
}
