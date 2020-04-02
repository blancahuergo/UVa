#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> eggs;
int solve(int N, int Q, int P) {
	sort(eggs.begin(), eggs.end());
	int totW = 0, ind = 0;
	while(ind < min(P, N)) {
		if (totW + eggs[ind] <= Q) {
			totW += eggs[ind];
		} else break;
		ind++;
	}
	return ind;
}

int main() {
	int T, N, P, Q;
	cin >> T;
	for (int t=1; t<=T; t++) {
		cin >> N >> P >> Q;
		eggs.assign(N, 0);
		for (int n = 0; n<N; n++) cin >> eggs[n];
		cout << "Case " << t << ": " << solve(N, Q, P) << "\n";
	}
	return 0;
}
