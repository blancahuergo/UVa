#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T, nPar, nEdge, V;
	long long capacity, plusINF = 100000000000000000LL, C;
	cin >> T;
	while(T--) {
		cin >> capacity >> nPar;
		vector<vector<long long>> adj_matrix(nPar+1, vector<long long>(nPar+1, plusINF));
		cin >> nEdge;
		while(nEdge--) {
			cin >> V;
			adj_matrix[0][V] = 0LL;
		}
		for (int n = 1; n <= nPar; n++) {
			cin >> nEdge;
			while(nEdge--) {
				cin >> C >> V;
				adj_matrix[n][V] = min(adj_matrix[n][V], C);
			}
		}
		for (int k = 0; k < nPar+1; k++) {
			adj_matrix[k][k] = 0;
			for (int i = 0; i < nPar+1; i++) {
				for (int j = 0; j < nPar+1; j++) {
					adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k]+adj_matrix[k][j]);
				}
			}
		}
		long long record = plusINF;
		for (int i = 1; i <= nPar; i++) {
			if (adj_matrix[0][i] == plusINF || adj_matrix[i][0] == plusINF) continue;
			record = min(record, adj_matrix[0][i]+adj_matrix[i][0]);
		}
		long long ans;
		if (record >= capacity) ans = 0;
		else {
			ans = 1;
			if ((capacity-record)%(record-1) == 0) ans += (capacity-record)/(record-1)-1;
			else ans += (capacity-record)/(record-1);
		}
		cout << ans << "\n";
	}
	return 0;
}
