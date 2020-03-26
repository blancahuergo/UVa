#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

int make_num(vector<int> comb) {
	return 1000*comb[0]+100*comb[1]+10*comb[2]+comb[3];
}

vector<int> make_comb(int num) {
	vector<int> ret = {0, 0, 0, 0};
	ret[0] = num/1000;
	num %= 1000;
	ret[1] = num/100;
	num %= 100;
	ret[2] = num/10;
	num %= 10;
	ret[3] = num;
	return ret;
}

int main() {
	int T, N, cur_num, end_num, next_num;
	unordered_set<int> forbid;
	vector<int> start, target, cur_comb, next_comb, dist;
	start.assign(4, 0);
	target.assign(4, 0);
	cur_comb.assign(4, 0);
	cin >> T;
	while(T--) {
		cin >> start[0] >> start[1] >> start[2] >> start[3];
		cin >> target[0] >> target[1] >> target[2] >> target[3];
		cin >> N;
		forbid.clear();
		for (int n = 0; n < N; n++) {
			cin >> cur_comb[0] >> cur_comb[1] >> cur_comb[2] >> cur_comb[3];
			forbid.insert(make_num(cur_comb));
		}
		queue<int> Q;
		Q.push(make_num(start));
		dist.assign(10000, -1);
		dist[make_num(start)] = 0;
		end_num = make_num(target);
		while(!Q.empty()) {
			cur_num = Q.front();
			Q.pop();
			if (cur_num == end_num) break;
			cur_comb = make_comb(cur_num);
			for (int i = 0; i < 4; i++) {
				next_comb = cur_comb;
				if (next_comb[i] == 9) next_comb[i] = 0;
				else next_comb[i]++;
				next_num = make_num(next_comb);
				if (dist[next_num] == -1 && forbid.find(next_num) == forbid.end()) {
					dist[next_num] = dist[cur_num]+1;
					Q.push(next_num);
				}
				next_comb = cur_comb;
				if (next_comb[i] == 0) next_comb[i] = 9;
				else next_comb[i]--;
				next_num = make_num(next_comb);
				if (dist[next_num] == -1 && forbid.find(next_num) == forbid.end()) {
					dist[next_num] = dist[cur_num]+1;
					Q.push(next_num);
				}
			}
		}
		cout << dist[end_num] << "\n";
	}
	return 0;
}
