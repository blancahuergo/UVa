#include <iostream>
using namespace std;

int main() {
	int T, N, cur, last, low, high;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cin >> last;
		low = 0;
		high = 0;
		for (int u = 1; u < N; u++) {
			cin >> cur;
			if (cur < last) {
				low++;
			} else if (cur > last) {
				high++;
			}
			last = cur;
		}
		cout << "Case " << (i+1) << ": " << high << " " << low << endl;
	}
	return 0;
}
