#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main() {
	int T, w, N, d, a, b;
	bool first = true;
	while(cin >> T >> w) {
		cin >> N;
		int values[N], weights[N];
		for (int n = 0; n < N; n++) {
			cin >> d >> values[n];
			weights[n] = 3*w*d;
		}
		int DP[N+1][T+1];
		memset(DP, 0, sizeof DP);
		for (int i = 1; i <= N; i++) {
			for (int t = 0; t <= T; t++) {
				if (t >= weights[i-1]) {
					DP[i][t] = max(DP[i-1][t], DP[i-1][t-weights[i-1]] + values[i-1]);
				} else {
					DP[i][t] = DP[i-1][t];
				}
				if (t > 0) DP[i][t] = max(DP[i][t], DP[i][t-1]);
			}
		}
		stack<int> gold;
		a = N, b = T;
		while(a) {
			if (weights[a-1] <= b) {
				if (DP[a][b] == DP[a-1][b - weights[a-1]] + values[a-1]) {
					a--;
					b -= weights[a];
					gold.push(a);
				} else {
					if (DP[a][b] == DP[a-1][b]) a--;
					else b--;
				}
			} else {
				if (DP[a][b] == DP[a-1][b]) a--;
				else b--;
			}
		}
		if (!first) cout << "\n";
		first = false;
		cout << DP[N][T] << endl;
		cout << gold.size() << endl;
		while(!gold.empty()) {
			a = gold.top();
			cout << weights[a]/(3*w) << " " << values[a] << endl;
			gold.pop();
		}
	}
	return 0;
}
