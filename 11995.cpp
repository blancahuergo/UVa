#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
	int n, inst, x;
	bool sta, que, pri;
	while(scanf("%d", &n) != EOF) {
		stack<int> st;
		queue<int> qu;
		priority_queue<int> pq;
		sta = true;
		que = true;
		pri = true;
		for (int u = 0; u < n; u++) {
			scanf("%d %d", &inst, &x);
			if (inst == 1) {
				st.push(x);
				qu.push(x);
				pq.push(x);
			} else {
				if (st.empty() || st.top() != x) {
					sta = false;
				}
				if (qu.empty() || qu.front() != x) {
					que = false;
				}
				if (pq.empty() || pq.top() != x) {
					pri = false;
				}
				if (st.size() >= 1) st.pop();
				else sta = false;
				if (qu.size() >= 1) qu.pop();
				else que = false;
				if (pq.size() >= 1) pq.pop();
				else pri = false;
			}
		}
		if (sta && !que && !pri) {
			cout << "stack" << endl;
		} else if (!sta && que && !pri) {
			cout << "queue" << endl;
		} else if (!sta && !que && pri) {
			cout << "priority queue" << endl;
		} else if (!sta && !que && !pri) {
			cout << "impossible" << endl;
		} else {
			cout << "not sure" << endl;
		}
	}
	return 0;
}
