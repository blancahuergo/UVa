#include <iostream>
using namespace std;

int main() {
	int cas, ans, n_stacks, tot, height;
	cas = 1;
	while (true) {
		cin >> n_stacks;
		if (!n_stacks) {
			break;
		}
		int stacks[n_stacks];
		tot = 0;
		for (int i = 0; i < n_stacks; i++) {
			cin >> stacks[i];
			tot += stacks[i];
		}
		height = tot/n_stacks;
		ans = 0;
		for (int j = 0; j < n_stacks; j++) {
			ans += abs(stacks[j]-height);
		}
		ans /= 2;
		cout << "Set #" << cas << endl;
		cout << "The minimum number of moves is " << ans << "." << endl;
		cout << "\n";
		cas++;
	}
	return 0;
}
