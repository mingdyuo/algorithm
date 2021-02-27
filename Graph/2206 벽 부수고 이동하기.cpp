#include <iostream>
#include <queue>

using namespace std;

int matrix[1001][1001];
int visited[1001][1001];

int N, M;

int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

void input() {
	cin >> N >> M;
	char a;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a;
			matrix[i][j] = a - '0';
		}
	}
}

struct info {
	int row, col, cost;
	bool isBroke;
	info(int r, int c, int cost, bool b) :row(r), col(c), isBroke(b), cost(cost) {}
};

bool isValid(int r, int c, bool isBroke) {
	if (r < 0 || c < 0 || r >= N || c >= M)
		return false;
	if (isBroke && matrix[r][c] == 1) return false;
	if (visited[r][c] == 3 || (visited[r][c] == 2 && isBroke) || (visited[r][c] == 1 && !isBroke))
		return false;
	return true;
}

void solution() {
	queue<info> q;
	visited[0][0] = 3;
	q.push(info(0, 0, 1, false));
	while (!q.empty()) {
		info curr = q.front(); q.pop();
		int r = curr.row, c = curr.col, b = curr.isBroke;
		if (r == N - 1 && c == M - 1) {
			cout << curr.cost;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i], nc = c + dc[i];
			bool nb = b;
			if (!isValid(nr, nc, b)) continue;
			if (!b && matrix[nr][nc] == 1) nb = true;

			if (nb) visited[nr][nc] += 2;
			else if (!nb) visited[nr][nc] += 1;
			q.push(info(nr, nc, curr.cost + 1, nb));
		}
	}
	cout << -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();
	solution();
	return 0;
}