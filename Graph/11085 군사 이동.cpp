// 소스 코드 출처 : https://beenpow.github.io/sweab/boj/%EB%B0%B1%EC%A4%80/2020/02/20/BOJ-11085/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int vertexCount, edgeCount, bj, cb;
vector<pair<int, int>> road[1003];
int dist[1003];
void input() {
	cin >> vertexCount >> edgeCount >> bj >> cb;
	int start, end, width;
	for (int i = 0; i < edgeCount; i++) {
		cin >> start >> end >> width;
		road[start].push_back({ width, end });
		road[end].push_back({ width, start });
	}
	for (int i = 0; i < vertexCount; i++) dist[i] = -1;
}

void solution() {
	priority_queue<pair<int, int>> pq;
	int answer = 0;
	dist[bj] = 1e9;
	pq.push({ 1e9, bj });
	while (!pq.empty()) {
		int cost = pq.top().first, curr = pq.top().second;
		pq.pop();
		if (curr == cb) 
			answer = max(answer, cost);
		
		if (dist[curr] > cost) 
			continue;
		for (auto next : road[curr]) {
			if (dist[next.second] < min(cost, next.first)){
				dist[next.second] = min(cost, next.first);
				pq.push({ min(cost, next.first), next.second });
			}
		}
	}

 	cout << dist[cb];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();
	solution();
	return 0;
}