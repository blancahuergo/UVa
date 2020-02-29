#include <iostream>
using namespace std;

int main() {
	int N, M, cell, curVal, x1, y1;
	long tot;
	bool notFirst = false;
	while(cin >> N >> M) {
		int DP[N][N];
		cin >> DP[0][0];
		for (int j = 1; j < N; j++) {
			cin >> cell;
			DP[0][j] = DP[0][j-1] + cell;
		}
		for (int i = 1; i < N; i++) {
			cin >> cell;
			DP[i][0] = DP[i-1][0] + cell;
			for (int j = 1; j < N; j++) {
				cin >> cell;
				DP[i][j] = DP[i-1][j]  - DP[i-1][j-1] + DP[i][j-1] + cell;
			}
		}
		if (notFirst) cout << "\n";
		notFirst = true;
		tot = 0L;
		for (int x2 = M-1; x2 < N; x2++) {
			x1 = x2 - M + 1;
			for (int y2 = M-1; y2 < N; y2++) {
				y1 = y2 - M + 1;
				if (x1 == 0) {
					if (y1 == 0) curVal = DP[x2][y2];
					else curVal = DP[x2][y2] - DP[x2][y1-1];
				} else if (y1 == 0) curVal = DP[x2][y2] - DP[x1-1][y2];
				else curVal = DP[x2][y2] - DP[x2][y1-1] - DP[x1-1][y2] + DP[x1-1][y1-1];
				cout << curVal << endl;
				tot += (long) curVal;
			}
		}
		cout << tot << endl;
	}
	return 0;
}
