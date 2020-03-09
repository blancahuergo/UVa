#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> T1;
vector<int> T2;

int LCS(int m, int n) {
	int DP[m+1][n+1];
	DP[0][0] = 0;
	memset(DP, 0, sizeof DP);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (T1[i-1] == T2[j-1]) DP[i][j] = DP[i-1][j-1] + 1;
			else DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
		}
	}
	return DP[m][n];
}

int main() {
	int M, N;
	int cas = 1;
	while(true) {
		cin >> M >> N;
		if (!(M||N)) break;
		T1.assign(M, 0);
		for (int m = 0; m < M; m++) {
			cin >> T1[m];
		}
		T2.assign(N, 0);
		for (int n = 0; n < N; n++) {
			cin >> T2[n];
		}
		cout << "Twin Towers #" << cas << endl;
		cout << "Number of Tiles : " << LCS(M, N) << endl;
		cout << "\n";
		cas++;
	}
	return 0;
}
