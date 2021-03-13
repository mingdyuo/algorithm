#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int N;

bool visited[10000];

void solution(int A, int B) {
	queue<pair<int ,string>> q;
	q.push({A, ""});
	memset(&visited, false, sizeof(visited));
	visited[A] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		string curCmd = q.front().second;
		q.pop();
		if (cur == B) { cout << curCmd << '\n'; return; }

		int next = (cur * 2) % 10000;
		if (!visited[next]) {
			visited[next] = true;
			q.push({ next, curCmd + 'D' });
		}

		next = (cur - 1 < 0) ? 9999 : cur - 1;
		if (!visited[next]) {
			visited[next] = true;
			q.push({ next, curCmd + 'S'});
		}

		next = (cur % 1000) * 10 + cur / 1000 ;
		if (!visited[next]) {
			visited[next] = true;
			q.push({ next, curCmd + 'L' });
		}
		
		next = (cur % 10) * 1000 + cur / 10;
		if (!visited[next]) {
			visited[next] = true;
			q.push({ next, curCmd + 'R' });
		}

	}
	
}
void input() {
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		solution(a, b);

	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();
	//solution();
	return 0;
}
