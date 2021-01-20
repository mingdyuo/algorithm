#include <iostream>
#include <algorithm>
using namespace std;
int dotCount, roundCount;
int parent[1000001];
void input() {
	cin >> dotCount >> roundCount;
	for (int i = 0; i < dotCount; i++) parent[i] = i;
	
}

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x > y) swap(x, y);
	parent[y] = x;
}

void solution() {
	int left, right;
	for (int i = 1; i <= roundCount; i++) {
		cin >> left >> right;
		if (find(left) == find(right)) {
			
			cout << i ;
			return;
		}
		merge(left, right);
	}
	cout << 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();
	solution();
	return 0;
 }