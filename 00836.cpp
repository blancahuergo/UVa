#include <iostream>
#include <vector>
using namespace std;

int main() {
	int cases, N, largestArea, curSum;
	vector<string> lines;
	string line;
	getline(cin, line);
	cases = stoi(line);
	getline(cin, line);
	while(cases--) {
		lines.clear();
		N = 0;
		while(true) {
			getline(cin, line);
			if (line.length() == 0) break;
			lines.push_back(line);
			N++;
		}
		int DP[N][N];
		DP[0][0] = lines[0][0] - '0';
		for (int j = 1; j < N; j++) {
			DP[0][j] = DP[0][j-1] + (lines[0][j] - '0');
		}
		for (int i = 1; i < N; i++) {
			DP[i][0] = DP[i-1][0] + (lines[i][0] - '0');
			for (int j = 1; j < N; j++) {
				DP[i][j] = DP[i-1][j] + DP[i][j-1] + (lines[i][j] - '0') - DP[i-1][j-1];
			}
		}
		largestArea = 0;
		for (int x1 = 0; x1 < N; x1++) {
			for (int x2 = x1; x2 < N; x2++) {
				for (int y1 = 0; y1 < N; y1++) {
					for (int y2 = y1; y2 < N; y2++) {
						if (x1 == 0) {
							if (y1 == 0) curSum = DP[x2][y2];
							else curSum = DP[x2][y2] - DP[x2][y1-1];
						} else if (y1 == 0) curSum = DP[x2][y2] - DP[x1-1][y2];
						else curSum = DP[x2][y2] - DP[x2][y1-1] - DP[x1-1][y2] + DP[x1-1][y1-1];
						if (curSum == (x2-x1+1)*(y2-y1+1)) largestArea = max(largestArea, curSum);
					}
				}
			}
		}
		cout << largestArea << endl;
		if (cases) cout << "\n";
	}
	return 0;
}
