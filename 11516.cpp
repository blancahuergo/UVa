#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, M, tot, i;
	double hi, lo, mid, cur;
	vector<double> house;
	cin >> T;
	cout << fixed << setprecision(1);
	while(T--) {
		cin >> N >> M;
		house.assign(M, 0);
		hi = 0;
		for (int m = 0; m < M; m++) {
			cin >> house[m];
			hi = max(hi, house[m]);
		}
		sort(house.begin(), house.end());
		lo = 0;
		while(hi - lo > 1e-9) {
			mid = (lo + hi)/2;
			tot = 1;
			cur = house[0] + mid;
			i = 1;
			while(i < M) {
				while(house[i] - mid <= cur) {
					i++;
					if (i == M) break;
				}
				if (i == M) break;
				cur = house[i] + mid;
				i++;
				tot++;
			}
			if (tot <= N) hi = mid;
			else lo = mid;
		}
		cout << hi << "\n";
	}
	return 0;
}
