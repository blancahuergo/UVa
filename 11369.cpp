#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> prices;

int solve(int N) {
	int disc = 0;
	sort(prices.begin(), prices.end());
	int i = N-3;
	while(i >= 0) {
		disc += prices[i];
		i-=3;
	}
	return disc;
}

int main() {
	int T, N;
	cin >> T;
	while(T--) {
		cin >> N;
		prices.assign(N, 0);
		for (int n = 0; n < N; n++) cin >> prices[n];
		cout << solve(N) << "\n";
	}
	return 0;
}
