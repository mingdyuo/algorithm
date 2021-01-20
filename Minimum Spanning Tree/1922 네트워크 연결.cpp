#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int computerCount, lineCount;
vector<pair<int, int>> computer[1002];
bool visited[1002];
void input() {
	cin >> computerCount >> lineCount;
	int com1, com2, cost;
	for (int i = 0; i < lineCount; i++) {
		cin >> com1 >> com2 >> cost;
		if (com1 == com2)continue;
		computer[com1].push_back({ cost, com2 });
		computer[com2].push_back({ cost, com1 });
	}
}

void solution() {
	priority_queue<pair<int, int>> pq;
	visited[1] = true;
	for (auto next : computer[1]) {
		pq.push({ -next.first, next.second });
	}
	long long answer = 0;
	while (!pq.empty()) {
		int dst = pq.top().second, cost = -pq.top().first;
		pq.pop();
		if (visited[dst]) continue;
		answer += cost;
		visited[dst] = true;
		for (auto next : computer[dst]) {
			if(!visited[next.second])
				pq.push({ -next.first, next.second });
		}
	}
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();
	solution();
	return 0;
}