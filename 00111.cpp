#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<int> ord, orig;

int LCS(vector<int> orig, vector<int> ord, int N) {
	int DP[N+1][N+1];
	DP[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		DP[i][0] = 0;
		DP[0][i] = 0;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (orig[i-1] == ord[j-1]) DP[i][j] = DP[i-1][j-1]+1;
			else DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
		}
	}
	return DP[N][N];
}

int main() {
	bool next_round = true;
	int N, ind, num;
	string line;
	getline(cin, line);
	N = stoi(line);
	while(next_round) {
		orig.assign(N, 0);
		getline(cin, line);
		istringstream is(line);
		ind = 0;
		while(is >> num) {
			orig[num-1] = ind;
			ind++;
		}
		next_round = false;
		while(getline(cin, line)) {
			ord.assign(N, 0);
			ind = 0;
			istringstream is(line);
			while(is >> num) {
				ord[num-1] = ind;
				ind++;
			}
			if (ind == 1) {
				N = num;
				next_round = true;
				break;
			} else {
				cout << LCS(orig, ord, N) << endl;
			}
		}
	}
	return 0;
}
