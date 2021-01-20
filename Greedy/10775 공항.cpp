#include <iostream>
#include <algorithm>
using namespace std;

int gate, plane;
int dock[100001];
bool used[100001];
int parent[100001];


int find(int x) {
	if (x == parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	parent[x] = y;
}

void input() {
	int docking, answer = 0;
	cin >> gate >> plane;
	for (int i = 1; i <= gate; i++)
		parent[i] = i;
	for (int i = 0; i < plane; i++) {
		cin >> docking;
		int empty = find(docking);
		if (empty == 0)
			break;
		else {
			answer++;
			merge(empty, empty - 1);
		}
	}
	cout << answer;
}

void solution() {
	int maxGate = dock[0];
	for (int i = 0; i < plane; i++) {
		if (maxGate <= i) {
			cout << i;
			break;
		}
		maxGate = max(maxGate, dock[i]);
		bool found = false;
		for (int j = dock[i]; j >= 1; j--) {
			if (!used[j]) {
				used[j] = true;
				found = true;
				break;
			}
		}
		if (!found) {
			cout << i;
			break;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();
	//solution();
	return 0;
}