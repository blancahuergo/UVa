#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
	int N, x1, x2, plusINF = 1000000000, A, B;
	string line;
	stringstream ss;
	vector<vector<int>> adj_matrix, new_matrix;
	vector<int> empt;
	while(true) {
		getline(cin, line);
		N = stoi(line);
		if (!N) break;
		empt.assign(N, plusINF);
		adj_matrix.assign(N, empt);
		new_matrix.assign(N, empt);
		for (int n = 0; n < N; n++) {
			adj_matrix[n][n] = 0;
			getline(cin, line);
			ss.str("");
			ss.clear();
			ss.str(line);
			ss >> x1;
			x1--;
			while(ss >> x2) adj_matrix[x1][x2-1] = 1;
		}
		for (int k = 0; k < N; k++)
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k]+adj_matrix[k][j]);
		for (int n = 0; n < N; n++) {
			new_matrix[n][n] = 0;
			getline(cin, line);
			ss.str("");
			ss.clear();
			ss.str(line);
			ss >> x1;
			x1--;
			while(ss >> x2) new_matrix[x1][x2-1] = 1;
		}
		for (int k = 0; k < N; k++)
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					new_matrix[i][j] = min(new_matrix[i][j], new_matrix[i][k]+new_matrix[k][j]);
		getline(cin, line);
		ss.str("");
		ss.clear();
		ss.str(line);
		ss >> A >> B;
		bool possible = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (new_matrix[i][j] > adj_matrix[i][j]*A+B) {
					possible = false;
					break;
				}
			}
			if (!possible) break;
		}
		if (possible) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
