#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, plusINF = 1000000000, C, init1, init2;
	string state, dir, X, Y, init_Y, init_M;
	while(true) {
		cin >> N;
		if (!N) break;
		vector<vector<int>> Y_matrix(26, vector<int>(26, plusINF));
		vector<vector<int>> M_matrix(26, vector<int>(26, plusINF));
		for (int n = 0; n < N; n++) {
			cin >> state >> dir >> X >> Y >> C;
			if (state[0] == 'Y') {
				Y_matrix[X[0] - 'A'][Y[0] - 'A'] = C;
				if (dir[0] == 'B') {
					Y_matrix[Y[0] - 'A'][X[0] - 'A'] = C;
				}
			} else {
				M_matrix[X[0] - 'A'][Y[0] - 'A'] = C;
				if (dir[0] == 'B') {
					M_matrix[Y[0] - 'A'][X[0] - 'A'] = C;
				}
			}
		}
		for (int k = 0; k < 26; k++) {
			Y_matrix[k][k] = 0;
			M_matrix[k][k] = 0;
			for (int i = 0; i < 26; i++) {
				for (int j = 0; j < 26; j++) {
					Y_matrix[i][j] = min(Y_matrix[i][j], Y_matrix[i][k] + Y_matrix[k][j]);
					M_matrix[i][j] = min(M_matrix[i][j], M_matrix[i][k] + M_matrix[k][j]);
				}
			}
		}
		cin >> init_Y >> init_M;
		init1 = init_Y[0] - 'A';
		init2 = init_M[0] - 'A';
		int ans = plusINF;
		vector<int> locs;
		for (int i = 0; i < 26; i++) {
			int cur = Y_matrix[init1][i] + M_matrix[init2][i];
			if (cur < ans) {
				ans = cur;
				locs.clear();
				locs.push_back(i);
			} else if (cur == ans) {
				locs.push_back(i);
			}
		}
		if (ans == plusINF) cout << "You will never meet.\n";
		else {
			cout << ans;
			for (int i = 0; i < locs.size(); i++) {
				cout << " " << ((char) ('A' + locs[i]));
			}
			cout << "\n";
		}
	}
	return 0;
}
