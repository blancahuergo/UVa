#include <iostream>
#include <cstring>
using namespace std;

const int maxL=26, maxS=351;
int DP[maxL+1][maxS+1][26];

void fillDP() {
	memset(DP, 0, sizeof DP);
	for (int s = 1; s <= 26; s++) DP[1][s][s-1] = 1;
	for (int l = 2; l <= maxL; l++) {
		for (int s = l+1; s <= maxS; s++) {
			for (int k = 1; k <= min(s, 26); k++) {
				for (int m = 1; m < k; m++) {
					DP[l][s][k-1] += DP[l-1][s-k][m-1];
				}
			}
		}
	}
}

int main() {
	int L, S, cas = 1;
	fillDP();
	while(true) {
		cin >> L >> S;
		if (!(L||S)) break;
		int ans = 0;
		if (L < S && L <= 26 && S <= maxS)
			for (int i = 0; i < 26; i++) ans += DP[L][S][i];
		cout << "Case " << cas << ": " << ans << "\n";
		cas++;
	}
	return 0;
}
