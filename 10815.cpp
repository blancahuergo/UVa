#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;

int main() {
	set<string> dict;
	string word;
	int i;
	char c;
	i = 0;
	word = "";
	while (c = getchar()) {
		if (c == EOF) break;
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			word += tolower(c);
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
