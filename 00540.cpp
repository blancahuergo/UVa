#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

int main() {
	int teams, t_size, cur, team_affected, elem, cas;
	string inst;
	cas = 1;
	while(true) {
		cin >> teams;
		if (!teams) {
			break;
		}
		unordered_map<int, int> team_belong;
		for (int i = 0; i < teams; i++) {
			cin >> t_size;
			for (int t = 0; t < t_size; t++) {
				cin >> cur;
				team_belong[cur] = i;
			}
		}
		queue<int> team_queue;
		unordered_set<int> teams_enqueued;
		unordered_map<int, queue<int>> elems_in_queue;
		cout << "Scenario #" << cas << endl;
		while(true) {
			cin >> inst;
			if (inst[0] == 'S') {
				break;
			} else if (inst[0] == 'E') {
				cin >> cur;
				if (teams_enqueued.find(team_belong[cur]) == teams_enqueued.end()) {
					team_queue.push(team_belong[cur]);
					teams_enqueued.insert(team_belong[cur]);
					queue<int> empty;
					swap(elems_in_queue[team_belong[cur]], empty);
					elems_in_queue[team_belong[cur]].push(cur);
				} else {
					elems_in_queue[team_belong[cur]].push(cur);
				}
			} else {
				team_affected = team_queue.front();
				elem = elems_in_queue[team_affected].front();
				cout << elem << endl;
				elems_in_queue[team_affected].pop();
				if (elems_in_queue[team_affected].empty()) {
					team_queue.pop();
					teams_enqueued.erase(team_affected);
				}
			}
		}
		cout << "\n";
		cas++;
	}
	return 0;
}
