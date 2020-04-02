#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> bache, spins;

void solve(int B, int S, int t) {
	if (B <= S) {
		cout << "Case " << t << ": 0\n";
		return;
	} else {
		cout << "Case " << t << ": " << (B-S) << " " << bache[0] << "\n";
	}
}

int main() {
	int B, S, t = 1;
	while(true) {
		cin >> B >> S;
		if (!(B||S)) break;
		bache.assign(B, 0);
		for (int b = 0; b < B; b++) cin >> bache[b];
		spins.assign(S, 0);
		for (int s = 0; s < S; s++) cin >> spins[s];
		sort(bache.begin(), bache.end());
		sort(spins.begin(), spins.end());
		solve(B, S, t);
		t++;
	}
	return 0;
}
