#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> adj_list;
unordered_map<string, int> dict;
unordered_map<int, string> dict_inv;
unordered_map<string, int> dictL;
vector<vector<int>> langWords;

int Dijkstra(int S, int D, int N) {
	int wrd, res = 2000000000, dis, nextwrd;
	vector<int> dist;
	dist.assign(N, 2000000000);
	priority_queue<pair<int, int>> Q;
	for (int i = 0; i < langWords[S].size(); i++) {
		wrd = langWords[S][i];
		dist[wrd] = dict_inv[wrd].length();
		Q.push({dist[wrd], wrd});
	}
	pair<int, int> cur;
	while(!Q.empty()) {
		cur = Q.top();
		Q.pop();
		wrd = cur.second;
		dis = cur.first;
		if (dis < dist[wrd]) continue;
		for (int i = 0; i < adj_list[wrd].size(); i++) {
			nextwrd = adj_list[wrd][i].first;
			if (dis + adj_list[wrd][i].second < dist[nextwrd]) {
				dist[nextwrd] = dis + adj_list[wrd][i].second;
				Q.push({dist[nextwrd], nextwrd});
			}
		}
	}
	for (int i = 0; i < langWords[D].size(); i++) {
		res = min(res, dist[langWords[D][i]]);
	}
	return res;
}

int main() {
	int M, l, w, w1, w2;
	string line, source, dest, lang1, lang2, word;
	stringstream ss;
	vector<int> empt;
	vector<pair<int, int>> empt2;
	while(true) {
		langWords.clear();
		dict.clear();
		dict_inv.clear();
		dictL.clear();
		getline(cin, line);
		M = stoi(line);
		if (!M) break;
		getline(cin, line);
		ss.str("");
		ss.clear();
		ss.str(line);
		ss >> source >> dest;
		dictL[source] = 0;
		dictL[dest] = 1;
		l = 2;
		w = 0;
		langWords.push_back(empt);
		langWords.push_back(empt);
		while(M--) {
			getline(cin, line);
			ss.str("");
			ss.clear();
			ss.str(line);
			ss >> lang1 >> lang2 >> word;
			if (dictL.find(lang1) == dictL.end()) {
				dictL[lang1] = l;
				langWords.push_back(empt);
				l++;
			}
			if (dictL.find(lang2) == dictL.end()) {
				dictL[lang2] = l;
				langWords.push_back(empt);
				l++;
			}
			if (dict.find(word) == dict.end()) {
				dict[word] = w;
				dict_inv[w] = word;
				w++;
			}
			langWords[dictL[lang1]].push_back(dict[word]);
			langWords[dictL[lang2]].push_back(dict[word]);
		}
		adj_list.assign(w, empt2);
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < langWords[i].size(); j++) {
				for (int k = j+1; k < langWords[i].size(); k++) {
					w1 = langWords[i][j];
					w2 = langWords[i][k];
					if (dict_inv[w1][0] == dict_inv[w2][0]) continue;
					adj_list[w1].push_back({w2, dict_inv[w2].length()});
					adj_list[w2].push_back({w1, dict_inv[w1].length()});
				}
			}
		}
		int ans = Dijkstra(dictL[source], dictL[dest], w);
		if (ans == 2000000000) cout << "impossivel\n";
		else cout << ans << "\n";
	}
	return 0;
}
