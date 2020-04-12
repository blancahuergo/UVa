#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<int> chop;
vector<vector<int>> DP;

int calc() {
	// DP[triples][ind]
	DP.assign(K+1, vector<int>(N, 2e9));
	for (int j = 0; j < N; j++)
		DP[0][j] = 0;
	for (int i = 1; i <= K; i++) {
		for (int j = 3*i-1; j < N; j++) {
			DP[i][j] = min(DP[i][j-1], DP[i-1][j-2] + (chop[j] - chop[j-1])*(chop[j] - chop[j-1]));
		}
	}
	int ans = 2e9;
	for (int j = 2; j < N; j++) ans = min(ans, DP[K][j]);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--) {
		cin >> K >> N;
		K += 8;
		chop.assign(N, 0);
		for (int n = N-1; n >= 0; n--) cin >> chop[n];
		cout << calc() << "\n";
	}
	return 0;
}
