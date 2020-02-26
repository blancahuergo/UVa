#include <iostream>
#include <vector>
using namespace std;

vector<vector<long>> posChange;

void build() {
	vector<int> coins = {1, 5, 10, 25, 50};
	int coin;
	vector<long> empty;
	empty.assign(8000, 1);
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
	vector<long> empty;
	empty.assign(8000, 0);
	posChange.assign(6, empty);
	build();
	while(cin >> N) {
		if (N == 0) cout << "1\n";
		else cout << posChange[5][N] << endl;
	}
	return 0;
}
