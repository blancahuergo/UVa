#include <iostream>
using namespace std;

int main() {
	int M, N, cell, largestArea, curSum;
	while(true) {
		cin >> M >> N;
		if (!(M||N)) break;
		int DP[M][N];
		cin >> DP[0][0];
		for (int j = 1; j < N; j++) {
			cin >> cell;
			DP[0][j] = DP[0][j-1]+cell;
		}
		for (int i = 1; i < M; i++) {
			cin >> cell;
			DP[i][0] = DP[i-1][0] + cell;
			for (int j = 1; j < N; j++) {
				cin >> cell;
				DP[i][j] = DP[i-1][j] + DP[i][j-1] + cell - DP[i-1][j-1];
			}
		}
		largestArea = 0;
		for (int x1 = 0; x1 < M; x1++) {
			for (int x2 = x1; x2 < M; x2++) {
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
