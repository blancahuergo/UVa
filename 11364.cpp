#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int cases, n, cur;
	vector<int> places;
	cin >> cases;
	for (int u = 0; u < cases; u++) {
		cin >> n;
		places.clear();
		for (int r = 0; r < n; r++) {
			cin >> cur;
			places.push_back(cur);
		}
		sort(places.begin(), places.end());
		cout << (places[places.size()-1]-places[0])*2 << endl;
	}
	return 0;
}
