#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int cases, blocks, a, b, c, d, N, largestArea, curSum;
	cin >> cases;
	while(cases--) {
		cin >> N;
		int matrix[N][N], DP[N][N];
		memset(matrix, 0, sizeof matrix);
		cin >> blocks;
		for (int B = 0; B < blocks; B++) {
			cin >> a >> b >> c >> d;
			a--;
			b--;
			c--;
			d--;
			for (int x = a; x <= c; x++) {
				for (int y = b; y <= d; y++) {
					matrix[x][y] = 1;
				}
			}
		}
		DP[0][0] = matrix[0][0];
		for (int j = 1; j < N; j++) {
			DP[0][j] = DP[0][j-1] + matrix[0][j];
		}
		for (int i = 1; i < N; i++) {
			DP[i][0] = DP[i-1][0] + matrix[i][0];
			for (int j = 1; j < N; j++) {
				DP[i][j] = DP[i-1][j] + DP[i][j-1] - DP[i-1][j-1] + matrix[i][j];
			}
		}
		largestArea = 0;
		for (int x1 = 0; x1 < N; x1++) {
			for (int x2 = x1; x2 < N; x2++) {
				for (int y1 = 0; y1 < N; y1++) {
					for (int y2 = y1; y2 < N; y2++) {
						if (x1 == 0) {
							if (y1 == 0) curSum = DP[x2][y2];
							else curSum = DP[x2][y2] - DP[x2][y1-1];
						} else if (y1 == 0) curSum = DP[x2][y2] - DP[x1-1][y2];
						else curSum = DP[x2][y2] - DP[x2][y1-1] - DP[x1-1][y2] + DP[x1-1][y1-1];
						if (!curSum) largestArea = max(largestArea, (x2-x1+1)*(y2-y1+1));
					}
				}
			}
		}
		cout << largestArea << endl;
	}
	return 0;
}
