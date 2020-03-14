#include <iostream>
#include <vector>
using namespace std;

vector<int> cuts;
vector<vector<int>> DP;

int minCuts(int l, int r) {
	if (r - l <= 1) return 0;
	if (DP[l][r] != -1) return DP[l][r];
	int res = 2000000000;
	for (int i = l+1; i < r; i++) {
		res = min(res, minCuts(l, i) + minCuts(i, r) + cuts[r] - cuts[l]);
	}
	DP[l][r] = res;
	return res;
}

int main() {
	int l, N;
	vector<int> empt;
	while(true) {
		cin >> l;
		if (!l) break;
		cin >> N;
		cuts.assign(N+2, 0);
		cuts[0] = 0;
		cuts[N+1] = l;
		empt.assign(N+2, -1);
		DP.assign(N+2, empt);
		for (int n = 1; n <= N; n++) {
			cin >> cuts[n];
		}
		cout << "The minimum cutting is " << minCuts(0, N+1) << ".\n";
	}
	return 0;
}
