#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
// for each problem:
// preprocess 2D grid of the values the sum of real and virtual coin achieves and the ways of doing this.
// function to check that e-value from the grid for each query

vector<vector<int>> posChange;
vector<pair<int, int>> coins;

void buildDP() {
	pair<int, int> coin;
	vector<int> empty;
	empty.assign(301, 0);
	posChange.assign(301, empty);
	for (int c = 0; c < coins.size(); c++) {
		coin = coins[c];
		posChange[coin.first][coin.second] = 1;
		for (int i = coin.first; i < posChange.size(); i++) {
			for (int j = coin.second; j < posChange[0].size(); j++) {
				if (posChange[i - coin.first][j - coin.second] > 0) {
					if (posChange[i][j] > 0)
						posChange[i][j] = min(posChange[i][j], posChange[i - coin.first][j - coin.second]+1);
					else
						posChange[i][j] = posChange[i - coin.first][j - coin.second]+1;
				}
			}
		}
	}
}

int findWays(int S) {
	int total = 2*S;
	int j;
	for (int i = 0; i*i <= S*S; i++) {
		j = sqrt(S*S - i*i);
		if (i*i + j*j == S*S) {
			if (posChange[i][j] > 0)
				total = min(total, posChange[i][j]);
			if (posChange[j][i] > 0)
				total = min(total, posChange[j][i]);
		}
	}
	return total;
}

int main() {
	int cases, S, n_coins, ans;
	cin >> cases;
	while (cases--) {
		cin >> n_coins;
		coins.assign(n_coins, {0, 0});
		cin >> S;
		for (int i = 0; i < n_coins; i++) cin >> coins[i].first >> coins[i].second;
		buildDP();
		ans = findWays(S);
		if (ans != 2*S) cout << ans << endl;
		else cout << "not possible\n";
	}
	return 0;
}
