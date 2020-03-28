#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

vector<string> grid;
unordered_map<string, int> doorToID;
vector<int> times;

string getString(int r, int c) {
	string str = to_string(r);
	str += ",";
	str += to_string(c);
	return str;
}

int Dijkstra(int R, int C) {
	vector<vector<int>> dist(R, vector<int>(C, 2000000000));
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	dist[R - 1][0] = 0;
	pq.push( { 0, R - 1, 0 });
	vector<int> cur;
	int r, c, cur_dist, time;
	while (!pq.empty()) {
		cur = pq.top();
		pq.pop();
		cur_dist = cur[0];
		r = cur[1];
		c = cur[2];
		if (cur_dist > dist[r][c]) continue;
		if (grid[r][c] == '.') {
			if (r < R - 1 && (grid[r + 1][c] == '.' || grid[r + 1][c] == 'N')) {
				if (dist[r][c] + 1 < dist[r + 1][c]) {
					dist[r + 1][c] = dist[r][c] + 1;
					pq.push( { dist[r + 1][c], r + 1, c });
				}
			}
			if (r > 0 && (grid[r - 1][c] == '.' || grid[r - 1][c] == 'S')) {
				if (dist[r][c] + 1 < dist[r - 1][c]) {
					dist[r - 1][c] = dist[r][c] + 1;
					pq.push( { dist[r - 1][c], r - 1, c });
				}
			}
			if (c < C - 1 && (grid[r][c + 1] == '.' || grid[r][c + 1] == 'W')) {
				if (dist[r][c] + 1 < dist[r][c + 1]) {
					dist[r][c + 1] = dist[r][c] + 1;
					pq.push( { dist[r][c + 1], r, c + 1 });
				}
			}
			if (c > 0 && (grid[r][c - 1] == '.' || grid[r][c - 1] == 'E')) {
				if (dist[r][c] + 1 < dist[r][c - 1]) {
					dist[r][c - 1] = dist[r][c] + 1;
					pq.push( { dist[r][c - 1], r, c - 1 });
				}
			}
		} else {
			time = times[doorToID[getString(r, c)]];
			// add second for getting to next room
			if (grid[r][c] == 'N') {
				if (c > 0 && (grid[r][c - 1] == '.' || grid[r][c - 1] == 'E')) {
					if (dist[r][c] + time+1 < dist[r][c - 1]) {
						dist[r][c - 1] = dist[r][c] + time+1;
						pq.push( { dist[r][c - 1], r, c - 1 });
					}
				}
				if (c < C-1 && (grid[r][c + 1] == '.' || grid[r][c + 1] == 'W')) {
					if (dist[r][c] + time+1 < dist[r][c + 1]) {
						dist[r][c + 1] = dist[r][c] + time+1;
						pq.push( { dist[r][c + 1], r, c + 1 });
					}
				}
				if (r < R-1 && (grid[r + 1][c] == '.' || grid[r + 1][c] == 'N')) {
					if (dist[r][c] + 2 * time +1 < dist[r + 1][c]) {
						dist[r + 1][c] = dist[r][c] + 2 * time+1;
						pq.push( { dist[r + 1][c], r + 1, c });
					}
				}
			} else if (grid[r][c] == 'S') {
				if (c > 0 && (grid[r][c - 1] == '.' || grid[r][c - 1] == 'E')) {
					if (dist[r][c] + time+1 < dist[r][c - 1]) {
						dist[r][c - 1] = dist[r][c] + time+1;
						pq.push( { dist[r][c - 1], r, c - 1 });
					}
				}
				if (c < C-1 && (grid[r][c + 1] == '.' || grid[r][c + 1] == 'W')) {
					if (dist[r][c] + time+1 < dist[r][c + 1]) {
						dist[r][c + 1] = dist[r][c] + time+1;
						pq.push( { dist[r][c + 1], r, c + 1 });
					}
				}
				if (r > 0 && (grid[r-1][c] == '.' || grid[r-1][c] == 'S')) {
					if (dist[r][c] + 2*time+1 < dist[r-1][c]) {
						dist[r-1][c] = dist[r][c] + 2*time+1;
						pq.push({dist[r-1][c], r-1, c});
					}
				}
			} else if (grid[r][c] == 'W') {
				if (r > 0 && (grid[r-1][c] == '.' || grid[r-1][c] == 'S')) {
					if (dist[r][c]+time+1 < dist[r-1][c]) {
						dist[r-1][c] = dist[r][c]+time+1;
						pq.push({dist[r-1][c], r-1, c});
					}
				}
				if (r < R-1 && (grid[r+1][c] == '.' || grid[r+1][c] == 'N')) {
					if (dist[r][c]+time+1 < dist[r+1][c]) {
						dist[r+1][c] = dist[r][c]+time+1;
						pq.push({dist[r+1][c], r+1, c});
					}
				}
				if (c < C-1 && (grid[r][c+1] == '.' || grid[r][c+1] == 'W')) {
					if (dist[r][c] + 2*time+1 < dist[r][c+1]) {
						dist[r][c+1] = dist[r][c] + 2*time+1;
						pq.push({dist[r][c+1], r, c+1});
					}
				}
			} else {
				if (r > 0 && (grid[r-1][c] == '.' || grid[r-1][c] == 'S')) {
					if (dist[r][c]+time+1 < dist[r-1][c]) {
						dist[r-1][c] = dist[r][c]+time+1;
						pq.push({dist[r-1][c], r-1, c});
					}
				}
				if (r < R - 1 && (grid[r + 1][c] == '.' || grid[r + 1][c] == 'N')) {
					if (dist[r][c] + time+1 < dist[r + 1][c]) {
						dist[r + 1][c] = dist[r][c] + time+1;
						pq.push( { dist[r + 1][c], r + 1, c });
					}
				}
				if (c > 0 && (grid[r][c-1] == '.' || grid[r][c-1] == 'E')) {
					if (dist[r][c]+2*time+1 < dist[r][c-1]) {
						dist[r][c-1] = dist[r][c] + 2*time+1;
						pq.push({dist[r][c-1], r, c-1});
					}
				}
			}
		}
	}
	return dist[0][C - 1];
}

int main() {
	int T, R, C, D;
	string line;
	cin >> T;
	while (T--) {
		grid.clear();
		cin >> R >> C;
		D = 0;
		for (int r = 0; r < R; r++) {
			cin >> line;
			grid.push_back(line);
			for (int c = 0; c < C; c++) {
				if (grid[r][c] != '#' && grid[r][c] != '.') {
					doorToID[getString(r, c)] = D;
					D++;
				}
			}
		}
		times.assign(D, 0);
		for (int d = 0; d < D; d++)
			cin >> times[d];
		int ans = Dijkstra(R, C);
		if (ans == 2000000000)
			cout << "Poor Kianoosh\n";
		else
			cout << ans << "\n";
	}
	return 0;
}
