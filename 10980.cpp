#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

vector<double> DP_pri, prices;
vector<int> amount;

void fillDP() {
	DP_pri.assign(101, 2e9);
	DP_pri[0] = 0;
	for (int i = 1; i <= 100; i++)
		for (int j = 0; j < (int) prices.size(); j++) {
			if (amount[j] <= i && DP_pri[i - amount[j]] + prices[j] < DP_pri[i])
				DP_pri[i] = prices[j] + DP_pri[i - amount[j]];
			else if (amount[j] > i && DP_pri[i] > prices[j])
				DP_pri[i] = prices[j];
		}
	for (int i = 99; i >= 0; i--) {
		DP_pri[i] = min(DP_pri[i], DP_pri[i+1]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(2);
	string line;
	stringstream ss;
	int M, Q;
	double unit;
	int cas = 1;
	while (getline(cin, line)) {
		ss.str("");
		ss.clear();
		ss.str(line);
		ss >> unit >> M;
		prices.assign(M+1, 0);
		amount.assign(M+1, 0);
		amount[0] = 1;
		prices[0] = unit;
		for (int m = 1; m <= M; m++) {
			getline(cin, line);
			ss.str("");
			ss.clear();
			ss.str(line);
			ss >> amount[m] >> prices[m];
		}
		fillDP();
		getline(cin, line);
		ss.str("");
		ss.clear();
		ss.str(line);
		cout << "Case " << cas << ":\n";
		while(ss >> Q) {
			cout << "Buy " << Q << " for $" << DP_pri[Q] << "\n";
		}
		cas++;
	}
	return 0;
}
