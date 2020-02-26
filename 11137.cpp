#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> posChange;

void build() {
	vector<int> coins;
	for (int i = 1; i <= 21; i++) coins.push_back(i*i*i);
	int coin;
	vector<long long> empty;
	empty.assign(posChange[0].size(), 1);
	posChange[1] = empty;
	for (int c = 2; c <= coins.size(); c++) {
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
	empty.assign(10010, 0);
	posChange.assign(22, empty);
	build();
	while(cin >> N) {
		cout << posChange[21][N] << endl;
	}
	return 0;
}
