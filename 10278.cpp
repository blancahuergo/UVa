#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

unordered_set<int> stations;
vector<bool> isStation;
vector<vector<pair<int, int>>> adj_list;
vector<int> overallDist;

int Dijkstra(int S, int N) {
	vector<int> dist;
	dist.assign(N, 2000000000);
	dist[S] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, S});
	pair<int, int> cur, cur_v;
	int dis, u, v, ed_v;
	while(!pq.empty()) {
		cur = pq.top();
		pq.pop();
		dis = cur.first;
		u = cur.second;
		if (dis > dist[u]) continue;
		for (int i = 0; i < adj_list[u].size(); i++) {
			cur_v = adj_list[u][i];
			v = cur_v.first;
			ed_v = cur_v.second;
			if (dist[u]+ed_v < dist[v]) {
				dist[v] = dist[u]+ed_v;
				pq.push({dist[v], v});
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (!isStation[i])
			overallDist[i] = min(overallDist[i], dist[i]);
		ans = max(ans, overallDist[i]);
	}
	return ans;
}

int DijInter(int S, int N) {
	vector<int> dist;
	dist.assign(N, 2000000000);
	dist[S] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, S});
	pair<int, int> cur, cur_v;
	int dis, u, v, ed_v;
	while(!pq.empty()) {
		cur = pq.top();
		pq.pop();
		dis = cur.first;
		u = cur.second;
		if (dis > dist[u]) continue;
		for (int i = 0; i < adj_list[u].size(); i++) {
			cur_v = adj_list[u][i];
			v = cur_v.first;
			ed_v = cur_v.second;
			if (dist[u]+ed_v < dist[v]) {
				dist[v] = dist[u]+ed_v;
				pq.push({dist[v], v});
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, min(overallDist[i], dist[i]));
	}
	return ans;
}

int main() {
	int T, F, I, A, B, C;
	string line;
	stringstream ss;
	vector<pair<int, int>> empt;
	getline(cin, line);
	T = stoi(line);
	getline(cin, line);
	while(T--) {
		getline(cin, line);
		ss.str("");
		ss.clear();
		ss.str(line);
		ss >> F >> I;
		isStation.assign(I, false);
		stations.clear();
		for (int f = 0; f < F; f++) {
			getline(cin, line);
			stations.insert(stoi(line)-1);
			isStation[stoi(line)-1] = true;
		}
		adj_list.assign(I, empt);
		while(true) {
			getline(cin, line);
			ss.str("");
			ss.clear();
			ss.str(line);
			if (line.length() >= 4) {
				ss >> A >> B >> C;
				A--;
				B--;
				adj_list[A].push_back({B, C});
				adj_list[B].push_back({A, C});
			}
			else break;
		}
		overallDist.assign(I, 2000000000);
		int ans = 2000000000, fin_stat = 2000000000, cur;
		for (const auto& stat: stations) {
			overallDist[stat] = 0;
			cur = Dijkstra(stat, I);
			ans = min(ans, cur);
			fin_stat = min(fin_stat, stat+1);
		}
		for (int i = 0; i < I; i++) {
			if (isStation[i] == false) {
				cur = DijInter(i, I);
				if (cur < ans) {
					ans = cur;
					fin_stat = i+1;
				} else if (cur == ans) {
					fin_stat = min(fin_stat, i+1);
				}
			}
		}
		cout << fin_stat << "\n";
		if (T) cout << "\n";
	}
	return 0;
}
