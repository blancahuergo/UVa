#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T, N, M, A, B, dist, time, plusINF=1000000000, Q, S, D;
	cin >> T;
	while(T--) {
		cin >> N >> M;
		vector<vector<int>> dist_matrix(N, vector<int>(N, plusINF));
		vector<vector<int>> time_matrix(N, vector<int>(N, plusINF));
		while(M--) {
			cin >> A >> B >> time >> dist;
			A--;
			B--;
			if (time < time_matrix[A][B]) {
				time_matrix[A][B] = time_matrix[B][A] = time;
				dist_matrix[A][B] = dist_matrix[B][A] = dist;
			} else if (time == time_matrix[A][B] && dist < dist_matrix[A][B]) {
				dist_matrix[A][B] = dist_matrix[B][A] = dist;
			}
		}
		for (int k = 0; k < N; k++) {
			time_matrix[k][k] = 0;
			dist_matrix[k][k] = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (time_matrix[i][j] > time_matrix[i][k]+time_matrix[k][j]) {
						time_matrix[i][j] = time_matrix[i][k]+time_matrix[k][j];
						dist_matrix[i][j] = dist_matrix[i][k]+dist_matrix[k][j];
					} else if (time_matrix[i][j] == time_matrix[i][k]+time_matrix[k][j]) {
						dist_matrix[i][j] = min(dist_matrix[i][j], dist_matrix[i][k]+dist_matrix[k][j]);
					}
				}
			}
		}
		cin >> Q;
		while(Q--) {
			cin >> S >> D;
			S--;
			D--;
			if (time_matrix[S][D] == plusINF) cout << "No Path.\n";
			else cout << "Distance and time to reach destination is " << dist_matrix[S][D] << " & " << time_matrix[S][D] << ".\n";
		}
		if(T) cout << "\n";
	}
	return 0;
}
