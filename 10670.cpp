#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> names;

vector<string> process(string line) {
	vector<string> ret;
	int i;
	string cur = "";
	for (i = 0; i < line.length(); i++) {
		if (line[i] == ':') break;
		cur += line[i];
	}
	ret.push_back(cur);
	i++;
	cur = "";
	while(i < line.length()) {
		if (line[i] == ',') break;
		cur += line[i];
		i++;
	}
	ret.push_back(cur);
	cur = "";
	i++;
	while(line[i] >= '0' && line[i] <= '9') {
		cur += line[i];
		i++;
	}
	ret.push_back(cur);
	return ret;
}

bool comp(pair<int, int> P1, pair<int, int> P2) {
	if (P1.first < P2.first) return true;
	if (P2.first < P1.first) return false;
	return names[P1.second] < names[P2.second];
}

int main() {
	string line;
	getline(cin, line);
	int T = stoi(line), N, M, L;
	stringstream ss;
	vector<string> cur;
	vector<pair<int, int>> AG;
	for (int cas = 1; cas <= T; cas++) {
		getline(cin, line);
		ss.str("");
		ss.clear();
		ss.str(line);
		ss >> N >> M >> L;
		names.clear();
		AG.assign(L, {0, 0});
		for (int l = 0; l < L; l++) {
			getline(cin, line);
			cur = process(line);
			names.push_back(cur[0]);
			int one = stoi(cur[1]);
			int half = stoi(cur[2]);
			int am = N, cost = 0;
			while(am != M) {
				if (am/2 >= M && half <= (am-(am/2))*one) {
					cost += half;
					am/=2;
				} else {
					cost += one;
					am--;
				}
			}
			AG[l] = {cost, l};
		}
		sort(AG.begin(), AG.end(), comp);
		cout << "Case " << cas << "\n";
		for (int l = 0; l < L; l++) cout << names[AG[l].second] << " " << AG[l].first << "\n";
	}
	return 0;
}
