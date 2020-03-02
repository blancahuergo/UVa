#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int cases, N, coin, sum_coins, max_W, diff;
	cin >> cases;
	for (int u = 0; u < cases; u++) {
		cin >> N;
		int coins[N];
		sum_coins = 0;
		for (int i = 0; i < N; i++) {
			cin >> coins[i];
			sum_coins += coins[i];
		}
		max_W = sum_coins / 2;
		int DP[N+1][max_W+1];
		memset(DP, 0, sizeof DP);
		for (int c = 1; c <= N; c++) {
			coin = coins[c-1];
			for(int w = 0; w <= max_W; w++) {
				if (w >= coin) {
					DP[c][w] = max(DP[c-1][w], DP[c-1][w-coin]+coin);
					if (w > 0) DP[c][w] = max(DP[c][w], DP[c][w-1]);
				} else {
					if (w == 0) DP[c][w] = DP[c-1][w];
					else DP[c][w] = max(DP[c][w-1], DP[c-1][w]);
				}
			}
		}
		diff = sum_coins - 2*DP[N][max_W];
		cout << diff << endl;
	}
	return 0;
}
