#include <iostream>
using namespace std;

int main() {
	int cases, stations, counter, cur_cas;
	bool possible;
	cin >> cases;
	cur_cas = 1;
	while (cases) {
		cin >> stations;
		int recharge[stations];
		int needed[stations];
		for (int i = 0; i < stations; i++) {
			cin >> recharge[i];
		}
		for (int i = 0; i < stations; i++) {
			cin >> needed[i];
		}
		counter = 0;
		for (int i = 0; i < stations; i++) {
			counter += recharge[i];
			counter -= needed[i];
			//
		}
		cases--;
		cur_cas++;
	}
	return 0;
}
