#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int m, n, t, max_reach;
	while(cin >> m >> n >> t) {
		if (t < min(m, n)) {
			cout << "0 " << t << endl;
			continue;
		}
		int DP[t+1];
		memset(DP, -1, sizeof DP);
		DP[min(n, m)] = 1;
		DP[0] = 0;
		max_reach = 0;
		for (int i = min(m, n); i <= t; i++) {
			if (i >= m && i >= n) {
				if (DP[i-m] != -1) DP[i] = DP[i-m]+1;
				if (DP[i-n] != -1) {
					if (DP[i] != -1)
						DP[i] = max(DP[i], DP[i-n]+1);
					else
						DP[i] = DP[i-n]+1;
				}
			}
			else if (i >= m) {
				if (DP[i-m] != -1) DP[i] = DP[i-m]+1;
			} else {
				if (DP[i-n] != -1) DP[i] = DP[i-n]+1;
			}
			if (DP[i] != -1) max_reach = i;
		}
		if (DP[t] != -1) cout << DP[t] << endl;
		else cout << DP[max_reach] << " " <<  (t - max_reach) << endl;
	}
	return 0;
}
