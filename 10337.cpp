#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int X, P;
vector<vector<int>> W;
vector<vector<int>> DP;

int calc() {
	DP.assign(P+1, vector<int>(10, 2e9));
	DP[0][0] = 0;
	queue<pair<int, int>> Q;
	Q.push({0, 0});
	pair<int, int> cur;
	int D, A;
	while(!Q.empty()) {
		cur = Q.front();
		Q.pop();
		D = cur.first;
		A = cur.second;
		if (D == P) continue;
		if (DP[D+1][A] > DP[D][A] + 30 - W[D][A]) {
			DP[D+1][A] = DP[D][A] + 30 - W[D][A];
			Q.push({D+1, A});
		}
		if (A > 0 && DP[D+1][A-1] > DP[D][A] + 20 - W[D][A]) {
			DP[D+1][A-1] = DP[D][A] + 20 - W[D][A];
			Q.push({D+1, A-1});
		}
		if (A < 9 && DP[D+1][A+1] > DP[D][A] + 60 - W[D][A]) {
			DP[D+1][A+1] = DP[D][A] + 60 - W[D][A];
			Q.push({D+1, A+1});
		}
	}
	return DP[P][0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--) {
		cin >> X;
		P = X/100;
		W.assign(P+1, vector<int>(10, 0));
		for (int i = 9; i >= 0; i--)
			for (int x = 0; x < P; x++) cin >> W[x][i];
		cout << calc() << "\n\n";
	}
	return 0;
}
