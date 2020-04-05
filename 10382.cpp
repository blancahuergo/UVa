#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int N, l, w, x, r;
	vector<pair<double, double>> S;
	while(cin >> N >> l >> w) {
		S.clear();
		double rest = ((double)w*w)/4, dif;
		for (int n = 0; n < N; n++) {
			cin >> x >> r;
			if (2*r < w) continue;
			dif = sqrt(((double) r*r) - rest);
			S.push_back(make_pair(x-dif, x+dif));
		}
		if (S.size() == 0) {
			cout << "-1\n";
			continue;
		}
		sort(S.begin(), S.end());
		double cur = 0, nxt;
		int i = 0, ans = 0;
		while (cur < l) {
			nxt = cur;
			while (i < N) {
				if (S[i].first > cur)
					break;
				nxt = max(nxt, S[i].second);
				i++;
			}
			if (nxt == cur) {
				ans = -1;
				break;
			}
			ans++;
			cur = nxt;
		}
		cout << ans << "\n";
	}
	return 0;
}
