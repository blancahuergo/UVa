#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long long L, x, r;
	int G;
	vector<pair<long long, long long>> stations;
	while(true) {
		cin >> L >> G;
		if (!(L||G)) break;
		stations.assign(G, {0LL, 0LL});
		for (int g = 0; g < G; g++) {
			cin >> x >> r;
			stations[g].first = x-r;
			stations[g].second = x+r;
		}
		sort(stations.begin(), stations.end());
		int used=0, i = 0;
		long long cov = 0LL, nxt;
		while(cov < L) {
			nxt = cov;
			while (i < G && stations[i].first <= cov) {
				nxt = max(nxt, stations[i].second);
				i++;
			}
			if (nxt == cov) {
				used = -1;
				break;
			}
			used++;
			cov = nxt;
		}
		if (used == -1) cout << "-1\n";
		else cout << (G-used) << "\n";
	}
	return 0;
}
