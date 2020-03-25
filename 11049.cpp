#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> walls = {{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0}};

bool are_sep(pair<int, int> A, pair<int, int> B) {
	if (A.first == B.first) {
		if (A.second > B.second) {
			int temp = B.second;
			B.second = A.second;
			A.second = temp;
		}
	} else {
		if (A.first > B.first) {
			int temp = B.first;
			B.first = A.first;
			A.first = temp;
		}
	}
	for (int w = 0; w < 3; w++) {
		if (walls[w][0] == walls[w][2]) {
			if (A.first == B.first) continue;
			if (A.first == walls[w][0] - 1 && B.first == walls[w][0] && walls[w][1] <= A.second && A.second < walls[w][3]) return true;
		} else {
			if (A.second == B.second) continue;
			if (A.second == walls[w][1] - 1 && B.second == walls[w][1] && walls[w][0] <= A.first && A.first < walls[w][2]) return true;
		}
	}
	return false;
}

int main() {
	int x, y;
	pair<int, int> S, D;
	vector<int> empt;
	empt.assign(6, -1);
	vector<vector<int>> predec;
	while(true) {
		cin >> x >> y;
		if (!(x||y)) break;
		predec.assign(6, empt);
		S = make_pair(x-1, y-1);
		cin >> x >> y;
		D = make_pair(x-1, y-1);
		cin >> walls[0][0] >> walls[0][1] >> walls[0][2] >> walls[0][3];
		cin >> walls[1][0] >> walls[1][1] >> walls[1][2] >> walls[1][3];
		cin >> walls[2][0] >> walls[2][1] >> walls[2][2] >> walls[2][3];
		queue<pair<int, int>> Q;
		Q.push(S);
		predec[S.first][S.second] = 4;
		while(!Q.empty()) {
			S = Q.front();
			Q.pop();
			if (S.first == D.first && S.second == D.second) break;
			if (S.first > 0 && !(are_sep(S, {S.first-1, S.second}) || predec[S.first-1][S.second] != -1)) {
				predec[S.first-1][S.second] = 0;
				Q.push({S.first - 1, S.second});
			}
			if (S.first < 5 && !(are_sep(S, {S.first+1, S.second}) || predec[S.first+1][S.second] != -1)) {
				predec[S.first+1][S.second] = 1;
				Q.push({S.first+1, S.second});
			}
			if (S.second > 0 && !(are_sep(S, {S.first, S.second-1}) || predec[S.first][S.second-1] != -1)) {
				predec[S.first][S.second-1] = 2;
				Q.push({S.first, S.second-1});
			}
			if (S.second < 5 && !(are_sep(S, {S.first, S.second+1}) || predec[S.first][S.second+1] != -1)) {
				predec[S.first][S.second+1] = 3;
				Q.push({S.first, S.second+1});
			}
		}
		pair<int, int> cur = D;
		string ans = "";
		while(true) {
			if (predec[cur.first][cur.second] == 0) {
				ans += 'W';
				cur.first++;
			} else if (predec[cur.first][cur.second] == 1) {
				ans += 'E';
				cur.first--;
			} else if (predec[cur.first][cur.second] == 2) {
				ans += 'N';
				cur.second++;
			} else if (predec[cur.first][cur.second] == 3) {
				ans += 'S';
				cur.second--;
			} else {
				break;
			}
		}
		for (int i = ans.length()-1; i >= 0; i--) cout << ans[i];
		cout << "\n";
	}
	return 0;
}
