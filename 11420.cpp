#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
int N, S;
vector<vector<pair<ll, ll>>> DP;

void fillIn() {
	// DP[numDraw][totSecured][isLocked]
	// locked = first
	DP.assign(N+1, vector<pair<ll, ll>>(S+1, {0,0}));
	// DP[N][S][L] = DP[N-1][S-1][L] + DP[N-1][S][U]
	// DP[N][S][U] = DP[N-1][S][L] + DP[N-1][S][U]
	DP[1][1].first = 1;
	DP[1][0].second = 1;
	for (int n = 2; n <= N; n++) {
		DP[n][0].first = DP[n-1][0].second;
		DP[n][0].second = DP[n-1][0].first + DP[n-1][0].second;
		for (int s = 1; s <= S; s++) {
			DP[n][s].first = DP[n-1][s-1].first + DP[n-1][s].second;
			DP[n][s].second = DP[n-1][s].first + DP[n-1][s].second;
		}
	}
}

ll calc() {
	return DP[N][S].first + DP[N][S].second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	N = 65;
	S = 65;
	fillIn();
	while(true) {
		cin >> N >> S;
		if (N < 0) break;
		if (S > N) cout << "0\n";
		else if (S == N) cout << "1\n";
		else cout << calc() << '\n';
	}
	return 0;
}
