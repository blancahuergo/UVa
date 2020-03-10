#include <iostream>
#include <vector>
using namespace std;

vector<int> stones;
vector<int> DP;

int wins(int N) {
	// solve using top-down DP from one of the players' perspective
	// return value of 1 means the player that plays that turn wins.
	// return value of 0 means the player that plays that turn loses.
	if (DP[N] != -1) return DP[N];
	bool ret = false;
	for (int s = 0; s < stones.size(); s++) {
		if (stones[s] > N) continue;
		if (!wins(N - stones[s])) {
			ret = true;
			break;
		}
	}
	DP[N] = ret;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, S, res;
	while(cin >> N >> S) {
		stones.assign(S, 0);
		for (int s = 0; s < S; s++) cin >> stones[s];
		DP.assign(N+1, -1);
		DP[0] = 0;
		DP[1] = 1;
		res = wins(N);
		if (res) cout << "Stan wins\n";
		else cout << "Ollie wins\n";
	}
	return 0;
}
