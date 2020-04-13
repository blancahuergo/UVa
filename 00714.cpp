#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, K, i;
	ll low, high, mid, slack, pos;
	vector<ll> books, scribes, empt;
	vector<vector<ll>> ans;
	cin >> T;
	while(T--) {
		cin >> N >> K;
		high = 0;
		low = 0;
		books.assign(N, 0);
		for (int n = 0; n < N; n++) {
			cin >> books[n];
			high += books[n];
			low = max(low, books[n]);
		}
		pos = high;
		while(low < high) {
			mid = (low+high)/2;
			i = 0;
			scribes.assign(K, 0);
			slack = 0;
			for (int k = 0; k < K; k++) {
				while(i < N) {
					if (scribes[k] + books[i] <= mid) {
						scribes[k] += books[i];
						i++;
					} else break;
				}
				slack += mid - scribes[k];
			}
			if (slack > 0 && i == N) {
				high = mid;
				pos = mid;
			} else if (slack == 0 && i == N) {
				pos = mid;
				break;
			}
			else low = mid;
			if (mid == (low+high)/2) break;
		}
		i = N-1;
		scribes.assign(K, 0);
		ans.assign(K, empt);
		for (int k = K-1; k >= 0; k--) {
			while(i >= 0) {
				if (scribes[k] + books[i] <= pos && i >= k) {
					scribes[k] += books[i];
					ans[k].insert(ans[k].begin(), books[i]);
					i--;
				} else break;
			}
		}
		for (int k = 0; k < K; k++) {
			if (k) cout << " / ";
			for (int j = 0; j < (int) ans[k].size(); j++) {
				if (j) cout << ' ';
				cout << ans[k][j];
			}
		}
		cout << "\n";
	}
	return 0;
}
