#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <sstream>
using namespace std;

vector<string> line1, line2;

void LCS() {
	int M = line1.size(), N = line2.size();
	int LCS[M+1][N+1];
	int predec[M+1][N+1];
	LCS[0][0] = 0;
	for (int i = 1; i <= M; i++) LCS[i][0] = 0;
	for (int j = 1; j <= N; j++) LCS[0][j] = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (line1[i-1] == line2[j-1]) {
				LCS[i][j] = LCS[i-1][j-1]+1;
				predec[i][j] = 1;
			}
			else {
				if (LCS[i][j-1] > LCS[i-1][j]) {
					LCS[i][j] = LCS[i][j-1];
					predec[i][j] = 2;
				} else {
					LCS[i][j] = LCS[i-1][j];
					predec[i][j] = 3;
				}
			}
		}
	}
	stack<int> indices;
	int i = M, j = N;
	while(i > 0 && j > 0) {
		if (predec[i][j] == 1) {
			indices.push(i-1);
			i--;
			j--;
		} else if (predec[i][j] == 3) i--;
		else j--;
	}
	cout << line1[indices.top()];
	indices.pop();
	while(!indices.empty()) {
		cout << " " << line1[indices.top()];
		indices.pop();
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string line, word;
	while(getline(cin, line)) {
		line1.clear();
		line2.clear();
		istringstream is(line);
		while(is>>word) line1.push_back(word);
		while(getline(cin, line)) {
			if(line == "#") break;
			istringstream is(line);
			while(is>>word) line1.push_back(word);
		}
		while(getline(cin, line)) {
			if(line == "#") break;
			istringstream is(line);
			while(is>>word) line2.push_back(word);
		}
		LCS();
	}
	return 0;
}
