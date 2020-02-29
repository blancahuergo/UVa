#include <iostream>
using namespace std;

int main() {
	int cases, A, B, C;
	long long maxSum, sectionMaxSum, curSum, curVal;
	cin >> cases;
	while(cases--) {
		cin >> A >> B >> C;
		// FILL CUBE
		long long cube[A][B][C];
		for (int i = 0; i < A; i++) {
			for (int j = 0; j < B; j++) {
				for (int k = 0; k < C; k++) {
					cin >> cube[i][j][k];
				}
			}
		}
		// FILL DP (LAYERS ARE INDEPENDENT) -> 2D Range Sum
		long long DP[A][B][C];
		for (int l = 0; l < C; l++) {
			DP[0][0][l] = cube[0][0][l];
			for (int j = 1; j < B; j++) {
				DP[0][j][l] = DP[0][j-1][l] + cube[0][j][l];
			}
			for (int i = 1; i < A; i++) {
				DP[i][0][l] = DP[i-1][0][l] + cube[i][0][l];
				for (int j = 1; j < B; j++) {
					DP[i][j][l] = DP[i-1][j][l] + DP[i][j-1][l] + cube[i][j][l] - DP[i-1][j-1][l];
				}
			}
		}
		// FIND MAX SUM -> 1D Range Sum
		maxSum = -9000000000000000000;
		for (int x1 = 0; x1 < A; x1++) {
			for (int x2 = x1; x2 < A; x2++) {
				for (int y1 = 0; y1 < B; y1++) {
					for (int y2 = y1; y2 < B; y2++) {
						sectionMaxSum = -9000000000000000000;
						curSum = 0L;
						for (int l = 0; l < C; l++) {
							if (x1 == 0) {
								if (y1 == 0) curVal = DP[x2][y2][l];
								else curVal = DP[x2][y2][l] - DP[x2][y1-1][l];
							} else if (y1 == 0) curVal = DP[x2][y2][l] - DP[x1-1][y2][l];
							else curVal = DP[x2][y2][l] - DP[x2][y1-1][l] - DP[x1-1][y2][l] + DP[x1-1][y1-1][l];
							curSum += curVal;
							if (curSum > sectionMaxSum) sectionMaxSum = curSum;
							if (curSum < 0) curSum = 0L;
						}
						if (sectionMaxSum > maxSum) maxSum = sectionMaxSum;
					}
				}
			}
		}
		cout << maxSum << endl;
		if (cases) cout << "\n";
	}
	return 0;
}
