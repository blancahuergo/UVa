#include <iostream>
using namespace std;

int main() {
	int N, tot, am;
	string s;
	cin >> N;
	tot = 0;
	for (int u = 0; u < N; u++) {
		cin >> s;
		if (s == "report") {
			cout << tot << endl;
		} else {
			cin >> am;
			tot += am;
		}
	}
	return 0;
}
