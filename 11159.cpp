#include <iostream>
#include <vector>
using namespace std;

vector<int> setA, setB, match, vis;
vector<vector<int>> adj_list;
int N1, N2, N;

void buildG() {
	vector<int> empt;
	adj_list.assign(N, empt);
	for (int i = 0; i < N1; i++) {
		for (int j = 0; j < N2; j++) {
			if (setA[i] != 0) {
				if (setB[j] == 0 || setB[j] % setA[i] == 0) {
					adj_list[i].push_back(N1+j);
					adj_list[N1+j].push_back(i);
				}
			} else if (setB[j] == 0) {
				adj_list[i].push_back(N1+j);
				adj_list[N1+j].push_back(i);
			}
		}
	}
}

int Aug(int l) {
	if (vis[l]) return 0;
	vis[l] = 1;
	for (int j = 0; j < (int) adj_list[l].size(); j++) {
		int r = adj_list[l][j];
		if (match[r] == -1 || Aug(match[r])) {
			match[r] = l;
			return 1;
		}
	}
	return 0;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N1;
		setA.assign(N1, 0);
		for (int n1 = 0; n1 < N1; n1++) {
			cin >> setA[n1];
		}
		cin >> N2;
		setB.assign(N2, 0);
		for (int n2 = 0; n2 < N2; n2++) {
			cin >> setB[n2];
		}
		N = N1+N2;
		buildG();
		int MCBM = 0;
		match.assign(N, -1);
		for (int l = 0; l < N1; l++) {
			vis.assign(N, 0);
			MCBM += Aug(l);
		}
		cout << "Case " << t << ": " << MCBM << "\n";
	}
	return 0;
}
