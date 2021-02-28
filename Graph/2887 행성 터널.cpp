#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>

using namespace std;

int N;

int parent[100001];

vector<pii> X, Y, Z;
vector<pair<int, pii>> info;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	
	if (x < y) parent[y] = x;
	else parent[x] = y;
}


void input() {
	cin >> N;
	int x, y, z;
	for (int i = 0; i < N; i++) {
		parent[i] = i;
		cin >> x >> y >> z;
		X.push_back({ x, i });
		Y.push_back({ y, i });
		Z.push_back({ z, i });
	}
}

void solution() {
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	for (int i = 0; i < N - 1; i++) {
		info.push_back({ X[i + 1].first - X[i].first, {X[i].second, X[i + 1].second} });
		info.push_back({ Y[i + 1].first - Y[i].first, {Y[i].second, Y[i + 1].second} });
		info.push_back({ Z[i + 1].first - Z[i].first, {Z[i].second, Z[i + 1].second} });
	}
	sort(info.begin(), info.end());

	int count = 0;
	int total = 0;

	for (int i = 0; i < info.size(); i++) {
		int a = info[i].second.first, b = info[i].second.second;
		int val = info[i].first;

		if (find(a) != find(b)) {
			merge(a, b);
			total += val;
		}
	}

	cout << total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();
	solution();
	return 0;
}