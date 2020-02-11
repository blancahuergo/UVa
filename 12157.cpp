#include <iostream>
using namespace std;

int main() {
	int T, N, m, j, cur;
	cin >> T;
	for (int u = 0; u < T; u++) {
		cin >> N;
		m = 0;
		j = 0;
		for (int i = 0; i < N; i++) {
			cin >> cur;
			m += (cur/30 + 1)*10;
			j += (cur/60 + 1)*15;
		}
		if (m < j) {
			cout << "Case " << u+1 << ": Mile " << m << endl;
		} else if (m > j) {
			cout << "Case " << u+1 << ": Juice " << j << endl;
		} else {
			cout << "Case " << u+1 << ": Mile Juice " << m << endl;
		}
	}
	return 0;
}
