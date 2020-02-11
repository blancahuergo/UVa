#include <iostream>
using namespace std;

int main() {
	int total, i, cur_len;
	char c;
	string line;
	while(getline(cin, line)) {
		i = 0;
		cur_len = 0;
		total = 0;
		while(i < line.length()) {
			c = line[i];
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
				cur_len++;
			} else {
				if (cur_len > 0) {
					total++;
					cur_len = 0;
				}
			}
			i++;
		}
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) total++;
		cout << total << endl;
	}
	return 0;
}
