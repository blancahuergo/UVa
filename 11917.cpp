#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int cas, N, D, days;
	string subj;
	cin >> cas;
	for (int i = 1; i <= cas; i++) {
		cin >> N;
		unordered_map<string, int> subjects;
		for (int u = 0; u < N; u++) {
			cin >> subj >> days;
			subjects[subj] = days;
		}
		cin >> D;
		cin >> subj;
		cout << "Case " << i << ": ";
		if (subjects.find(subj) == subjects.end()) {
			cout << "Do your own homework!" << endl;
		} else if (subjects[subj] <= D) {
			cout << "Yesss" << endl;
		} else if (subjects[subj] <= D+5) {
			cout << "Late" << endl;
		} else {
			cout << "Do your own homework!" << endl;
		}
	}
	return 0;
}
