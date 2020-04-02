#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> soldiers;

bool comp(pair<int, int> P1, pair<int, int> P2) {
	if (P1.first > P2.first) return true;
	else if (P2.first > P1.first) return false;
	return P1.second > P2.second;
}

int solve(int N) {
	sort(soldiers.begin(), soldiers.end(), comp);
	int curT=0, maxT=0;
	for (int i = 0; i < N; i++) {
		curT += soldiers[i].second;
		maxT = max(maxT, curT+soldiers[i].first);
	}
	return maxT;
}

int main() {
	int N, t=1;
	while(true) {
		cin >> N;
		if (!N) break;
		soldiers.assign(N, {0, 0});
		for (int n = 0; n < N; n++) {
			cin >> soldiers[n].second >> soldiers[n].first;
		}
		cout << "Case " << t << ": " << solve(N) << "\n";
		t++;
	}
	return 0;
}
