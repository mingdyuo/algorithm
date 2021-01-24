#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int vertexCount, edgeCount, blueCount;
vector<pair<int, int>> tree[1002];
bool visited[1002];

void solution();

void input() {
	while (true) {
		cin >> vertexCount >> edgeCount >> blueCount;
		if (!vertexCount && !edgeCount && !blueCount) break;
		for (int i = 1; i <= vertexCount; i++) tree[i].clear();
		char color;
		int head, tail;
		for (int i = 0; i < edgeCount; i++) {
			cin >> color >> head >> tail;
			int cost = color == 'B' ? 1 : 0;
			tree[head].push_back({ cost, tail });
			tree[tail].push_back({ cost, head });
		}
		solution();
	}
}

void solution() {
	memset(visited, false, sizeof(visited));
	priority_queue<pair<int, int>> pq;
	visited[1] = true;
	for (auto elem : tree[1]) {
		pq.push({elem.first, elem.second});
	}
	int minCost = 0, maxCost = 0;
	while (!pq.empty()) {
		int cost = pq.top().first, dst = pq.top().second;
		pq.pop(); 
		if (visited[dst]) continue;
		visited[dst] = true;
		maxCost += cost;
		for (auto next : tree[dst]) {
			if (!visited[next.second])
				pq.push({ next.first, next.second });
		}
	}
	memset(visited, false, sizeof(visited));
	visited[1] = true;
	for (auto elem : tree[1]) {
		pq.push({ -elem.first, elem.second });
	}
	while (!pq.empty()) {
		int cost = -pq.top().first, dst = pq.top().second;
		pq.pop();
		if (visited[dst]) continue;
		visited[dst] = true;
		minCost += cost;
		for (auto next : tree[dst]) {
			if (!visited[next.second])
				pq.push({ -next.first, next.second });
		}
	}
	if (minCost <= blueCount && blueCount <= maxCost) 
		cout << "1\n";
	else 
		cout << "0\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();
	return 0;
}