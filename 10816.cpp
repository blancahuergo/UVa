#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<int> dist;
int N, temp, len;
vector<vector<vector<int>>> adj_list;
vector<int> path, predec, curT;

int Dijkstra(int S, int D, int R) {
	dist.assign(N, 2e9);
	dist[S] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({0, S});
	pair<int, int> cur;
	vector<int> cur_v;
	int u, v, tem, ed_v;
	curT.assign(N, 2e9);
	curT[S] = 0;
	while(!pq.empty()) {
		cur = pq.top();
		pq.pop();
		tem = cur.first;
		u = cur.second;
		if (tem > curT[u]) continue;
		for (int i = 0; i < (int) adj_list[u].size(); i++) {
			cur_v = adj_list[u][i];
			v = (int) cur_v[0];
			ed_v = cur_v[1];
			if (cur_v[2] > R) continue;
			if (curT[v] > max(curT[u], cur_v[2])) {
				dist[v] = dist[u]+ed_v;
				curT[v] = max(curT[u], cur_v[2]);
				pq.push({curT[v], v});
			} else if (curT[v] == max(curT[u], cur_v[2]) && dist[v] > dist[u]+ed_v) {
				dist[v] = dist[u]+ed_v;
			}
		}
	}
	if (dist[D] < 2e9) {
		len = dist[D];
		return curT[D];
	}
	else return -1;
}

void findPath(int S, int D, int R) {
	dist.assign(N, 2e9);
	dist[S] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({0, S});
	pair<int, int> cur;
	vector<int> cur_v;
	int u, v, dis, ed_v;
	predec.assign(N, -1);
	while(!pq.empty()) {
		cur = pq.top();
		pq.pop();
		dis = cur.first;
		u = cur.second;
		if (dis > dist[u]) continue;
		for (int i = 0; i < (int) adj_list[u].size(); i++) {
			cur_v = adj_list[u][i];
			v = (int) cur_v[0];
			ed_v = cur_v[1];
			if (cur_v[2] > R) continue;
			if (dist[v] > dist[u]+ed_v) {
				dist[v] = dist[u]+ed_v;
				predec[v] = u;
				pq.push({dist[v], v});
			}
		}
	}
	len = dist[D];
}

void storeRoute(int S, int D, int R) {
	findPath(S, D, R);
	path.clear();
	path.push_back(D+1);
	int cur = D;
	while(predec[cur] != -1) {
		cur = predec[cur];
		path.push_back(cur+1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M, S, D, A, B, lo, hi, mid, ans;
	double R, C;
	vector<vector<int>> empt;
	while(cin >> N >> M) {
		adj_list.assign(N, empt);
		cin >> S >> D;
		S--;
		D--;
		while(M--) {
			cin >> A >> B >> R >> C;
			adj_list[A-1].push_back({B-1, (int) (10*C), (int) (10*R)});
			adj_list[B-1].push_back({A-1, (int) (10*C), (int) (10*R)});
		}
		lo = 199;
		hi = 501;
		while(true) {
			mid = (lo + hi)/2;
			ans = Dijkstra(S, D, mid);
			if (ans == -1) lo = mid;
			else {
				hi = ans;
				temp = ans;
			}
			if (((lo + hi)/2) == mid) break;
		}
		storeRoute(S, D, temp);
		for (int i = (int) path.size() - 1; i > 0; i--) {
			printf("%d ", path[i]);
		}
		printf("%d\n", path[0]);
		printf("%d.%d %d.%d\n", len/10, len%10, temp/10, temp%10);
	}
	return 0;
}
