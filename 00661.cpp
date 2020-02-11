#include <iostream>
using namespace std;

int main() {
	int devices, operations, capacity, dev, cur, max_val;
	int cas = 1;
	while(true) {
		cin >> devices >> operations >> capacity;
		if (!(devices || operations || capacity)) {
			break;
		}
		int capacities[devices];
		bool state[devices];
		for (int i = 0; i < devices; i++) {
			cin >> capacities[i];
			state[i] = 0;
		}
		cur = 0;
		max_val = 0;
		for (int i = 0; i < operations; i++) {
			cin >> dev;
			state[dev-1] = !(state[dev-1]);
			if (state[dev-1]) {
				cur += capacities[dev-1];
				if (cur > max_val) {
					max_val = cur;
				}
			} else {
				cur -= capacities[dev-1];
			}
		}
		if (max_val > capacity) {
			cout << "Sequence " << cas << endl;
			cout << "Fuse was blown." << endl;
		} else {
			cout << "Sequence " << cas << endl;
			cout << "Fuse was not blown." << endl;
			cout << "Maximal power consumption was " << max_val << " amperes." << endl;
		}
		cout << "\n";
		cas++;
	}
	return 0;
}
