#include <iostream>
using namespace std;

int main() {
	int T, N, M, largestArea, area;
	long long K, curSum, price;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		cin >> N >> M >> K;
		long long DP[N][M], cell;
		cin >> DP[0][0];
		for (int j = 1; j < M; j++) {
			cin >> cell;
			DP[0][j] = DP[0][j-1] + cell;
		}
		for (int i = 1; i < N; i++) {
			cin >> cell;
			DP[i][0] = DP[i-1][0] + cell;
			for (int j = 1; j < M; j++) {
				cin >> cell;
				DP[i][j] = DP[i-1][j] + DP[i][j-1] + cell - DP[i-1][j-1];
			}
		}
		largestArea = 0;
		price = 0;
		for (int x1 = 0; x1 < N; x1++) {
			for (int x2 = x1; x2 < N; x2++) {
				for (int y1 = 0; y1 < M; y1++) {
					for (int y2 = y1; y2 < M; y2++) {
						if (x1 == 0) {
							if (y1 == 0) curSum = DP[x2][y2];
							else curSum = DP[x2][y2] - DP[x2][y1-1];
						} else if (y1 == 0) curSum = DP[x2][y2] - DP[x1-1][y2];
						else curSum = DP[x2][y2] - DP[x2][y1-1] - DP[x1-1][y2] + DP[x1-1][y1-1];
						area = (y2 - y1 + 1)*(x2 - x1 + 1);
						if (area > largestArea && curSum <= K) {
							largestArea = area;
							price = curSum;
						} else if (area == largestArea && curSum < price) {
							price = curSum;
						}
					}
				}
			}
		}
		cout << "Case #" << cas << ": " << largestArea << " " << price << endl;
	}
	return 0;
}
