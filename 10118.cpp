#include <iostream>
#include <vector>
using namespace std;

vector<vector<vector<vector<int>>>> DP;
vector<vector<int>> piles;

int calc(int p1, int p2, int p3, int p4, vector<int> bask) {
	if (DP[p1][p2][p3][p4] != -1) return DP[p1][p2][p3][p4];
	if (bask.size() == 5) return DP[p1][p2][p3][p4] = 0;
	if (!(p1||p2||p3||p4)) return DP[p1][p2][p3][p4] = 0;
	bool f;
	int op1= 0, op2= 0, op3= 0, op4= 0, col;
	vector<int> new_bask;
	if (p1) {
		col = piles[0][p1-1];
		f = false;
		new_bask = bask;
		for (int i = 0; i < (int) new_bask.size(); i++) {
			if (new_bask[i] == col) {
				new_bask.erase(new_bask.begin()+i);
				f = true;
				break;
			}
		}
		if (f) {
			op1 = 1+calc(p1-1, p2, p3, p4, new_bask);
		} else {
			new_bask.push_back(col);
			op1 = calc(p1-1, p2, p3, p4, new_bask);
		}
	}
	if (p2) {
		col = piles[1][p2-1];
		f = false;
		new_bask = bask;
		for (int i = 0; i < (int) new_bask.size(); i++) {
			if (new_bask[i] == col) {
				new_bask.erase(new_bask.begin() + i);
				f = true;
				break;
			}
		}
		if (f) {
			op2 = 1 + calc(p1, p2 - 1, p3, p4, new_bask);
		} else {
			new_bask.push_back(col);
			op2 = calc(p1, p2 - 1, p3, p4, new_bask);
		}
	}
	if (p3) {
		col = piles[2][p3 - 1];
		f = false;
		new_bask = bask;
		for (int i = 0; i < (int) new_bask.size(); i++) {
			if (new_bask[i] == col) {
				new_bask.erase(new_bask.begin() + i);
				f = true;
				break;
			}
		}
		if (f) {
			op3 = 1 + calc(p1, p2, p3 - 1, p4, new_bask);
		} else {
			new_bask.push_back(col);
			op3 = calc(p1, p2, p3 - 1, p4, new_bask);
		}
	}
	if (p4) {
		col = piles[3][p4 - 1];
		f = false;
		new_bask = bask;
		for (int i = 0; i < (int) new_bask.size(); i++) {
			if (new_bask[i] == col) {
				new_bask.erase(new_bask.begin() + i);
				f = true;
				break;
			}
		}
		if (f) {
			op4 = 1 + calc(p1, p2, p3, p4 - 1, new_bask);
		} else {
			new_bask.push_back(col);
			op4 = calc(p1, p2, p3, p4 - 1, new_bask);
		}
	}
	return DP[p1][p2][p3][p4] = max(max(op1, op2), max(op3, op4));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	vector<int> empt;
	while(true) {
		cin >> N;
		if (!N) break;
		piles.assign(4, vector<int>(N, 0));
		DP.assign(N+1, vector<vector<vector<int>>>(N+1, vector<vector<int>>(N+1, vector<int>(N+1, -1))));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> piles[j][N-i-1];
			}
		}
		cout << max(0, calc(N, N, N, N, empt)) << "\n";
	}
	return 0;
}
