#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int students, cur, max_freq, max_occ;
	string code;
	while (true) {
		cin >> students;
		if (!students) break;
		unordered_map<string, int> freq;
		max_freq = 0;
		max_occ = 0;
		for (int i = 0; i < students; i++) {
			int cur_stud[5];
			for (int u = 0; u < 5; u++) {
				cin >> cur;
				cur_stud[u] = cur;
			}
			sort(cur_stud, cur_stud+5);
			code = to_string(cur_stud[0])+to_string(cur_stud[1])+to_string(cur_stud[2])+to_string(cur_stud[3])+to_string(cur_stud[4]);
			if (freq.find(code) == freq.end()) {
				freq[code] = 1;
			} else {
				freq[code]++;
			}
			if (freq[code] > max_freq) {
				max_freq = freq[code];
				max_occ = 1;
			} else if (freq[code] == max_freq) {
				max_occ++;
			}
		}
		cout << max_freq*max_occ << endl;
	}
	return 0;
}
