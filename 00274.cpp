#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

vector<vector<int>> cat, mouse;
vector<int> empt;
vector<bool> c_vis, m_vis;
int MH;

void catDFS(int S) {
	c_vis[S] = true;
	for (int i = 0; i < (int) cat[S].size(); i++) {
		int v = cat[S][i];
		if (!c_vis[v]) catDFS(v);
	}
}

void mouseDFS(int S) {
	m_vis[S] = true;
	for (int i = 0; i < (int) mouse[S].size(); i++) {
		int v = mouse[S][i];
		if (!m_vis[v]) mouseDFS(v);
	}
}

bool retHome(int u) {
	m_vis[u] = true;
	if (c_vis[u]) return false;
	if (u == MH) return true;

	bool ret = false;
	for (int i = 0; i < (int) mouse[u].size(); i++) {
		int v = mouse[u][i];
		if (!m_vis[v])
			ret = retHome(v);
		if (ret) break;
	}
	return ret;
}

int main() {
	int T, N, CH, A, B;
	string line;
	stringstream ss;
	getline(cin, line);
	T = stoi(line);
	getline(cin, line);
	while(T--) {
		getline(cin, line);
		ss.str("");
		ss.clear();
		ss.str(line);
		ss >> N >> CH >> MH;
		CH--;
		MH--;
		mouse.assign(N, empt);
		cat.assign(N, empt);
		while(true) {
			getline(cin, line);
			ss.str("");
			ss.clear();
			ss.str(line);
			ss >> A >> B;
			if (A == -1) break;
			cat[A-1].push_back(B-1);
		}
		while(true) {
			getline(cin, line);
			if (line.length() < 3) break;
			ss.str("");
			ss.clear();
			ss.str(line);
			ss >> A >> B;
			mouse[A-1].push_back(B-1);
		}
		c_vis.assign(N, false);
		m_vis.assign(N, false);
		catDFS(CH);
		mouseDFS(MH);
		bool first = false;
		for (int i = 0; i < N; i++) {
			if (m_vis[i] && c_vis[i]) {
				first = true;
				break;
			}
		}
		bool second = false;
		m_vis.assign(N, false);
		for (int i = 0; i < (int) mouse[MH].size(); i++) {
			if (!m_vis[mouse[MH][i]])
				second = retHome(mouse[MH][i]);
			if (second) break;
		}
		if (first) cout << "Y ";
		else cout << "N ";
		if (second) cout << "Y\n";
		else cout << "N\n";
		if(T) cout << "\n";
	}
	return 0;
}
