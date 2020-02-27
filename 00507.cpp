#include <iostream>
#include <vector>
using namespace std;

vector<int> values;

pair<int, int> nicePart() {
	pair<int, int> recordPoints = {-1, -1};
	int recordVal = 0, cur_tot = values[0], last_ind = 0;
	if (cur_tot > recordVal) {
		recordVal = cur_tot;
		recordPoints = {1, 2};
	}
	for (int i = 1; i < values.size(); i++) {
		if (cur_tot < 0) {
			cur_tot = values[i];
			last_ind = i;
		} else {
			cur_tot += values[i];
		}
		if (cur_tot > recordVal) {
			recordVal = cur_tot;
			recordPoints.first = last_ind+1;
			recordPoints.second = i+2;
		} else if (cur_tot == recordVal) {
			if (i+1 - last_ind > recordPoints.second - recordPoints.first) {
				recordPoints.first = last_ind+1;
				recordPoints.second = i+2;
			}
		}
	}
	return recordPoints;
}

int main() {
	int num_r, num_stops;
	pair<int, int> route;
	cin >> num_r;
	for (int cur_r = 1; cur_r <= num_r; cur_r++) {
		cin >> num_stops;
		values.assign(num_stops-1, 0);
		for (int s = 0; s < num_stops-1; s++) {
			cin >> values[s];
		}
		route = nicePart();
		if (route.first == -1) cout << "Route " << cur_r << " has no nice parts\n";
		else cout << "The nicest part of route " << cur_r << " is between stops " << route.first << " and " << route.second << endl;
	}
	return 0;
}
