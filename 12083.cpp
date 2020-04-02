#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> music_dict, sport_dict;
vector<int> height, music, sport, gender, match, vis;
int m, s;
vector<vector<int>> adj_list;

void reset(int N) {
	music_dict.clear();
	sport_dict.clear();
	height.assign(N, 0);
	music.assign(N, 0);
	sport.assign(N, 0);
	gender.assign(N, 0);
	vector<int> empt;
	adj_list.assign(N, empt);
	m = 0;
	s = 0;
}

bool couple(int i, int j) {
	if (gender[i] == gender[j] || abs(height[i]-height[j]) > 40 || music[i] != music[j] || sport[i] == sport[j]) return false;
	return true;
}

void buildG(int N) {
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (couple(i, j)) {
				adj_list[i].push_back(j);
				adj_list[j].push_back(i);
			}
		}
	}
}

int Aug(int l) {
	if (vis[l]) return 0;
	vis[l] = 1;
	for (int j = 0; j < (int) adj_list[l].size(); j++) {
		int r = adj_list[l][j];
		if (match[r] == -1 || Aug(match[r])) {
			match[r] = l;
			return 1;
		}
	}
	return 0;
}

int main() {
	int T, N, h, men;
	string gend, mus, spo;
	cin >> T;
	while(T--) {
		cin >> N;
		reset(N);
		men = 0;
		for (int n = 0; n < N; n++) {
			cin >> h >> gend >> mus >> spo;
			height[n] = h;
			if (gend[0] == 'M') {
				gender[n] = 1;
				men++;
			}
			else gender[n] = 0;
			if (music_dict.find(mus) == music_dict.end())
				music_dict[mus] = m++;
			if (sport_dict.find(spo) == sport_dict.end())
				sport_dict[spo] = s++;
			music[n] = music_dict[mus];
			sport[n] = sport_dict[spo];
		}
		buildG(N);
		int MCBM = 0;
		match.assign(N, -1);
		for (int l = 0; l < N; l++) {
			if (gender[l] == 0) continue;
			vis.assign(N, 0);
			MCBM += Aug(l);
		}
		cout << N - MCBM << endl;
	}
	return 0;
}
