#include <iostream>
using namespace std;

int main() {
	int n, jump;
	int start, end;
	char temp;
	string s;
	while (true) {
		cin >> n;
		if (!n) {
			break;
		}
		cin >> s;
		jump = s.length()/n;
		for (int i = 0; i < s.length(); i+=jump) {
			start = i;
			end = i+jump-1;
			while (start < end) {
				temp = s[start];
				s[start] = s[end];
				s[end] = temp;
				start++;
				end--;
			}
		}
		cout << s << endl;
	}
	return 0;
}
