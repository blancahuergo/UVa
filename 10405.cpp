#include <iostream>
#include <cstring>
using namespace std;

char line1[1002], line2[1002];

int LCS() {
	int m = strlen(line1);
	int n = strlen(line2);
	int DP[m+1][n+1];
	memset(DP, 0, sizeof DP);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (line1[i-1] == line2[j-1]) {
				DP[i][j] = DP[i-1][j-1]+1;
			} else {
				DP[i][j] = max(DP[i][j-1], DP[i-1][j]);
			}
		}
	}
	return DP[m][n];
}

int main() {
	while(gets(line1)) {
		gets(line2);
		cout << LCS() << endl;
	}
	return 0;
}
