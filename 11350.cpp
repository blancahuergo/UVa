#include <iostream>
#include <vector>
using namespace std;

pair<long, long> mediant(pair<long, long> f, pair<long, long> s) {
	pair<long, long> ret;
	ret.first = f.first + s.first;
	ret.second = f.second + s.second;
	return ret;
}

vector<pair<long, long>> next_row (vector<pair<long, long>> past_row, char quer) {
	vector<pair<long, long>> row;
	pair<long, long> empty;
	row.assign(3, empty);
	if (quer == 'L') {
		row[0] = past_row[0];
		row[1] = mediant(past_row[0], past_row[1]);
		row[2] = past_row[1];
	} else if (quer == 'R') {
		row[0] = past_row[1];
		row[1] = mediant(past_row[1], past_row[2]);
		row[2] = past_row[2];
	}
	return row;
}

pair<long, long> query (string path) {
	vector<pair<long, long>> last;
	pair<long, long> empty = {1, 1};
	last.assign(3, empty);
	last[0].first = 0;
	last[2].second = 0;
	for (int i = 0; i < path.length(); i++) {
		last = next_row(last, path[i]);
	}
	return last[1];
}

int main() {
	int Q;
	string path;
	cin >> Q;
	for (int q = 0; q < Q; q++) {
		cin >> path;
		pair<long, long> fract = query(path);
		cout << fract.first << "/" << fract.second << endl;
	}
	return 0;
}
