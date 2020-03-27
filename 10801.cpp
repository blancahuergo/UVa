#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

vector<int> times;
vector<vector<vector<int>>> adj_list;

int Dijkstra(int S, int N, int T) {
	vector<int> dist;
	dist.assign(N, 2000000000);
	dist[S] = 0;
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	pq.push({0, S, -1});
	vector<int> cur, cur_v;
	int dis, u, v, ed_v, elev_u, elev_v;
	while(!pq.empty()) {
		cur = pq.top();
		pq.pop();
		dis = cur[0];
		u = cur[1];
		elev_u = cur[2];
		if (dis > dist[u]) continue;
		for (int i = 0; i < adj_list[u].size(); i++) {
			cur_v = adj_list[u][i];
			v = cur_v[0];
			ed_v = cur_v[1];
			elev_v = cur_v[2];
			if (elev_u != -1 && elev_u != elev_v) ed_v += 60;
			if (dist[u]+ed_v < dist[v]) {
				dist[v] = dist[u]+ed_v;
				pq.push({dist[v], v, elev_v});
			}
		}
	}
	return dist[T];
}

int main() {
	int N, target, num;
	string line;
	stringstream ss;
	vector<int> curLine;
	vector<vector<int>> empt;
	while(getline(cin, line)) {
		ss.str("");
		ss.clear();
		ss.str(line);
		ss >> N >> target;
		adj_list.assign(100, empt);
		times.assign(N, 0);
		getline(cin, line);
		ss.str("");
		ss.clear();
		ss.str(line);
		for (int n = 0; n < N; n++) {
			ss >> times[n];
		}
		for (int n = 0; n < N; n++) {
			getline(cin, line);
			curLine.clear();
			ss.str("");
			ss.clear();
			ss.str(line);
			while(ss >> num) curLine.push_back(num);
			for (int i = 0; i < curLine.size(); i++) {
				for (int j = i+1; j < curLine.size(); j++) {
					vector<int> t = {curLine[j], (curLine[j]-curLine[i])*times[n], n};
					adj_list[curLine[i]].push_back(t);
					t[0] = curLine[i];
					adj_list[curLine[j]].push_back(t);
				}
			}
		}
		int ans = Dijkstra(0, 100, target);
		if (ans == 2000000000) cout << "IMPOSSIBLE\n";
		else cout << ans << "\n";
	}
	return 0;
}
