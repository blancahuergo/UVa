#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int cas, mon, gar, cur_gar, c_p;
	int prices[25][25];
	int DP[221][21];
	int units[25];
	bool possible;
	cin >> cas;
	while(cas--) {
		cin >> mon >> gar;
		memset(prices, 0, sizeof prices);
		for (int y = 0; y < gar; y++) {
			cin >> cur_gar;
			units[y] = cur_gar;
			for (int u = 0; u < cur_gar; u++) {
				cin >> c_p;
				prices[y][u] = c_p;
			}
		}
		// prices[garment][unit]
		// DP[money][garment]
		DP[0][0] = 0;
		for (int m = 1; m <= mon; m++) {
			DP[m][0] = DP[m-1][0];
			for (int u = 0; u < units[0]; u++) {
				if (prices[0][u] <= m)
					DP[m][0] = max(DP[m][0], prices[0][u]);
			}
		}
		possible = true;
		for (int g = 1; g < gar; g++) {
			DP[0][g] = 0;
			for (int m = 1; m <= mon; m++) {
				DP[m][g] = DP[m-1][g];
				for (int u = 0; u < units[g]; u++) {
					if (m - prices[g][u] >= 0 && m - prices[g][u] >= DP[m-prices[g][u]][g-1]) {
						DP[m][g] = max(DP[m][g], DP[m-prices[g][u]][g-1] + prices[g][u]);
					}
				}
			}
			if (DP[mon][g] == 0) {
				possible = false;
				break;
			}
		}
		if (possible) cout << DP[mon][gar-1] << endl;
		else cout << "no solution" << endl;
	}
	return 0;
}
