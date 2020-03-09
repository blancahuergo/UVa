#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

vector<int> tracks;

void max_sum(int T, int N) {
	int DP[N+1][T+1], len;
	memset(DP, 0, sizeof DP);
	for (int t = 1; t <= T; t++) {
		len = tracks[t-1];
		for (int n = 1; n <= N; n++) {
			DP[n][t] = DP[n][t-1];
			if (n - len >= 0) DP[n][t] = max(DP[n][t], DP[n-len][t-1]+len);
		}
	}
	stack <int> nums;
	int tot = 0;
	pair<int, int> cur = {N, T};
	while (cur.first > 0 && cur.second > 0) {
		if (DP[cur.first][cur.second] == DP[cur.first][cur.second-1]) {
			cur.second--;
		} else {
			cur.first -= tracks[cur.second-1];
			nums.push(tracks[cur.second-1]);
			tot += tracks[cur.second-1];
			cur.second--;
		}
	}
	while (! nums.empty()) {
		cout << nums.top() << " ";
		nums.pop();
	}
	cout << "sum:" << tot << endl;
}

int main() {
	int N, T;
	while(cin >> N >> T) {
		tracks.assign(T, 0);
		for (int t = 0; t < T; t++) {
			cin >> tracks[t];
		}
		max_sum(T, N);
	}
	return 0;
}
