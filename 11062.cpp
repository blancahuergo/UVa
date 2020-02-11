#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;

int main() {
	set<string> dict;
	string word;
	char c;
	bool hyp;
	word = "";
	hyp = false;
	while (c = getchar()) {
		if (c == EOF) break;
		if (c == '\n') {
			if (!hyp) {
				if (word.length() >= 1)
					dict.insert(word);
				word = "";
			} else {
				hyp = false;
			}
		} else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			if (hyp) {
				word += '-';
			}
			word += tolower(c);
			hyp = false;
		} else if (c == '-') {
			hyp = true;
		} else {
			if (word.length() >= 1) {
				dict.insert(word);
			}
			word = "";
		}
	}
	for (auto it = dict.begin(); it != dict.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
