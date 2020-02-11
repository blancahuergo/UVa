#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, tot;
	vector<int> rows;
	vector<int> cols;
	while(true) {
		cin >> n;
		if (!n) {
			break;
		}
		bool matrix[n][n];
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				cin >> matrix[r][c];
			}
		}
		rows.clear();
		for (int r = 0; r < n; r++) {
			tot = 0;
			for (int i = 0; i < n; i++) {
				tot += matrix[r][i];
			}
			if (tot % 2 == 1) {
				rows.push_back(r);
				if (rows.size() > 1) {
					break;
				}
			}
		}
		if (rows.size() > 1) {
			cout << "Corrupt" << endl;
			continue;
		}
		cols.clear();
		for (int c = 0; c < n; c++) {
			tot = 0;
			for (int i = 0; i < n; i++) {
				tot += matrix[i][c];
			}
			if (tot % 2 == 1) {
				cols.push_back(c);
				if (cols.size() > 1) {
					break;
				}
			}
		}
		if (cols.size() > 1) {
			cout << "Corrupt" << endl;
			continue;
		}
		if (rows.size() == 0 && cols.size() == 0) {
			cout << "OK" << endl;
		} else if (rows.size() == 1 && cols.size() == 1) {
			cout << "Change bit (" << (rows[0]+1) << "," << (cols[0]+1) << ")" << endl;
		} else {
			cout << "Corrupt" << endl;
		}
	}
	return 0;
}
