#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> posChange;

void build() {
	vector<int> coins = {1, 5, 10, 25, 50};
	int coin;
	vector<long long> empty;
	empty.assign(posChange[0].size(), 1);
	posChange[1] = empty;
	for (int c = 2; c <= 5; c++) {
		coin = coins[c-1];
		posChange[c][0] = 1;
		for (int amount = 1; amount < posChange[0].size(); amount++) {
			posChange[c][amount] += posChange[c-1][amount];
			if (amount - coin < 0) continue;
			posChange[c][amount] += posChange[c][amount - coin];
		}
	}
}

int main() {
	int N;
	vector<long long> empty;
	empty.assign(30010, 0);
	posChange.assign(6, empty);
	build();
	while(cin >> N) {
		if (N == 0) cout << "There is only 1 way to produce 0 cents change.\n";
		else if (posChange[5][N] != 1) cout << "There are " << posChange[5][N] << " ways to produce " << N << " cents change.\n";
		else cout << "There is only 1 way to produce " << N << " cents change.\n";
	}
	return 0;
}
