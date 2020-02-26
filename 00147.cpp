#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<vector<long long>> posChange;

void build() {
	vector<int> coins = {10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
	int coin;
	vector<long long> empty;
	empty.assign(posChange[0].size(), 1);
	posChange[1] = empty;
	for (int c = 0; c < coins.size(); c++) coins[c] /= 5;
	for (int c = 1; c <= coins.size(); c++) {
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
	double M;
	vector<long long> empty;
	empty.assign(6010, 0);
	posChange.assign(11, empty);
	build();
	while(true) {
		cin >> M;
		if (M == 0) break;
		N = 20*M;
		printf("%6.2lf%17lld\n", M, posChange[10][N]);
	}
	return 0;
}
