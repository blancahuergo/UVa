#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

unordered_map<char, int> dict;

bool valid(string S) {
	stack<int> st;
	for (int i = 0; i < S.length(); i++) {
		if (dict.find(S[i]) == dict.end()) continue;
		if (st.size() == 0) {
			if (dict[S[i]] % 2 == 1)
				st.push(dict[S[i]]);
			else return false;
		} else if (st.top() == dict[S[i]] - 1 && dict[S[i]] % 2 == 0) st.pop();
		else if (dict[S[i]] % 2 == 1) st.push(dict[S[i]]);
		else return false;
	}
	if (st.size() == 0) return true;
	else return false;
}

int main() {
	int T;
	string line;
	dict['{'] = 1;
	dict['}'] = 2;
	dict['('] = 3;
	dict[')'] = 4;
	dict['['] = 5;
	dict[']'] = 6;
	getline(cin, line);
	T = stoi(line);
	while(T--) {
		getline(cin, line);
		if (valid(line)) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
