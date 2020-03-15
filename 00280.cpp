#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<vector<int>> cost;
	vector<int> empt;
	vector<int> ans;
	int N, i, j, Q, st;
	while(true) {
		cin >> N;
		empt.assign(N, 100);
		cost.assign(N, empt);
		if (!N) break;
		while(true) {
			cin >> i;
			if (!i) break;
			while(true) {
				cin >> j;
				if (!j) break;
				cost[i-1][j-1] = min(cost[i-1][j-1], 0);
			}
		}
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				for (int c = 0; c < N; c++) {
					cost[b][c] = min(cost[b][c], cost[b][a]+cost[a][c]);
				}
			}
		}
		cin >> Q;
		while (Q--) {
			cin >> st;
			ans.clear();
			for (int k = 0; k < N; k++) {
				if (cost[st-1][k] > 0) ans.push_back(k+1);
			}
			cout << ans.size();
			for (int k = 0; k < ans.size(); k++) {
				cout << " " << ans[k];
			}
			cout << "\n";
		}
	}
	return 0;
}
