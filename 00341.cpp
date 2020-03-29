#include <iostream>
#include <vector>
using namespace std;

vector<int> sol;
vector<vector<int>> parent;

void printPath(int i, int j) {
	if (i != j) printPath(i, parent[i][j]);
	sol.push_back(j+1);
}

int main() {
	int NI, M, B, C, posINF = 1000000000, S, D;
	int t = 1;
	vector<int> empt;
	while(true) {
		cin >> NI;
		if (!NI) break;
		vector<vector<int>> adj_matrix(NI, vector<int>(NI, posINF));
		empt.assign(NI, 0);
		parent.assign(NI, empt);
		for (int n = 0; n < NI; n++) {
			adj_matrix[n][n] = 0;
			cin >> M;
			while(M--) {
				cin >> B >> C;
				adj_matrix[n][B-1] = C;
			}
		}
		for (int i = 0; i < NI; i++)
			for (int j = 0; j < NI; j++)
				parent[i][j] = i;
		cin >> S >> D;
		S--;
		D--;
		for (int k = 0; k < NI; k++)
			for (int i = 0; i < NI; i++)
				for (int j = 0; j < NI; j++) {
					if (adj_matrix[i][k]+adj_matrix[k][j] < adj_matrix[i][j]) {
						adj_matrix[i][j] = adj_matrix[i][k]+adj_matrix[k][j];
						parent[i][j] = parent[k][j];
					}
				}
		sol.clear();
		printPath(S, D);
		cout << "Case " << t << ": Path =";
		for (int i = 0; i < sol.size(); i++) cout << " " << sol[i];
		cout << "; " << adj_matrix[S][D] << " second delay\n";
		t++;
	}
	return 0;
}
