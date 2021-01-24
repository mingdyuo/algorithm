#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
int M, N; // N이 가로 M 이 세로
int room[52][52];
int wall[52][52];

int dx[] = {0, -1, 0, 1}; // 서북동남
int dy[] = {-1, 0, 1, 0};
map<int, int> roomSize;
void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> wall[i][j];
		}
	}
}

inline bool isValid(int x, int y) {
	if (x >= 0 && y >= 0 && x < M && y < N) return true;
	return false;
}

int bfs(int sx, int sy, int label) {
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	room[sx][sy] = label;
	int count = 1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if ((1 << i) & (wall[x][y])) continue;
			int nx = x + dx[i], ny = y + dy[i];
			if (!isValid(nx, ny) || room[nx][ny] != 0) continue;
			room[nx][ny] = label;
			q.push({ nx, ny });
			count++;
		}
	}
	return count;
}

int combine(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	wall[sx][sy] = 1;
	int label = room[sx][sy];
	int maxCombine = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (!isValid(nx, ny) || wall[nx][ny]) continue;
			if (room[nx][ny] == label) {
				wall[nx][ny] = true;
				q.push({ nx, ny });
			}
			else {
				maxCombine = max(maxCombine, roomSize[label] + roomSize[room[nx][ny]]);
			}
		}
	}
	return maxCombine;
}

void solution() {
	vector<int> sizes;
	int label = 1;
	int maxSize = 0, maxCombine = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (room[i][j] == 0) {
				int size = bfs(i, j, label);
				roomSize[label++] = size;
				maxSize = max(maxSize, size);
			}
		}
	}
	memset(wall, 0, sizeof(wall));

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!wall[i][j])
				maxCombine = max(maxCombine, combine(i, j));
		}
	}

	cout << label - 1 << "\n" << maxSize << "\n" << maxCombine;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();
	solution();
	return 0;
}
