#include <iostream>
#include <cstring>
using namespace std;

int M, C, price[25][25], DP[210][25], garment_num[25];

int shop(int money_left, int g) {
	if (money_left < 0) return -1000;
	if (g == C) return M - money_left;
	if (DP[money_left][g] != -1) return DP[money_left][g];
	int ans = -1;
	for (int option = 0; option < garment_num[g]; option++) {
		ans = max(ans, shop(money_left - price[g][option], g+1));
	}
	DP[money_left][g] = ans;
	return ans;
}

int main() {
	int N, result;
	cin >> N;
	while(N--) {
		cin >> M >> C;
		for (int c = 0; c < C; c++) {
			cin >> garment_num[c];
			for (int i = 0; i < garment_num[c]; i++) {
				cin >> price[c][i];
			}
		}
		memset(DP, -1, sizeof DP);
		result = shop(M, 0);
		if (result < 0) cout << "no solution\n";
		else cout << result << endl;
	}
	return 0;
}
