#include <iostream>
#include <cstring>
using namespace std;

char A[200], B[200];

int LCS(int m, int n) {
	int DP[m+1][n+1];
	memset(DP, 0, sizeof DP);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (A[i-1] == B[j-1]) DP[i][j] = DP[i-1][j-1]+1;
			else DP[i][j] = max(DP[i][j-1], DP[i-1][j]);
		}
	}
	return DP[m][n];
}

int main() {
	int cas = 1;
	while (gets(A)) {
		if (strcmp(A, "#") == 0) break;
		gets(B);
		cout << "Case #" << cas << ": you can visit at most " << LCS(strlen(A), strlen(B)) << " cities.\n";
		cas++;
	}
	return 0;
}
