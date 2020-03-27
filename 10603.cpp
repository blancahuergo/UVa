#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void Dijkstra(int a, int b, int c, int d) {
	int N = max(max(a, b), c), tar = 0;
	vector<vector<int>> poured(N+1, vector<int>(N+1, 1000000000));
	vector<int> reachable(N+1, 1000000000);
	poured[0][0] = 0;
	queue<int> QA, QB, QC, QP;
	QA.push(0);
	QB.push(0);
	QC.push(c);
	QP.push(0);
	int c_a, c_b, c_c, c_p;
	while(!QA.empty()) {
		// 6 transitions
		c_p = QP.front();
		QP.pop();
		c_a = QA.front();
		QA.pop();
		c_b = QB.front();
		QB.pop();
		c_c = QC.front();
		QC.pop();
		reachable[c_a] = min(reachable[c_a], c_p);
		if (c_a <= d) tar = max(tar, c_a);
		reachable[c_b] = min(reachable[c_b], c_p);
		if (c_b <= d) tar = max(tar, c_b);
		reachable[c_c] = min(reachable[c_c], c_p);
		if (c_c <= d) tar = max(tar, c_c);
		// A->B
		if (c_a + c_b > b) {
			if (poured[c_a - (b - c_b)][b] > c_p + (b - c_b)) {
				poured[c_a - (b - c_b)][b] = c_p + (b - c_b);
				QP.push(c_p + (b - c_b));
				QA.push(c_a - (b - c_b));
				QB.push(b);
				QC.push(c_c);
			}
		} else {
			if (poured[0][c_a + c_b] > c_p + c_a) {
				poured[0][c_a + c_b] = c_p + c_a;
				QP.push(c_p + c_a);
				QA.push(0);
				QB.push(c_a + c_b);
				QC.push(c_c);
			}
		}
		// B->A
		if (c_a + c_b > a) {
			if (poured[a][c_b - (a - c_a)] > c_p + (a - c_a)) {
				poured[a][c_b - (a - c_a)] = c_p + (a - c_a);
				QA.push(a);
				QB.push(c_b - (a - c_a));
				QC.push(c_c);
				QP.push(c_p + (a - c_a));
			}
		} else {
			if (poured[c_a + c_b][0] > c_p + c_b) {
				poured[c_a + c_b][0] = c_p + c_b;
				QP.push(c_p + c_b);
				QA.push(c_a + c_b);
				QB.push(0);
				QC.push(c_c);
			}
		}
		// B->C
		if (c_b + c_c > c) {
			if (poured[c_a][c_b - (c - c_c)] > c_p + (c - c_c)) {
				poured[c_a][c_b - (c - c_c)] = c_p + (c - c_c);
				QP.push(c_p + (c - c_c));
				QA.push(c_a);
				QB.push(c_b - (c - c_c));
				QC.push(c);
			}
		} else {
			if (poured[c_a][0] > c_p + c_b) {
				poured[c_a][0] = c_p + c_b;
				QP.push(c_p + c_b);
				QA.push(c_a);
				QB.push(0);
				QC.push(c_b + c_c);
			}
		}
		// C->B
		if (c_b + c_c > b) {
			if (poured[c_a][b] > c_p + (b - c_b)) {
				poured[c_a][b] = c_p + (b - c_b);
				QP.push(c_p + (b - c_b));
				QA.push(c_a);
				QB.push(b);
				QC.push(c_c - (b - c_b));
			}
		} else {
			if (poured[c_a][c_b + c_c] > c_p + c_c) {
				poured[c_a][c_b + c_c] = c_p + c_c;
				QP.push(c_p + c_c);
				QA.push(c_a);
				QB.push(c_b + c_c);
				QC.push(0);
			}
		}
		// C->A
		if (c_a + c_c > a) {
			if (poured[a][c_b] > c_p + (a - c_a)) {
				poured[a][c_b] = c_p + (a - c_a);
				QP.push(c_p + (a - c_a));
				QA.push(a);
				QB.push(c_b);
				QC.push(c_c - (a - c_a));
			}
		} else {
			if (poured[c_a + c_c][c_b] > c_p + c_c) {
				poured[c_a + c_c][c_b] = c_p + c_c;
				QP.push(c_p + c_c);
				QA.push(c_a + c_c);
				QB.push(c_b);
				QC.push(0);
			}
		}
		// A->C
		if (c_a + c_c > c) {
			if (poured[c_a - (c - c_c)][c_b] > c_p + (c - c_c)) {
				poured[c_a - (c - c_c)][c_b] = c_p + (c - c_c);
				QP.push(c_p + (c - c_c));
				QA.push(c_a - (c - c_c));
				QB.push(c_b);
				QC.push(c);
			}
		} else {
			if (poured[0][c_b] > c_p + c_a) {
				poured[0][c_b] = c_p + c_a;
				QP.push(c_p + c_a);
				QA.push(0);
				QB.push(c_b);
				QC.push(c_a + c_c);
			}
		}
	}
	cout << reachable[tar] << " " << tar << "\n";
}

int main() {
	int T, a, b, c, d;
	cin >> T;
	while(T--) {
		cin >> a >> b >> c >> d;
		if (d >= c) {
			cout << "0 " << c << "\n";
			continue;
		}
		Dijkstra(a, b, c, d);
	}
	return 0;
}
