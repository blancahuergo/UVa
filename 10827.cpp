#include <iostream>
using namespace std;

int main() {
	int cases, N, maxSum, curSum;
	cin >> cases;
	while(cases--) {
		cin >> N;
		int DP[2*N][2*N], matrix[N][N];
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				cin >> matrix[i][j];
			}
		}
		DP[0][0] = matrix[0][0];
		for (int j = 1; j < 2*N; j++) {
			DP[0][j] = DP[0][j-1] + matrix[0][j%N];
		}
		for (int i = 1; i < 2*N; i++) {
			DP[i][0] = DP[i-1][0] + matrix[i%N][0];
			for (int j = 1; j < 2*N; j++) {
				DP[i][j] = DP[i-1][j] + DP[i][j-1] + matrix[i%N][j%N] - DP[i-1][j-1];
			}
		}
		maxSum = 75*75*-100;
		for (int x1 = 0; x1 < 2*N; x1++) {
			for (int x2 = x1; x2 < min(2*N, x1+N); x2++) {
				for (int y1 = 0; y1 < 2*N; y1++) {
					for (int y2 = y1; y2 < min(y1+N, 2*N); y2++) {
						if (x1 == 0) {
							if (y1 == 0) curSum = DP[x2][y2];
							else curSum = DP[x2][y2] - DP[x2][y1-1];
						} else if (y1 == 0) curSum = DP[x2][y2] - DP[x1-1][y2];
						else curSum = DP[x2][y2] - DP[x2][y1-1] - DP[x1-1][y2] + DP[x1-1][y1-1];
						maxSum = max(maxSum, curSum);
					}
				}
			}
		}
		cout << maxSum << endl;
	}
	return 0;
}
