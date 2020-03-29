#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	cout << fixed << setprecision(4);
	int T, N, x, y, plusINF = 1000000000;
	cin >> T;
	vector<pair<int, int>> points;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		points.clear();
		for (int n = 0; n < N; n++) {
			cin >> x >> y;
			points.push_back({x, y});
		}
		double adj_matrix[N][N];
		for (int i = 0; i < N; i++) {
			adj_matrix[i][i] = 0;
			for (int j = i+1; j < N; j++) {
				adj_matrix[i][j] = sqrt((points[i].first - points[j].first)*(points[i].first - points[j].first)+(points[i].second - points[j].second)*(points[i].second - points[j].second));
				adj_matrix[j][i] = adj_matrix[i][j];
				if (adj_matrix[i][j] > 10) {
					adj_matrix[i][j] = plusINF;
					adj_matrix[j][i] = plusINF;
				}
			}
		}
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k]+adj_matrix[k][j]);
				}
			}
		}
		double ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans = max(ans, adj_matrix[i][j]);
			}
		}
		cout << "Case #" << t << ":\n";
		if (ans == plusINF) cout << "Send Kurdy\n";
		else cout << ans << "\n";
		cout << "\n";
	}
	return 0;
}
