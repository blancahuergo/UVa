#include <iostream>
#include <cstring>
using namespace std;

int N, K;
int DP[501][501];

int W(int i) {
	return i + 1 + K;
}

int cost(int i, int j) {
	if (DP[i][j] != -1) return DP[i][j];
	if (i == j-1) return DP[i][j] = 2*W(i);
	if (i == j || i < 0) return 0;
	int ret = 2e9;
	for (int k = i; k <= j; k++) {
		ret = min(ret, cost(i, k-1) + (j-i+1)*W(k) + cost(k+1, j));
	}
	return DP[i][j] = ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		cin >> N >> K;
		memset(DP, -1, sizeof DP);
		cout << "Case " << cas << ": " << cost(0, N-1) << "\n";
	}
	return 0;
}
