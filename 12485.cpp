#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, tot, ans, avg;
	vector<int> notes;
	while(cin >> N) {
		tot = 0;
		notes.assign(N, 0);
		for (int n = 0; n < N; n++) {
			cin >> notes[n];
			tot += notes[n];
		}
		if (tot % N != 0) {
			cout << "-1\n";
			continue;
		}
		avg = tot/N;
		ans = 0;
		for (int n = 0; n < N; n++) {
			ans += abs(notes[n]-avg);
		}
		cout << (1 + ans/2) << "\n";
	}
	return 0;
}
