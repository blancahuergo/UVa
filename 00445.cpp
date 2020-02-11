#include <iostream>
using namespace std;

int main() {
	string line;
	char c;
	int i, count;
	while(getline(cin, line)) {
		if (line.length() == 0) {
			cout << "\n";
		} else {
			i = 0;
			count = 0;
			while (i < line.length()) {
				c = line[i];
				if (c >= '0' && c <= '9') {
					count += c - '0';
				} else if (c == '!') {
					cout << "\n";
				} else if (c == 'b') {
					for (int u = 0; u < count; u++) cout << ' ';
					count = 0;
				} else {
					for (int u = 0; u < count; u++) cout << c;
					count = 0;
				}
				i++;
			}
			if (c != '!') cout << "\n";
		}
	}
	return 0;
}
