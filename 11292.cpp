#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> diam, knights;

void solve() {
	int dInd=0, kInd=0, cost = 0;
	bool pos = true;
	while(dInd < (int) diam.size()) {
		if (kInd == (int) knights.size()) {
			pos = false;
			break;
		}
		while (knights[kInd] < diam[dInd]) {
			kInd++;
			if (kInd == (int) knights.size()) {
				pos = false;
				break;
			}
		}
		if (!pos) break;
		cost += knights[kInd];
		dInd++;
		kInd++;
	}
	if (pos) cout << cost << "\n";
	else cout << "Loowater is doomed!\n";
}

int main() {
	int N, M;
	while(true) {
		cin >> N >> M;
		if (!(N||M)) break;
		diam.assign(N, 0);
		for (int n = 0; n < N; n++) cin >> diam[n];
		knights.assign(M, 0);
		for (int m = 0; m < M; m++) cin >> knights[m];
		sort(diam.begin(), diam.end());
		sort(knights.begin(), knights.end());
		solve();
	}
	return 0;
}
