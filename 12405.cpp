#include <iostream>
using namespace std;

int main() {
	int T, N, ans, cur_points;
	string field;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		cin >> field;
		ans = 0;
		int c = 0;
		while(c < N) {
			if (field[c] == '.') {
				ans++;
				c += 3;
			} else {
				c++;
			}
		}
		cout << "Case " << t << ": " << ans << endl;
	}
	return 0;
}
