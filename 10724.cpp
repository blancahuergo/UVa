#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<pair<int, int>> points;
int dist(int i, int j) {
	return (points[i].first - points[j].first)*(points[i].first - points[j].first) + (points[i].second - points[j].second)*(points[i].second - points[j].second);
}

int main() {
	int N, M, x, y, u, v, plusINF = 1000000000, A, B;
	double cur_cost, record_cost, cur_road, dist_bet;
	while(true) {
		cin >> N >> M;
		points.clear();
		if (!(N||M)) break;
		for (int n = 0; n < N; n++) {
			cin >> x >> y;
			points.push_back({x, y});
		}
		vector<vector<double>>adj_matrix(N, vector<double>(N, plusINF));
		while(M--) {
			cin >> u >> v;
			u--;
			v--;
			adj_matrix[u][v] = adj_matrix[v][u] = sqrt((double) dist(u, v));
		}
		for (int k = 0; k < N; k++) {
			adj_matrix[k][k] = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k]+adj_matrix[k][j]);
				}
			}
		}
		vector<vector<double>> new_matrix;
		record_cost = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				cur_road = sqrt((double) dist(i, j));
				if (cur_road >= adj_matrix[i][j]) continue;
				new_matrix = adj_matrix;
				new_matrix[i][j] = new_matrix[j][i] = cur_road;
				for (int k = 0; k < N; k++) {
					new_matrix[k][k] = 0;
					for (int a = 0; a < N; a++) {
						for (int b = 0; b < N; b++) {
							new_matrix[a][b] = min(new_matrix[a][b], new_matrix[a][k]+new_matrix[k][b]);
						}
					}
				}
				cur_cost = 0;
				for (int a = 0; a < N; a++) {
					for (int b = 0; b < N; b++) {
						cur_cost += adj_matrix[a][b] - new_matrix[a][b];
					}
				}
				if (cur_cost > record_cost) {
					record_cost = cur_cost;
					A = i+1;
					B = j+1;
					dist_bet = new_matrix[i][j];
				} else if (cur_cost > 0 && cur_cost == record_cost && new_matrix[i][j] < dist_bet) {
					dist_bet = new_matrix[i][j];
					A = i+1;
					B = j+1;
				}
			}
		}
		if (record_cost <= 1) cout << "No road required\n";
		else cout << A << " " << B << "\n";
	}
	return 0;
}
