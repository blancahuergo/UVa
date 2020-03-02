#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int B, N, ret;
	while(cin >> B >> N) {
		int values[N], prices[N];
		for (int n = 0; n < N; n++) {
			cin >> prices[n] >> values[n];
		}
		int DP[N+1][B+201];
		memset(DP, 0, sizeof DP);
		for (int i = 1; i <= N; i++) {
			for (int w = 0; w <= B+200; w++) {
				if (w > prices[i-1] && DP[i-1][w-prices[i-1]] > 0) {
					DP[i][w] = max(DP[i-1][w], DP[i-1][w-prices[i-1]]+values[i-1]);
				} else if (w == prices[i-1]) {
					DP[i][w] = max(DP[i-1][w], DP[i-1][w-prices[i-1]]+values[i-1]);
				} else {
					DP[i][w] = DP[i-1][w];
				}
			}
		}
		ret = DP[N][B];
		for (int b = max(B, 2001); b <= B+200; b++) {
			ret = max(ret, DP[N][b]);
		}
		for (int b = 0; b < B; b++) {
			ret = max(ret, DP[N][b]);
		}
		cout << ret << endl;
	}
	return 0;
}
