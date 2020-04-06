#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int M, N;
	vector<int> teams;
	vector<pair<int, int>> tables;
	vector<vector<int>> SOL;
	while(true) {
		cin >> M >> N;
		if (!(M||N)) break;
		teams.assign(M, 0);
		tables.assign(N, {0, 0});
		SOL = vector<vector<int>>(M);
		for (int m = 0; m < M; m++) cin >> teams[m];
		for (int n = 0; n < N; n++) {
			cin >> tables[n].first;
			tables[n].second = n+1;
		}
		sort(tables.begin(), tables.end(), greater<pair<int, int>>());
		bool pos = true;
		for (int m = 0; m < M; m++) {
			for (int n = 0; n < N; n++) {
				if (tables[n].first == 0) continue;
				tables[n].first--;
				teams[m]--;
				SOL[m].push_back(tables[n].second);
				if (teams[m] == 0) break;
			}
			if (teams[m] != 0) {
				pos = false;
				break;
			}
		}
		if (pos) {
			cout << "1\n";
			for (int i = 0; i < M; i++) {
				cout << SOL[i][0];
				for (int j = 1; j < (int) SOL[i].size(); j++) cout << " " << SOL[i][j];
				cout << "\n";
			}
		} else cout << "0\n";
	}
	return 0;
}
