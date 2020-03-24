#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> grid, dist;
vector<vector<bool>> visited;
vector<int> empt;
vector<bool> empt2;

int main() {
	int R, C, num_R, cur_R, cur_B, c, x, y;
	pair<int, int> start_pos, end_pos, cur_pos;
	while(true) {
		cin >> R >> C;
		if (!(R||C)) break;
		empt.assign(C, -1);
		empt2.assign(C, false);
		grid.assign(R, empt);
		dist.assign(R, empt);
		visited.assign(R, empt2);
		cin >> num_R;
		while(num_R--) {
			cin >> cur_R >> cur_B;
			while(cur_B--) {
				cin >> c;
				grid[cur_R][c] = 1;
			}
		}
		cin >> x >> y;
		start_pos = make_pair(x, y);
		cin >> x >> y;
		end_pos = make_pair(x, y);
		queue<pair<int, int>> Q;
		dist[start_pos.first][start_pos.second] = 0;
		visited[start_pos.first][start_pos.second] = true;
		Q.push(start_pos);
		while(!Q.empty()) {
			cur_pos = Q.front();
			Q.pop();
			if (cur_pos.first == end_pos.first && cur_pos.second == end_pos.second) break;
			if (cur_pos.first < R-1) {
				if (!visited[cur_pos.first+1][cur_pos.second] && grid[cur_pos.first+1][cur_pos.second] != 1) {
					visited[cur_pos.first+1][cur_pos.second] = true;
					dist[cur_pos.first+1][cur_pos.second] = dist[cur_pos.first][cur_pos.second]+1;
					Q.push(make_pair(cur_pos.first+1, cur_pos.second));
				}
			}
			if (cur_pos.first > 0) {
				if (!visited[cur_pos.first-1][cur_pos.second] && grid[cur_pos.first-1][cur_pos.second] != 1) {
					visited[cur_pos.first-1][cur_pos.second] = true;
					dist[cur_pos.first-1][cur_pos.second] = dist[cur_pos.first][cur_pos.second]+1;
					Q.push(make_pair(cur_pos.first-1, cur_pos.second));
				}
			}
			if (cur_pos.second < C-1) {
				if (!visited[cur_pos.first][cur_pos.second+1] && grid[cur_pos.first][cur_pos.second+1] != 1) {
					visited[cur_pos.first][cur_pos.second+1] = true;
					dist[cur_pos.first][cur_pos.second+1] = dist[cur_pos.first][cur_pos.second]+1;
					Q.push(make_pair(cur_pos.first, cur_pos.second+1));
				}
			}
			if (cur_pos.second > 0) {
				if (!visited[cur_pos.first][cur_pos.second-1] && grid[cur_pos.first][cur_pos.second-1] != 1) {
					visited[cur_pos.first][cur_pos.second-1] = true;
					dist[cur_pos.first][cur_pos.second-1] = dist[cur_pos.first][cur_pos.second]+1;
					Q.push(make_pair(cur_pos.first, cur_pos.second-1));
				}
			}
		}
		cout << dist[end_pos.first][end_pos.second] << "\n";
	}
	return 0;
}
