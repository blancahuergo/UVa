#include <iostream>
#include <vector>
using namespace std;

vector<bool> treeA;
vector<bool> treeB;
int ind;

vector<int> children(int p) {
	vector<int> ret = {4*p - 2, 4*p - 1, 4*p, 4*p + 1};
	return ret;
}

void propagA(int p) {
	treeA[p] = true;
	if (4*p+1 >= treeA.size()) {
		return;
	}
	vector<int> p_c = children(p);
	propagA(p_c[0]);
	propagA(p_c[1]);
	propagA(p_c[2]);
	propagA(p_c[3]);
}

void propagB(int p) {
	treeB[p] = true;
	if (4*p+1 >= treeB.size()) {
		return;
	}
	vector<int> p_c = children(p);
	propagB(p_c[0]);
	propagB(p_c[1]);
	propagB(p_c[2]);
	propagB(p_c[3]);
}

void buildA(string path, int p) {
	if (path[ind] == 'f') {
		propagA(p);
		return;
	} else if (path[ind] == 'p') {
		vector<int> p_c = children(p);
		ind++;
		buildA(path, p_c[0]);
		ind++;
		buildA(path, p_c[1]);
		ind++;
		buildA(path, p_c[2]);
		ind++;
		buildA(path, p_c[3]);
		return;
	} else {
		return;
	}
}

void buildB(string path, int p) {
	if (path[ind] == 'f') {
		propagB(p);
		return;
	} else if (path[ind] == 'p') {
		vector<int> p_c = children(p);
		ind++;
		buildB(path, p_c[0]);
		ind++;
		buildB(path, p_c[1]);
		ind++;
		buildB(path, p_c[2]);
		ind++;
		buildB(path, p_c[3]);
		return;
	} else {
		return;
	}
}

int add() {
	int total = 0;
	for (int i = 342; i < treeA.size(); i++) {
		total += (treeA[i] || treeB[i]);
	}
	return total;
}

int main() {
	int N;
	string A, B;
	cin >> N;
	while(N--) {
		cin >> A;
		treeA.assign(1367, false);
		ind = 0;
		buildA(A, 1);
		cin >> B;
		treeB.assign(1367, false);
		ind = 0;
		buildB(B, 1);
		cout << "There are " << add() << " black pixels." << endl;
	}
	return 0;
}
