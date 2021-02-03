#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
int cityCount, cableCount, hubCount;

bool visited[1003];
vector<pair<int, int>> city[1003];
vector<int> hubs;
void input() {
	cin >> cityCount >> cableCount >> hubCount;
	int hubInput;
	for (int i = 0; i < hubCount; i++) {
		cin >> hubInput;
		hubs.push_back(hubInput);
	}
	int start, end, cost;
	for (int i = 0; i < cableCount; i++) {
		cin >> start >> end >> cost;
		city[start].push_back({ cost, end });
		city[end].push_back({ cost, start });
	}
}

void solution() {
	priority_queue<pair<int, int>> pq;
	for (auto hub : hubs) {
		visited[hub] = true;
		for (auto link : city[hub]) {
			pq.push({-link.first, link.second});
		}
	}
	int answer = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first, link = pq.top().second;
		pq.pop();
		if (visited[link]) continue;
		visited[link] = true;
		answer += cost;
		for (auto next : city[link]) {
			if (!visited[next.second])
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