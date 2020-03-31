#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cstring>
using namespace std;

unordered_map<string, int> dict;
unordered_map<int, string> dict_inv;
unordered_map<string, string> roads;
int plusINF = 1000000000;
vector<int> seq;
vector<vector<int>> adj_matrix, parent;
int c;

bool process() {
	int linelen, k, len;
	char line[100];
	gets(line);
	linelen = strlen(line);
	if (linelen < 3) return false;
    string A, B, road, num;
    k = 0;
	while (line[k]!=',') {
		A += line[k++];
	}
	k++;
	while (line[k]!=',') {
		B += line[k++];
	}
	k++;
	while (line[k]!=',') {
		road += line[k++];
	}
	k++;
	sscanf(line+k, "%d", &len);
	if (dict.find(A) == dict.end()) {
		dict[A] = c;
		dict_inv[c] = A;
		c++;
	}
	if (dict.find(B) == dict.end()) {
		dict[B] = c;
		dict_inv[c] = B;
		c++;
	}
	if (len < adj_matrix[dict[A]][dict[B]]) {
		adj_matrix[dict[B]][dict[A]] = adj_matrix[dict[A]][dict[B]] = len;
		roads[to_string(min(dict[A], dict[B])) + "," + to_string(max(dict[A], dict[B]))] = road;
	}
	return true;
}

void findPath(int i, int j) {
	if (i != j) findPath(i, parent[i][j]);
	seq.push_back(j);
}

bool process_query(string A, string B) {
	seq.clear();
	findPath(dict[A], dict[B]);
	cout << "\n\n";
	cout << "From                 To                   Route      Miles\n";
	cout << "-------------------- -------------------- ---------- -----\n";
	string ans, ans2;
	for (int i = 0; i < seq.size()-1; i++) {
		ans = dict_inv[seq[i]];
		while(ans.length() < 20) ans += " ";
		ans += " ";
		ans += dict_inv[seq[i+1]];
		while(ans.length() < 41) ans += " ";
		ans += " ";
		ans += roads[to_string(min(seq[i], seq[i+1]))+","+to_string(max(seq[i], seq[i+1]))];
		while(ans.length() < 52) ans += " ";
		ans += " ";
		ans2 = to_string(adj_matrix[seq[i]][seq[i+1]]);
		while(ans.length() + ans2.length() < 58) ans += " ";
		cout << ans << ans2 << "\n";
	}
	cout << "                                                     -----\n";
	ans = "  ";
	while (ans.length() < 42) ans += " ";
	ans += "Total     ";
	ans2 = to_string(adj_matrix[dict[A]][dict[B]]);
	while (ans.length() + ans2.length() < 58) ans += " ";
	cout << ans << ans2 << "\n";
	return true;
}

int main() {
	string line;
	vector<int> empt;
	empt.assign(102, plusINF);
	adj_matrix.assign(102, empt);
	parent = adj_matrix;
	c = 0;
	bool flag = true;
	while(flag) {
		flag = process();
	}
	for (int i = 0; i < c; i++)
		for (int j = 0; j < c; j++)
			parent[i][j] = i;
	for (int k = 0; k < c; k++) {
		adj_matrix[k][k] = 0;
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < c; j++) {
				if (adj_matrix[i][j] > adj_matrix[i][k]+adj_matrix[k][j]) {
					adj_matrix[i][j] = adj_matrix[i][k]+adj_matrix[k][j];
					parent[i][j] = parent[k][j];
				}
			}
		}
	}
	char s[100];
	string A, B;
	while(gets(s)) {
		A = B = "";
		int len = strlen(s), k = 0;
		while (s[k]!=',') {
			A += s[k++];
		}
		k++;
		while (k<len) B += s[k++];
		process_query(A, B);
	}
	return 0;
}
