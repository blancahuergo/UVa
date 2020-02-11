#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	int N, k;
	string nam;
	vector<string> names;
	cin >> N;
	for (int u = 0; u < N; u++) {
		cin >> nam;
		names.push_back(nam);
	}
	string song[] = {"Happy", "birthday", "to", "you",
			"Happy", "birthday", "to", "you",
			"Happy", "birthday", "to", "Rujia",
			"Happy", "birthday", "to", "you"};
	k = 1;
	while (16*k < N) {
		k++;
	}
	for (int w = 0; w < 16*k; w++) {
		cout << names[w%N] << ": " << song[w%16] << endl;
	}
	return 0;
}
