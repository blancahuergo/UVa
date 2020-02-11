#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	int cases, num_coins, num_weight, num_c_bal, cur, coin;
	bool found;
	unordered_set<int> cur_coins;
	char conc;
	cin >> cases;
	while (cases) {
		cin >> num_coins >> num_weight;
		bool rem_coins[num_coins];
		for (int i = 1; i <= num_coins; i++) {
			rem_coins[i] = true;
		}
		for (int u = 0; u < num_weight; u++) {
			cin >> num_c_bal;
			cur_coins.clear();
			for (int y = 0; y < num_c_bal*2; y++) {
				cin >> cur;
				cur_coins.insert(cur);
			}
			cin >> conc;
			if (conc == '=') {
				for (const auto& c: cur_coins) {
				    rem_coins[c-1] = false;
				}
			} else {
				for (int c = 0; c < num_coins; c++) {
					if (cur_coins.find(c+1) == cur_coins.end()) {
						rem_coins[c] = false;
					}
				}
			}
		}
		found = false;
		coin = -1;
		for (int i = 0; i < num_coins; i++) {
			if (rem_coins[i]) {
				if (found) {
					coin = -1;
					break;
				}
				found = true;
				coin = i+1;
			}
		}
		if (coin > 0) {
			cout << coin << endl;
		} else {
			cout << "0" << endl;
		}
		cases--;
		if (cases) {
			cout << "\n";
		}
	}
	return 0;
}
