#include <iostream>
#include <limits>
using namespace std;

int main() {
	long bottles[9];
	long cur, min_moves;
	string move;
	// Order: BGC
	while(cin >> bottles[0]) {
		for (int y = 1; y < 9; y++) cin >> bottles[y];
		min_moves = numeric_limits<long>::max();
		// BCG
		cur = bottles[3]+bottles[6]+bottles[2]+bottles[8]+bottles[1]+bottles[4];
		if (cur < min_moves) {
			min_moves = cur;
			move = "BCG";
		}
		// BGC
		cur = bottles[3]+bottles[6]+bottles[1]+bottles[7]+bottles[2]+bottles[5];
		if (cur < min_moves) {
			min_moves = cur;
			move = "BGC";
		}
		// CBG
		cur = bottles[5]+bottles[8]+bottles[0]+bottles[6]+bottles[1]+bottles[4];
		if (cur < min_moves) {
			min_moves = cur;
			move = "CBG";
		}
		// CGB
		cur = bottles[5]+bottles[8]+bottles[1]+bottles[7]+bottles[0]+bottles[3];
		if (cur < min_moves) {
			min_moves = cur;
			move = "CGB";
		}
		// GBC
		cur = bottles[4]+bottles[7]+bottles[0]+bottles[6]+bottles[2]+bottles[5];
		if (cur < min_moves) {
			min_moves = cur;
			move = "GBC";
		}
		// GCB
		cur = bottles[4]+bottles[7]+bottles[2]+bottles[8]+bottles[0]+bottles[3];
		if (cur < min_moves) {
			min_moves = cur;
			move = "GCB";
		}
		cout << move << " " << min_moves << endl;
	}
	return 0;
}
