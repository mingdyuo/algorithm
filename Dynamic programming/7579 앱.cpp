#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int costSum;
int dp[10001];

vector<pair<int, int>> info;

void input() {
	cin >> N >> M;
	costSum = 0;
	int mem, cost;
	for (int i = 0; i < N; i++) {
		cin >> mem;
		info.push_back({ mem, 0 });
	}
	for (int i = 0; i < N; i++) {
		cin >> cost;
		costSum += cost;
		info[i].second = cost;
	}
}

void solution() {
	for (int i = 0; i < N; i++) {
		for (int j = costSum; j >= info[i].second; j--) {
			dp[j] = max(dp[j], dp[j - info[i].second] + info[i].first);
		}
	}
	for (int j = 0; j <= costSum; j++) {
		if (dp[j] >= M) {
			cout << j;
			break;
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