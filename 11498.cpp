#include <iostream>
using namespace std;

int main() {
	int K, X, Y, x, y;
	while (true) {
		cin >> K;
		if (K == 0) {
			break;
		}
		cin >> X >> Y;
		for (int u = 0; u < K; u++) {
			cin >> x >> y;
			if (x < X) {
				if (y < Y) {
					cout << "SO" << endl;
				} else if (y > Y) {
					cout << "NO" << endl;
				} else {
					cout << "divisa" << endl;
				}
			} else if (x > X) {
				if (y < Y) {
					cout << "SE" << endl;
				} else if (y > Y) {
					cout << "NE" << endl;
				} else {
					cout << "divisa" << endl;
				}
			} else {
				cout << "divisa" << endl;
			}
		}
	}
	return 0;
}
