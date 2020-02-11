#include <iostream>
using namespace std;

int main() {
	int T, N, cur, c_max;
	cin >> T;
	for (int u = 0; u < T; u++) {
		cin >> N;
		c_max = 0;
		for (int y = 0; y < N; y++) {
			cin >> cur;
			if (cur > c_max) {
				c_max = cur;
			}
		}
		cout << "Case " << (u+1) << ": " << c_max << endl;
	}
	return 0;
}
