#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;

int paper[101][101];
int visited[101][101];

int cheese;

bool isValid(int r, int c) {
	if (r >= 0 && c >= 0 && r < N && c < M) return true;
	return false;
}

int dc[] = { 0, 0, 1, -1 };
int dr[] = { 1, -1, 0, 0 };

void bfs() {
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = 1;
	while (!q.empty()) {
		int r = q.front().first, c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i], nc = c + dc[i];
			if (!isValid(nr, nc)) continue;
			if (paper[nr][nc] == 0 && visited[nr][nc] == 1) continue;
			if (paper[nr][nc] == 0 && visited[nr][nc] == 0) {
				visited[nr][nc] = 1;
				q.push({ nr,nc });
				continue;
			}
			if (paper[nr][nc] == 1) visited[nr][nc]--;
			if (visited[nr][nc] <= -2) {
				visited[nr][nc] = 1;
				paper[nr][nc] = 0;
				cheese--;
			}
		}
	}
}

void solution() {
	int answer = 0;

	for (;cheese; answer++) {
		bfs();
	}
	cout << answer;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> paper[i][j];
			if (paper[i][j] == 1) cheese++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();
	solution();
	return 0;
}