#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	int bord, enem, plusINF = 2000000, Q, A, B;
	int t = 1;
	while(cin >> bord) {
		vector<vector<int>> adj_matrix(20, vector<int>(20, plusINF));
		while(bord--) {
			cin >> enem;
			adj_matrix[0][enem-1] = 1;
			adj_matrix[enem-1][0] = 1;
		}
		for (int i = 1; i < 19; i++) {
			cin >> bord;
			while(bord--) {
				cin >> enem;
				adj_matrix[i][enem-1] = 1;
				adj_matrix[enem-1][i] = 1;
			}
		}
		for (int k = 0; k < 20; k++) {
			adj_matrix[k][k] = 0;
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 20; j++) {
					adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k]+adj_matrix[k][j]);
				}
			}
		}
		cin >> Q;
		cout << "Test Set #" << t << "\n";
		while(Q--) {
			cin >> A >> B;
			cout << setw(2) << A << " to " << setw(2) << B << ": " << adj_matrix[A-1][B-1] << "\n";
		}
		t++;
		cout << "\n";
	}
	return 0;
}
