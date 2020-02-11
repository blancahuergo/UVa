#include <iostream>
#include <vector>
using namespace std;

void fill_black(vector<bool> &photo, int p) {
	if (p > 340) {
		photo[p] = true;
		return;
	} else {
		photo[p] = true;
		fill_black(photo, 4*p+1);
		fill_black(photo, 4*p+2);
		fill_black(photo, 4*p+3);
		fill_black(photo, 4*p+4);
	}
}

void fill_empty(vector<bool> &photo, int p) {
	if (p > 340) {
		photo[p] = false;
		return;
	} else {
		photo[p] = false;
		fill_empty(photo, 4*p+1);
		fill_empty(photo, 4*p+2);
		fill_empty(photo, 4*p+3);
		fill_empty(photo, 4*p+4);
	}
}

int next_cursor(int p) {
	if(p % 4 == 0) p /= 4;
	if(p == 0) return -1;
	p++;
	return p;
}

void fill(vector<bool> &photo, string pH) {
	photo.assign(1365, false);
	int cursor = 0;
	int i = 0;
	while(i < pH.length()) {
		if (pH[i] == 'f') {
			fill_black(photo, cursor);
			cursor = next_cursor(cursor);
			if (cursor == -1) break;
		} else if (pH[i] == 'e') {
			fill_empty(photo, cursor);
			cursor = next_cursor(cursor);
			if (cursor == -1) break;
		} else {
			cursor = cursor*4+1;
		}
		i++;
	}
}

int merge(vector<bool> &ph1, vector<bool> &ph2) {
	int count = 0;
	for(int j = ph1.size()-1; j > ph1.size() - 1025; j--) {
		count += (ph1[j] || ph2[j]);
	}
	return count;
}

int main() {
	int N;
	string phA, phB;
	vector<bool> photo1, photo2;
	cin >> N;
	for (int y = 0; y < N; y++) {
		cin >> phA;
		photo1.clear();
		fill(photo1, phA);
		cin >> phB;
		photo2.clear();
		fill(photo2, phB);
		cout << "There are " << merge(photo1, photo2) << " black pixels." << endl;
	}
	return 0;
}
