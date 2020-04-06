#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, D;
	long double x, y, dist;
	vector<pair<long double, long double>> I;
	int cas = 0;
	while(cin >> N >> D) {
		if (!(N||D)) break;
		cas++;
		I.assign(N, {0, 0});
		bool pos = true;
		for (int n = 0; n < N; n++) {
			cin >> x >> y;
			dist = sqrt(D*D - y*y);
			I[n] = {x-dist, x+dist};
			if (y > D) pos = false;
		}
		if (!pos) {
			cout << "Case " << cas << ": -1\n";
			continue;
		}
		sort(I.begin(), I.end());
		int ans = 0;
		int i;
		for (i = 0; i < N; i++) {
			ans++;
			int j;
			for (j = i+1; j < N; j++) {
				if (I[i].second >= I[j].first) {
					if (I[i].second >= I[j].second) {
						i = j;
					}
				} else {
					i = j-1;
					break;
				}
			}
			if (j == N) break;
		}
		cout << "Case " << cas << ": " << ans << "\n";
	}
	return 0;
}
