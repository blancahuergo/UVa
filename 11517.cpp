#include <iostream>
#include <vector>
using namespace std;

vector<long long> posChange;

int buildDP(vector<int> coins, int req) {
	posChange.assign(10010, 0);
	int coin;
	for (int c = 0; c < coins.size(); c++) {
		coin = coins[c];
		for (int am = posChange.size()-1; am > coin; am--) {
			if (posChange[am - coin] > 0) {
				if (posChange[am] > 0) posChange[am] = min(posChange[am], posChange[am - coin]+1);
				else posChange[am] = posChange[am - coin]+1;
			}
		}
		posChange[coin] = 1;
	}
	for (int am = req; am < posChange.size(); am++) {
		if (posChange[am] > 0) return am;
	}
	return 10000;
}

int main() {
	int cases, num_c, amount_req, amount_paid;
	vector<int> coins;
	cin >> cases;
	while(cases--) {
		cin >> amount_req;
		cin >> num_c;
		coins.assign(num_c, 0);
		for (int c = 0; c < num_c; c++) {
			cin >> coins[c];
		}
		amount_paid = buildDP(coins, amount_req);
		cout << amount_paid << " " << posChange[amount_paid] << endl;
	}
	return 0;
}
